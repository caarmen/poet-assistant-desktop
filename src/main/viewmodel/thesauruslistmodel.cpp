#include "thesauruslistmodel.h"

ThesaurusListModel::ThesaurusListModel(ThesaurusViewModel *viewModel, QObject *parent)
    : QAbstractListModel{parent}, viewModel(viewModel), thesaurusEntries(nullptr)
{

}

void ThesaurusListModel::readThesaurus(QString searchText) {
    beginResetModel();
    if (thesaurusEntries != nullptr) {
        qDeleteAll(*thesaurusEntries);
        delete thesaurusEntries;
    }
    QFuture<QList<ThesaurusDisplayData*>*> future = viewModel->readThesaurus(searchText);
    auto *watcher = new QFutureWatcher<QList<ThesaurusDisplayData*>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<ThesaurusDisplayData*>*>::finished, this, [=](){
        thesaurusEntries = future.result();
        endResetModel();
        watcher->deleteLater();
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
