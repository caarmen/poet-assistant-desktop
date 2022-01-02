#include "definitionslistmodel.h"
#include "definitiondisplaydata.h"

DefinitionsListModel::DefinitionsListModel(QSqlDatabase *db, QObject *parent)
    : QAbstractListModel(parent), db(db), query(nullptr), size(0)
{
}

void DefinitionsListModel::readDefinitions(QString searchText) {
    beginResetModel();
    if (query != nullptr) delete query;
    query = new QSqlQuery();
    query->prepare("SELECT part_of_speech, definition FROM dictionary WHERE word = :word");
    query->bindValue(":word", searchText);
    query->exec();
    query->last();
    size = query->at() + 1;
    endResetModel();
}

QHash<int,QByteArray> DefinitionsListModel::roleNames() const {
    return { { DefinitionRole, "definition" } };
}

int DefinitionsListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return size;
}

QVariant DefinitionsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == DefinitionRole) {
        query->seek(index.row(), false);
        QString definition = query->value("definition").toString();
        QString partOfSpeech = query->value("part_of_speech").toString();
        return QVariant::fromValue(new DefinitionDisplayData(
                                       partOfSpeech,
                                       definition,
                                       (QObject*) this
                                       ));
    } else {
        return QVariant();
    }
}
