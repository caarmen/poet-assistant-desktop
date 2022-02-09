#include "ttsviewmodel.h"

#include <QtConcurrent>
TtsViewModel::TtsViewModel(QObject *parent)
    : QObject{parent}
{
    tts = new QTextToSpeech(this);
    QObject::connect(tts, &QTextToSpeech::stateChanged, this, [=]{ emit playButtonIconChanged();});
}

bool TtsViewModel::isTtsSupported() const {
    return !QTextToSpeech::availableEngines().empty() &&
            !tts->availableVoices().empty() &&
            !tts->availableLocales().empty();
}

QString TtsViewModel::getVoiceName() const {
    return tts->voice().name();
}

QStringList TtsViewModel::getAvailableVoiceNames() const {
    QStringList voiceNames = QtConcurrent::blockingMapped(tts->availableVoices(), [=] (QVoice voice) {
        return voice.name();
    });
    voiceNames.sort();
    return voiceNames;
}
void TtsViewModel::useVoice(QString name) {
    QVector<QVoice> matchingVoices = QtConcurrent::blockingFiltered(tts->availableVoices(), [=] (QVoice voice) {
        return voice.name() == name;
    });
    if(!matchingVoices.empty()) {
        tts->setVoice(matchingVoices.first());
    }
}
void TtsViewModel::setPitch(double pitch) {
    tts->setPitch(pitch);
}

void TtsViewModel::setRate(double rate) {
    tts->setRate(rate);
}

QString TtsViewModel::getPlayButtonIcon() {
    return tts->state() == QTextToSpeech::Speaking ? "qrc:/images/stop.svg" : "qrc:/images/play.svg";
}

void TtsViewModel::play(QString text) {
    if (tts->state() == QTextToSpeech::Speaking) {
        tts->stop();
    } else {
        tts->say(text);
    }
}
