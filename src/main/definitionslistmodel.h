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

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    bool isLoading;
    bool removeMeShouldLoad;
    QSqlDatabase *db;
    QSqlQuery *query;
    int size;
};

#endif // DEFINITIONSLISTMODEL_H
