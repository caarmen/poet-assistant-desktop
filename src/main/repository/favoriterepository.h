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
#ifndef FAVORITEREPOSITORY_H
#define FAVORITEREPOSITORY_H

#include <QObject>
#include <QSettings>

class FavoriteRepository : public QObject
{
    Q_OBJECT
public:
    explicit FavoriteRepository(QObject *parent = nullptr);
    const QList<QString> *readAll() const;
    bool isFavorite(const QString &word) const;
    void toggleFavorite(const QString &word);

signals:
    void favoritesChanged();
private:
    const static inline QString favoritesSetting = "favorites";
    QSettings settings;
    QList<QString> favorites;

};

#endif // FAVORITEREPOSITORY_H
