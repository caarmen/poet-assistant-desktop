#include "definitionslistmodel.h"
#include "definitiondisplaydata.h"

DefinitionsListModel::DefinitionsListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    removeMeShouldLoad = true;
}


QHash<int,QByteArray> DefinitionsListModel::roleNames() const {
    return { { DefinitionRole, "definition" },
    };
}

QVariant DefinitionsListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QString("header");
}

int DefinitionsListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 2;
}

bool DefinitionsListModel::hasChildren(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return false;
}

bool DefinitionsListModel::canFetchMore(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return removeMeShouldLoad;
}

void DefinitionsListModel::fetchMore(const QModelIndex &parent)
{
    // FIXME: Implement me!
    beginInsertRows(parent, 0, 2);
    endInsertRows();
    removeMeShouldLoad = false;
}

QVariant DefinitionsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if (role == DefinitionRole) {
        return QVariant::fromValue(new DefinitionDisplayData(
                                       "noun",
                                       QString("some blah blah %1").arg(QString::number(index.row())),
                                       (QObject*) this
                                       ));
    } else {
        return QVariant();
    }
}
