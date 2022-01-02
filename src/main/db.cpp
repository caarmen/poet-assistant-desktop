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

QFuture<void> Db::openDb(QCoreApplication &app) {
    return QtConcurrent::run(threadPool, [this, &app]() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setConnectOptions("QSQLITE_OPEN_READONLY");
        QTemporaryFile tmpFile(&app);
        tmpFile.setFileTemplate("XXXXXX.db");
        if (tmpFile.open()) {
            QFile file(":/poet_assistant.db");
            if (file.open(QIODevice::ReadOnly)) {
                tmpFile.write(file.readAll());
            }
            tmpFile.close();
        }
        db.setDatabaseName(tmpFile.fileName());
        if (!db.open()) {
            qFatal("Couldn't open db");
        }
    });
}
