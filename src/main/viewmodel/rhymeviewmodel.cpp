#include "rhymeviewmodel.h"
#include "rhymeentitymapper.h"

#include <QtConcurrent>

RhymeViewModel::RhymeViewModel(RhymeRepository *repository, QObject *parent)
    : QObject{parent}, repository(repository)
{

}

void RhymeViewModel::readRhymes(QString searchText){
    auto *result = new QList<RhymeDisplayData*>();
    QFuture<QList<RhymeEntity*>*> futureWordVariants = repository->readWordVariants(searchText);
    auto *watcherWordVariants = new QFutureWatcher<QList<RhymeEntity*>*>();
    QObject::connect(watcherWordVariants, &QFutureWatcher<QList<RhymeEntity*>*>::finished, this, [=](){
        QList<RhymeEntity*>* wordVariantEntities = futureWordVariants.result();
        for(int i = 0; i < wordVariantEntities->size(); i++) {
            auto& wordVariantEntity  = wordVariantEntities->at(i);
            QFuture<QStringList*> futureRhymes = repository->readByStressSyllablesExcludingWord(wordVariantEntity->stressSyllables, searchText);
            auto *watcherRhymes = new QFutureWatcher<QStringList*>();
            QObject::connect(watcherRhymes, &QFutureWatcher<QList<RhymeEntity*>*>::finished, this, [=](){
                QStringList *rhymes = futureRhymes.result();
                QList<RhymeDisplayData*>* rhymeDisplayDatas =  RhymeEntityMapper::map(wordVariantEntity, rhymes);
                result->append(*rhymeDisplayDatas);
                delete rhymeDisplayDatas;
                delete rhymes;
                watcherRhymes->deleteLater();
                if (i == wordVariantEntities->size() - 1) {
                    emit onRhymesFetched(result);
                    qDeleteAll(*wordVariantEntities);
                    delete wordVariantEntities;
                }
            });
            watcherRhymes->setFuture(futureRhymes);
        }
        watcherWordVariants->deleteLater();
    });
    watcherWordVariants->setFuture(futureWordVariants);
}
