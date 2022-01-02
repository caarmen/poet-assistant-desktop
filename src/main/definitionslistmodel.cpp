#include "definitionslistmodel.h"
#include "definitiondisplaydata.h"

DefinitionsListModel::DefinitionsListModel(QSqlDatabase *db, QObject *parent)
    : QAbstractListModel(parent), db(db), isLoading(false), query(nullptr), size(0)
{
    removeMeShouldLoad = true;
}

void DefinitionsListModel::readDefinitions(QString searchText) {
    removeMeShouldLoad = true;
    beginResetModel();
    if (query != nullptr) delete query;
    query = new QSqlQuery();
    query->prepare("SELECT part_of_speech, definition FROM dictionary WHERE word = :word");
    query->bindValue(":word", searchText);
    if(!query->exec()) {
        qDebug() << "Error executing query";
    }
    qDebug() << "query " << query->isSelect();
    query->last();
    size = query->at() + 1;
    qDebug() << "query size " << size;
    endResetModel();
    //emit dataChanged(index(0,0), index(size, 0));
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

    return size;
}

bool DefinitionsListModel::canFetchMore(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return !parent.isValid() && !isLoading && removeMeShouldLoad;
}

void DefinitionsListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid()) return;

    if (query == nullptr) return;

    // FIXME: Implement me!
    if (!isLoading) {
        isLoading = true;
        beginInsertRows(parent, 0, size);
        endInsertRows();
        removeMeShouldLoad = false;
        isLoading = false;
    }
}

QVariant DefinitionsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == DefinitionRole) {
        query->seek(index.row(), false);
        QSqlRecord record = query->record();
        int columnDefinition = record.indexOf("definition");
        int columnPartOfSpeech = record.indexOf("part_of_speech");
        QString definition = query->value(columnDefinition).toString();
        QString partOfSpeech = query->value(columnPartOfSpeech).toString();
        return QVariant::fromValue(new DefinitionDisplayData(
                                       partOfSpeech,
                                       definition,
                                       (QObject*) this
                                       ));
    } else {
        return QVariant();
    }
}
