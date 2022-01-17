#ifndef COMPOSERVIEWMODEL_H
#define COMPOSERVIEWMODEL_H

#include "poemrepository.h"
#include <QObject>

class ComposerViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString savedState READ getSavedState NOTIFY savedStateChanged)

public:
    explicit ComposerViewModel(PoemRepository *repository, QObject *parent = nullptr);
    Q_INVOKABLE const QString readPoem() const ;
    Q_INVOKABLE void writePoem(QString poem);
    const QString getSavedState() const;

signals:
    void savedStateChanged();
private:
    QString savedState;
    void onSavedStateChanged(PoemRepository::PoemSavedState savedState);
    PoemRepository *repository;

};

#endif // COMPOSERVIEWMODEL_H
