#ifndef COMPOSERVIEWMODEL_H
#define COMPOSERVIEWMODEL_H

#include "poemrepository.h"
#include <QObject>
#include <QUrl>

class ComposerViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString poem READ getPoem WRITE writePoem NOTIFY poemChanged)
    Q_PROPERTY(QString savedState READ getSavedState NOTIFY savedStateChanged)
    Q_PROPERTY(QString poemFileName READ getPoemFileName NOTIFY poemFileNameChanged)

public:
    explicit ComposerViewModel(PoemRepository *repository, QObject *parent = nullptr);
    Q_INVOKABLE const QString getFileDialogFile() const ;
    Q_INVOKABLE const QString getFileDialogFolder() const ;
    Q_INVOKABLE const QString getPoemFileName() const ;
    Q_INVOKABLE void newFile();
    Q_INVOKABLE void open(QUrl poemFilePath);
    Q_INVOKABLE void saveAs(QUrl poemFilePath);
    const QString getSavedState() const;

signals:
    void savedStateChanged();
    void poemFileNameChanged();
    void poemChanged();
private:
    QString savedState;
    const QString getPoem() const ;
    void writePoem(QString poem);
    void onSavedStateChanged(PoemRepository::PoemSavedState savedState);
    PoemRepository *repository;

};

#endif // COMPOSERVIEWMODEL_H
