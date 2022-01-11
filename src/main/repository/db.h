#ifndef DB_H
#define DB_H

#include <QtSql>

class Db
{
public:
    Db();
    QFuture<void> openDb();
    QThreadPool * getThreadPool();
private :
    QThreadPool *threadPool;
};

#endif // DB_H
