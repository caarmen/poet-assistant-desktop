#include "definitionlistmodel.h"
#include <QFutureWatcher>
#include <QtConcurrent>

DefinitionListModel::DefinitionListModel(DefinitionViewModel *viewModel, QObject *parent)
    : QAbstractListModel(parent), viewModel(viewModel), definitions(nullptr)
{
}

void DefinitionListModel::readDefinitions(QString searchText) {
    beginResetModel();
    if (definitions != nullptr) {
        qDeleteAll(*definitions);
        delete definitions;
    }
    QFuture<QList<DefinitionDisplayData*>*> future = viewModel->readDefinitions(searchText);
    auto *watcher = new QFutureWatcher<QList<DefinitionDisplayData*>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<DefinitionDisplayData*>*>::finished, this, [=](){
        definitions = future.result();
        endResetModel();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

QHash<int,QByteArray> DefinitionListModel::roleNames() const {
    return { { DefinitionRole, "definition" } };
}

int DefinitionListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return definitions == nullptr ? 0 : definitions->size();
}

QVariant DefinitionListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == DefinitionRole) {
        return QVariant::fromValue(definitions->at(index.row()));
    } else {
        return QVariant();
    }
}

