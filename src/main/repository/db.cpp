#include "db.h"
#include <QtConcurrent>

Db::Db()
{
    threadPool = new QThreadPool();
    threadPool->setMaxThreadCount(1);
}

QThreadPool* Db::getThreadPool() {
    return threadPool;
}

QFuture<void> Db::openDb() {
    return QtConcurrent::run(threadPool, [=]() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setConnectOptions("QSQLITE_OPEN_READONLY");
        QFile file(":/poet_assistant.db");
        QString appDataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        QDir().mkdir(appDataDir);
        QString dbCopyFileName(QString("%1/poet_assistant.db").arg(appDataDir));
        QFile dbCopyFile(dbCopyFileName);
        if (dbCopyFile.open(QIODevice::WriteOnly)) {
            if (file.open(QIODevice::ReadOnly)) {
                dbCopyFile.write(file.readAll());
            }
            dbCopyFile.close();
        }
        db.setDatabaseName(dbCopyFile.fileName());
        if (!db.open()) {
            qFatal("Couldn't open db");
        }
    });
}
