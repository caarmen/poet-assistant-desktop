#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QCoreApplication>

class Db
{
public:
    Db();
    QFuture<void> openDb(QCoreApplication &app);
    QThreadPool * getThreadPool();
private :
    QThreadPool *threadPool;
};

#endif // DB_H
