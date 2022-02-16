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
#include "favoritelistmodel.h"

FavoriteListModel::FavoriteListModel(FavoriteRepository *repository, QObject *parent)
    : QAbstractListModel(parent),
      repository(repository)
{
    favorites = repository->readAll();
    QObject::connect(repository, &FavoriteRepository::favoritesChanged, this,
                     &FavoriteListModel::onFavoritesChanged);
    isEmptyTextVisible = favorites->empty();
}

void FavoriteListModel::onFavoritesChanged()
{
    beginResetModel();
    favorites = repository->readAll();
    isEmptyTextVisible = favorites->empty();
    emit isEmptyTextVisibleChanged(isEmptyTextVisible);
    endResetModel();
}

QHash<int, QByteArray> FavoriteListModel::roleNames() const
{
    return { { FavoriteRole, "favorite" } };
}

int FavoriteListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return favorites == nullptr ? 0 : favorites->size();
}

QVariant FavoriteListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == FavoriteRole) {
        return QVariant::fromValue(favorites->at(index.row()));
    } else {
        return QVariant();
    }
}

