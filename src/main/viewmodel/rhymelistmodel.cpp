#include "rhymelistmodel.h"
#include "rhymeentitymapper.h"

RhymeListModel::RhymeListModel(RhymeRepository *repository, QObject *parent)
    : QAbstractListModel{parent}, repository(repository), rhymeEntries(nullptr)
{

}

void RhymeListModel::readRhymes(QString searchText) {
    beginResetModel();
    if (rhymeEntries != nullptr) {
        qDeleteAll(*rhymeEntries);
        delete rhymeEntries;
    }
    rhymeEntries = new QList<RhymeDisplayData*>();
    QFuture<QList<RhymeEntity*>*> futureWordVariants = repository->readWordVariants(searchText);
    QFutureWatcher<QList<RhymeEntity*>*> *watcherWordVariants = new QFutureWatcher<QList<RhymeEntity*>*>();
    QObject::connect(watcherWordVariants, &QFutureWatcher<QList<RhymeEntity*>*>::finished, this, [=](){
        QList<RhymeEntity*>* wordVariantEntities = futureWordVariants.result();
        for(int i = 0; i < wordVariantEntities->size(); i++) {
            auto& wordVariantEntity  = wordVariantEntities->at(i);
            QFuture<QStringList*> futureRhymes = repository->readByStressSyllablesExcludingWord(wordVariantEntity->stressSyllables, searchText);
            QFutureWatcher<QStringList*> *watcherRhymes = new QFutureWatcher<QStringList*>();
            QObject::connect(watcherRhymes, &QFutureWatcher<QList<RhymeEntity*>*>::finished, this, [=](){
                QStringList *rhymes = futureRhymes.result();
                QList<RhymeDisplayData*>* rhymeDisplayDatas =  RhymeEntityMapper::map(wordVariantEntity, rhymes);
                rhymeEntries->append(*rhymeDisplayDatas);
                delete rhymeDisplayDatas;
                delete rhymes;
                watcherRhymes->deleteLater();
                if (i == wordVariantEntities->size() - 1) {
                    endResetModel();
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

QHash<int,QByteArray> RhymeListModel::roleNames() const {
    return { { RhymeRole, "rhyme" } };
}

int RhymeListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return rhymeEntries == nullptr ? 0 : rhymeEntries->size();
}

QVariant RhymeListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == RhymeRole) {
        return QVariant::fromValue(rhymeEntries->at(index.row()));
    } else {
        return QVariant();
    }
}
