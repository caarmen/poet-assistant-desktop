#ifndef THESAURUSREPOSITORY_H
#define THESAURUSREPOSITORY_H

#include "db.h"
#include "thesaurusentity.h"
#include <QObject>

class ThesaurusRepository : public QObject
{
    Q_OBJECT
public:
    explicit ThesaurusRepository(Db *db, QObject *parent = nullptr);
    QFuture<QList<ThesaurusEntity*>*> readThesaurus(QString word);

signals:

private:
    Db *db;
};

#endif // THESAURUSREPOSITORY_H
