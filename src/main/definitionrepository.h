#ifndef DEFINITIONREPOSITORY_H
#define DEFINITIONREPOSITORY_H

#include "definitiondisplaydata.h"

#include <QObject>
#include <QtSql>

class DefinitionRepository : public QObject
{
    Q_OBJECT
public:
    explicit DefinitionRepository(QThreadPool *threadPool, QSqlDatabase *db, QObject *parent = nullptr);
    QFuture<QList<DefinitionDisplayData*>*> readDefinitions(QString word);
signals:

private:
    QThreadPool *threadPool;
    QSqlDatabase *db;
};

#endif // DEFINITIONREPOSITORY_H
