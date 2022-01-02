#include "definitionslistmodel.h"
#include "definitiondisplaydata.h"
#include <QFutureWatcher>

DefinitionsListModel::DefinitionsListModel(DefinitionRepository *repository, QObject *parent)
    : QAbstractListModel(parent), repository(repository), definitions(nullptr)
{
}

void DefinitionsListModel::readDefinitions(QString searchText) {
    beginResetModel();
    if (definitions != nullptr) {
        qDeleteAll(*definitions);
        definitions->clear();
        delete definitions;
    }
    QFuture<QList<DefinitionDisplayData*>*> future = repository->readDefinitions(searchText);
    QFutureWatcher<QList<DefinitionDisplayData*>*> *watcher = new QFutureWatcher<QList<DefinitionDisplayData*>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<DefinitionDisplayData*>*>::finished, this, [=](){
        definitions = future.result();
        endResetModel();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

QHash<int,QByteArray> DefinitionsListModel::roleNames() const {
    return { { DefinitionRole, "definition" } };
}

int DefinitionsListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return definitions == nullptr ? 0 : definitions->size();
}

QVariant DefinitionsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == DefinitionRole) {
        return QVariant::fromValue(definitions->at(index.row()));
    } else {
        return QVariant();
    }
}
