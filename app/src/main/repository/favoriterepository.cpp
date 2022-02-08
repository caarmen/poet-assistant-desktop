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
#include "favoriterepository.h"

FavoriteRepository::FavoriteRepository(QObject *parent)
    : QObject{parent}
{
    favorites = settings.value(favoritesSetting).value<QList<QString>>();
}

const QList<QString> *FavoriteRepository::readAll() const
{
    return &favorites;
}
bool FavoriteRepository::isFavorite(const QString &word) const
{
    bool result = favorites.contains(word);
    return result;
}
void FavoriteRepository::toggleFavorite(const QString &word)
{
    if (favorites.contains(word)) favorites.removeAll(word);
    else favorites.append(word);
    favorites.sort();
    settings.setValue(favoritesSetting, favorites);
    emit favoritesChanged();
}
void FavoriteRepository::clear()
{
    favorites.clear();
    settings.setValue(favoritesSetting, favorites);
    emit favoritesChanged();
}
