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
    const QString getPoem() const;
    const QString getPoemFilePath() const;
    const QString getDefaultPoemFilePath() const;
    const QString generateFilenameFromPoemText() const;
    void newFile();
    void open(QString poemFilePath);
    void saveAs(QString poemFilePath);
    void writePoem(QString poem);
    PoemSavedState state;

signals:
    void poemChanged();
    void stateChanged();
private:
    const static inline QString poemFilePathSetting = "poemFilePath";
    const static inline int saveDelayMs = 2000;
    void readPoemImpl();
    void writePoemImpl();
    QString poem;
    QString poemFilePath;
    QSettings settings;
    QTimer timer;
    QString defaultPoemFilePath;
};

#endif // POEMREPOSITORY_H
