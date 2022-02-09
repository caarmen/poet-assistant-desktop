#ifndef TTSVIEWMODEL_H
#define TTSVIEWMODEL_H

#include <QObject>
#include <QtTextToSpeech/qtexttospeech.h>

class TtsViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double pitch READ getPitch() WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(double rate READ getRate() WRITE setRate NOTIFY rateChanged)
    Q_PROPERTY(QString voiceName READ getVoiceName() NOTIFY voiceNameChanged)
    Q_PROPERTY(QStringList availableVoiceNames READ getAvailableVoiceNames() NOTIFY availableVoiceNamesChanged)
    Q_PROPERTY(QString playButtonIcon READ getPlayButtonIcon NOTIFY playButtonIconChanged)

public:
    explicit TtsViewModel(QObject *parent = nullptr);
    Q_INVOKABLE bool isTtsSupported() const;
    Q_INVOKABLE void useVoice(QString name);
    Q_INVOKABLE QString getLocaleName() const;
    Q_INVOKABLE QStringList getAvailableLocaleNames() const;
    Q_INVOKABLE void useLocale(QString name);
    Q_INVOKABLE void play(QString text);

signals:
    void playButtonIconChanged();
    void availableVoiceNamesChanged();
    void voiceNameChanged();
    void pitchChanged();
    void rateChanged();
private:
    QString getVoiceName() const;
    QStringList getAvailableVoiceNames() const;
    double getPitch();
    void setPitch(double pitch);
    double getRate();
    void setRate(double rate);
    QString getPlayButtonIcon();
    QTextToSpeech *tts;
};

#endif // TTSVIEWMODEL_H
