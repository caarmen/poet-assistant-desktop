#include "thesauruslistmodel.h"
#include "thesaurusentitymapper.h"

ThesaurusListModel::ThesaurusListModel(ThesaurusRepository *repository, QObject *parent)
    : QAbstractListModel{parent}, repository(repository), thesaurusEntries(nullptr)
{

}

void ThesaurusListModel::readThesaurus(QString searchText) {
    beginResetModel();
    if (thesaurusEntries != nullptr) {
        qDeleteAll(*thesaurusEntries);
        delete thesaurusEntries;
    }
    QFuture<QList<ThesaurusEntity*>*> future = repository->readThesaurus(searchText);
    QFutureWatcher<QList<ThesaurusEntity*>*> *watcher = new QFutureWatcher<QList<ThesaurusEntity*>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<ThesaurusEntity*>*>::finished, this, [=](){
        QList<ThesaurusEntity*>* entities = future.result();
        thesaurusEntries = ThesaurusEntityMapper::map(entities);
        endResetModel();
        watcher->deleteLater();
        qDeleteAll(*entities);
        delete entities;
    });
    watcher->setFuture(future);
}

QHash<int,QByteArray> ThesaurusListModel::roleNames() const {
    return { { ThesaurusRole, "thesaurus" } };
}

int ThesaurusListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return thesaurusEntries == nullptr ? 0 : thesaurusEntries->size();
}

QVariant ThesaurusListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == ThesaurusRole) {
        return QVariant::fromValue(thesaurusEntries->at(index.row()));
    } else {
        return QVariant();
    }
}
