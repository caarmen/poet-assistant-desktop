#include "ttsviewmodel.h"

#include <QtConcurrent>
TtsViewModel::TtsViewModel(QObject *parent)
    : QObject{parent}
{
    tts = new QTextToSpeech(this);
    QObject::connect(tts, &QTextToSpeech::stateChanged, this, [ = ] { emit playButtonIconChanged();});
    QObject::connect(tts, &QTextToSpeech::pitchChanged, this, [ = ] { emit pitchChanged();});
    QObject::connect(tts, &QTextToSpeech::rateChanged, this, [ = ] { emit rateChanged();});
    QObject::connect(tts, &QTextToSpeech::voiceChanged, this, [ = ] {
        emit voiceNameChanged();
        emit pitchChanged();
        emit rateChanged();
    }
                    );
    QObject::connect(tts, &QTextToSpeech::localeChanged, this, [ = ] { emit availableVoiceNamesChanged();});
    initLocales();
}

void TtsViewModel::initLocales()
{
    auto allLocales = tts->availableLocales();
    auto englishLocales = QtConcurrent::blockingFiltered(allLocales, [ = ](QLocale locale) {
        return locale.language() == QLocale::English;
    });
    auto englishLocaleNames = QtConcurrent::blockingMapped(englishLocales, [ = ](QLocale locale) {
        return locale.name();
    });
    auto nonEnglishLocales = QtConcurrent::blockingFiltered(allLocales, [ = ](QLocale locale) {
        return locale.language() != QLocale::English;
    });
    auto nonEnglishLocaleNames = QtConcurrent::blockingMapped(allLocales, [ = ](QLocale locale) {
        return locale.name();
    });
    englishLocaleNames.sort();
    nonEnglishLocaleNames.sort();
    localeNames.append(englishLocaleNames);
    localeNames.append(nonEnglishLocaleNames);
}

bool TtsViewModel::isTtsSupported() const
{
    return !QTextToSpeech::availableEngines().empty() &&
           !tts->availableVoices().empty() &&
           !tts->availableLocales().empty();
}

QString TtsViewModel::getVoiceName() const
{
    return tts->voice().name();
}

QStringList TtsViewModel::getAvailableVoiceNames() const
{
    QStringList voiceNames = QtConcurrent::blockingMapped(tts->availableVoices(), [ = ] (QVoice voice) {
        return voice.name();
    });
    QString selectedVoiceName = getVoiceName();
    voiceNames.sort();
    if (!voiceNames.contains(selectedVoiceName)) {
        voiceNames.prepend(selectedVoiceName);
    }
    return voiceNames;
}
void TtsViewModel::useVoice(QString name)
{
    QVector<QVoice> matchingVoices = QtConcurrent::blockingFiltered(tts->availableVoices(), [ = ] (
    QVoice voice) {
        return voice.name() == name;
    });
    if (!matchingVoices.empty()) {
        tts->setVoice(matchingVoices.first());
    }
}
QString TtsViewModel::getLocaleName() const
{
    return tts->locale().name();
}

QStringList TtsViewModel::getAvailableLocaleNames() const
{
    return localeNames;
}
void TtsViewModel::useLocale(QString name)
{
    QVector<QLocale> matchingLocales = QtConcurrent::blockingFiltered(tts->availableLocales(), [ = ] (
    QLocale locale) {
        return locale.name() == name;
    });
    if (!matchingLocales.empty()) {
        tts->setLocale(matchingLocales.first());
    }
}
double TtsViewModel::getPitch()
{
    return tts->pitch();
}

void TtsViewModel::setPitch(double pitch)
{
    tts->setPitch(pitch);
}

double TtsViewModel::getRate()
{
    return tts->rate();
}

void TtsViewModel::setRate(double rate)
{
    tts->setRate(rate);
}

QString TtsViewModel::getPlayButtonIcon()
{
    return tts->state() == QTextToSpeech::Speaking ? "qrc:/images/stop.svg" : "qrc:/images/play.svg";
}

void TtsViewModel::play(QString text, int startPosition)
{
    if (tts->state() == QTextToSpeech::Speaking) {
        tts->stop();
    }
    // The cursor was at the end of the text, read the whole text
    else if (startPosition >= text.length()) {
        tts->say(text);
    }
    // Read the selected text
    else {
        tts->say(text.mid(startPosition));
    }
}
