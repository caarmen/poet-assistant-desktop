#ifndef FAVORITELISTMODEL_H
#define FAVORITELISTMODEL_H

#include <QAbstractListModel>
#include "favoriterepository.h"

class FavoriteListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isEmptyTextVisible MEMBER isEmptyTextVisible NOTIFY isEmptyTextVisibleChanged)

public:
    enum MyRoles {
        FavoriteRole = Qt::UserRole + 1,
    };
    explicit FavoriteListModel(FavoriteRepository *repository, QObject *parent = nullptr);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:
    void isEmptyTextVisibleChanged(bool);
private:
    void onFavoritesChanged();
    const QList<QString> *favorites;
    FavoriteRepository *repository;
    bool isEmptyTextVisible;
};

#endif // FAVORITELISTMODEL_H
