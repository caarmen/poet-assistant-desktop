/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/
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

    QHash<int, QByteArray> roleNames() const override;
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
