#ifndef RHYMEREPOSITORY_H
#define RHYMEREPOSITORY_H

#include "db.h"
#include "rhymeentity.h"
#include <QObject>
#include <QStringList>

class RhymeRepository : public QObject
{
    Q_OBJECT
public:
    explicit RhymeRepository(Db *db, QObject *parent = nullptr);
    QFuture<QList<RhymeEntity*>*> readStressSyllableRhymes(QString word);

signals:

private:
    RhymeEntity* create(QSqlQuery &query);
    Db *db;
};

#endif // RHYMEREPOSITORY_H
