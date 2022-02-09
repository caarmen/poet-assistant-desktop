#ifndef TTSVIEWMODEL_H
#define TTSVIEWMODEL_H

#include <QObject>
#include <QtTextToSpeech/qtexttospeech.h>

class TtsViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString playButtonIcon READ getPlayButtonIcon NOTIFY playButtonIconChanged)

public:
    explicit TtsViewModel(QObject *parent = nullptr);
    Q_INVOKABLE bool isTtsSupported() const;
    Q_INVOKABLE QString getVoiceName() const;
    Q_INVOKABLE QStringList getAvailableVoiceNames() const;
    Q_INVOKABLE void useVoice(QString name);
    Q_INVOKABLE void setPitch(double pitch);
    Q_INVOKABLE void setRate(double rate);
    Q_INVOKABLE void play(QString text);

signals:
    void playButtonIconChanged();
private:

    QString getPlayButtonIcon();
    QTextToSpeech *tts;
};

#endif // TTSVIEWMODEL_H
