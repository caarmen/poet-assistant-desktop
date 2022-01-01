#include "definitionslistmodel.h"
#include "definitiondisplaydata.h"

DefinitionsListModel::DefinitionsListModel(QObject *parent)
    : QAbstractListModel(parent), isLoading(false)
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

bool DefinitionsListModel::canFetchMore(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return !parent.isValid() && !isLoading && removeMeShouldLoad;
}

void DefinitionsListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid()) return;

    // FIXME: Implement me!
    if (!isLoading) {
        isLoading = true;
        beginInsertRows(parent, 0, 2);
        endInsertRows();
        removeMeShouldLoad = false;
        isLoading = false;
    }
}

QVariant DefinitionsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if (role == DefinitionRole) {
        return QVariant::fromValue(new DefinitionDisplayData(
                                       "noun",
                                       QString("some blah blah %1 %2").arg(QString::number(index.row()), QString::number(index.column())),
                                       (QObject*) this
                                       ));
    } else {
        return QVariant();
    }
}
