#ifndef TTSVIEWMODEL_H
#define TTSVIEWMODEL_H

#include <QObject>
#include <QtTextToSpeech/qtexttospeech.h>

class TtsViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double pitch READ getPitch() WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(double rate READ getRate() WRITE setRate NOTIFY rateChanged)
    Q_PROPERTY(QString playButtonIcon READ getPlayButtonIcon NOTIFY playButtonIconChanged)

public:
    explicit TtsViewModel(QObject *parent = nullptr);
    Q_INVOKABLE bool isTtsSupported() const;
    Q_INVOKABLE QString getVoiceName() const;
    Q_INVOKABLE QStringList getAvailableVoiceNames() const;
    Q_INVOKABLE void useVoice(QString name);
    Q_INVOKABLE void play(QString text);

signals:
    void playButtonIconChanged();
    void pitchChanged();
    void rateChanged();
private:
    double getPitch();
    void setPitch(double pitch);
    double getRate();
    void setRate(double rate);
    QString getPlayButtonIcon();
    QTextToSpeech *tts;
};

#endif // TTSVIEWMODEL_H
