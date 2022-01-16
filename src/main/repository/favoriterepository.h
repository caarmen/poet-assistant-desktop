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
