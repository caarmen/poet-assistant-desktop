#ifndef RHYMEVIEWMODEL_H
#define RHYMEVIEWMODEL_H

#include "rhymerepository.h"
#include "rhymedisplaydata.h"
#include <QObject>
#include <QFuture>

class RhymeViewModel : public QObject
{
    Q_OBJECT
public:
    explicit RhymeViewModel(RhymeRepository *repository, QObject *parent = nullptr);
    QFuture<QList<RhymeDisplayData*>*> readRhymes(QString searchText);

private:
    RhymeRepository *repository;
};

#endif // RHYMEVIEWMODEL_H
