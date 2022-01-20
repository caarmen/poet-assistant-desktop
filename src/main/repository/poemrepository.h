#ifndef POEMREPOSITORY_H
#define POEMREPOSITORY_H

#include <QObject>
#include <QSettings>
#include <QTimer>

class PoemRepository : public QObject
{
    Q_OBJECT
public:
    enum PoemSavedState { UNSAVED, SAVING, SAVED };
    explicit PoemRepository(QObject *parent = nullptr);
    const QString readPoem() const;
    void writePoem(QString poem);
    PoemSavedState state;

signals:
    void stateChanged();
private:
    const static inline QString poemSetting = "poem";
    const static inline int saveDelayMs = 2000;
    void writePoemImpl();
    QString poem;
    QSettings settings;
    QTimer timer;
};

#endif // POEMREPOSITORY_H
