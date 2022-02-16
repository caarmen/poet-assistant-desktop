#ifndef TTSVIEWMODEL_H
#define TTSVIEWMODEL_H

#include <QObject>
#include <QtGlobal>
#include <QtTextToSpeech/qtexttospeech.h>

class TtsViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double pitch READ getPitch() WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(double rate READ getRate() WRITE setRate NOTIFY rateChanged)
    Q_PROPERTY(QString voiceName READ getVoiceName() NOTIFY voiceNameChanged)
    Q_PROPERTY(QStringList availableVoiceNames READ getAvailableVoiceNames() NOTIFY
               availableVoiceNamesChanged)
    Q_PROPERTY(QString playButtonIcon READ getPlayButtonIcon NOTIFY playButtonIconChanged)
    Q_PROPERTY(double minPitch MEMBER minPitch CONSTANT)
    Q_PROPERTY(double maxPitch MEMBER maxPitch CONSTANT)
    Q_PROPERTY(double minRate MEMBER minRate CONSTANT)
    Q_PROPERTY(double maxRate MEMBER maxRate CONSTANT)

public:
    explicit TtsViewModel(QObject *parent = nullptr);
    Q_INVOKABLE bool isTtsSupported() const;
    Q_INVOKABLE void useVoice(QString name);
    Q_INVOKABLE QString getLocaleName() const;
    Q_INVOKABLE QStringList getAvailableLocaleNames() const;
    Q_INVOKABLE void useLocale(QString name);
    Q_INVOKABLE void play(QString text, int startPosition = 0);

signals:
    void playButtonIconChanged();
    void availableVoiceNamesChanged();
    void voiceNameChanged();
    void pitchChanged();
    void rateChanged();
private:
    void initLocales();
    QString getVoiceName() const;
    QStringList getAvailableVoiceNames() const;
    double getPitch();
    void setPitch(double pitch);
    double getRate();
    void setRate(double rate);
    QString getPlayButtonIcon();
    QTextToSpeech *tts;
    QList<QString> localeNames;

#ifdef Q_OS_MACOS
    const static inline double minPitch = -1;
    const static inline double maxPitch = 10;
    const static inline double minRate = -0.5;
    const static inline double maxRate = 1;
#else
    const static inline double minPitch = -1;
    const static inline double maxPitch = 1;
    const static inline double minRate = -0.99;
    const static inline double maxRate = 1;
#endif
};

#endif // TTSVIEWMODEL_H
