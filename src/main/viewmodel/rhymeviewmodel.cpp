#include "rhymeviewmodel.h"
#include "rhymeentitymapper.h"

#include <QtConcurrent>

RhymeViewModel::RhymeViewModel(RhymeRepository *repository, QObject *parent)
    : QObject{parent}, repository(repository)
{

}

QFuture<QList<RhymeDisplayData*>*> RhymeViewModel::readRhymes(QString searchText){
    return repository->readStressSyllableRhymes(searchText)
            .then([](QList<RhymeEntity*>* rhymeEntities){
        QList<RhymeDisplayData*>* result = RhymeEntityMapper::map(rhymeEntities);
        qDeleteAll(*rhymeEntities);
        delete rhymeEntities;
        return result;
    });
}
