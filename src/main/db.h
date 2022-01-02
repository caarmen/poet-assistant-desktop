#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QCoreApplication>

class Db
{
public:
    static QSqlDatabase openDb(QCoreApplication &app);
private :
    Db();
};

#endif // DB_H
