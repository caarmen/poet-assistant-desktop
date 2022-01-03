#ifndef DEFINITIONREPOSITORY_H
#define DEFINITIONREPOSITORY_H

#include "definitiondisplaydata.h"
#include "db.h"

#include <QObject>
#include <QtSql>

class DefinitionRepository : public QObject
{
    Q_OBJECT
public:
    explicit DefinitionRepository(Db *db, QObject *parent = nullptr);
    QFuture<QList<DefinitionDisplayData*>*> readDefinitions(QString word);
signals:

private:
    Db *db;
};

#endif // DEFINITIONREPOSITORY_H
