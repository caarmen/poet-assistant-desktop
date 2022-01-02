#ifndef DEFINITIONSLISTMODEL_H
#define DEFINITIONSLISTMODEL_H

#include <QAbstractListModel>
#include <QtSql>

class DefinitionsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum MyRoles {
        DefinitionRole = Qt::UserRole + 1,
    };
    explicit DefinitionsListModel(QSqlDatabase *db, QObject *parent = nullptr);

    void readDefinitions(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QSqlDatabase *db;
    QSqlQuery *query;
    int size;
};

#endif // DEFINITIONSLISTMODEL_H
