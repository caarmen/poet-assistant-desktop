#include "definitionlistmodel.h"
#include "definitiondisplaydata.h"
#include <QFutureWatcher>
#include <QtConcurrent>

DefinitionListModel::DefinitionListModel(DefinitionRepository *repository, QObject *parent)
    : QAbstractListModel(parent), repository(repository), definitions(nullptr)
{
}

void DefinitionListModel::readDefinitions(QString searchText) {
    beginResetModel();
    if (definitions != nullptr) {
        qDeleteAll(*definitions);
        delete definitions;
    }
    QFuture<QList<DefinitionEntity*>*> future = repository->readDefinitions(searchText);
    QFutureWatcher<QList<DefinitionEntity*>*> *watcher = new QFutureWatcher<QList<DefinitionEntity*>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<DefinitionEntity*>*>::finished, this, [=](){
        QList<DefinitionEntity*>* entities = future.result();
        definitions = new QList<DefinitionDisplayData*>(QtConcurrent::blockingMapped(*entities, [=](DefinitionEntity* entity){
            return new DefinitionDisplayData(entity->partOfSpeech, entity->definition);
        }));
        endResetModel();
        watcher->deleteLater();
        qDeleteAll(*entities);
        delete entities;
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

