#include "db.h"

Db::Db()
{
}

QSqlDatabase Db::openDb(QCoreApplication &app) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QTemporaryFile tmpFile(&app);
    tmpFile.setFileTemplate("XXXXXX.db");
    if (tmpFile.open()) {
        QString tmp_filename=tmpFile.fileName();
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
    return db;
}
