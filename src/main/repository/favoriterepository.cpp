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
