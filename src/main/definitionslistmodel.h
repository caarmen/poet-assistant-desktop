#ifndef DEFINITIONSLISTMODEL_H
#define DEFINITIONSLISTMODEL_H

#include <QAbstractListModel>

class DefinitionsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum MyRoles {
        DefinitionRole = Qt::UserRole + 1,
    };
    explicit DefinitionsListModel(QObject *parent = nullptr);

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
};

#endif // DEFINITIONSLISTMODEL_H
