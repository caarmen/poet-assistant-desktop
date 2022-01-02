#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QCoreApplication>

class Db
{
public:
    static QFuture<QSqlDatabase> openDb(QThreadPool &threadPool, QCoreApplication &app);
private :
    Db();
};

#endif // DB_H
