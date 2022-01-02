#ifndef DEFINITIONREPOSITORY_H
#define DEFINITIONREPOSITORY_H

#include "definitiondisplaydata.h"

#include <QObject>
#include <QtSql>

class DefinitionRepository : public QObject
{
    Q_OBJECT
public:
    explicit DefinitionRepository(QSqlDatabase *db, QObject *parent = nullptr);
    QList<DefinitionDisplayData*>* readDefinitions(QString word);
signals:

private:
    QSqlDatabase *db;
};

#endif // DEFINITIONREPOSITORY_H
