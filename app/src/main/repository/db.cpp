/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "db.h"
#include <QtConcurrent>

Db::Db()
{
    threadPool = new QThreadPool();
    threadPool->setMaxThreadCount(1);
}

QThreadPool *Db::getThreadPool()
{
    return threadPool;
}

QFuture<void> Db::openDb()
{
    return QtConcurrent::run(threadPool, [ = ]() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setConnectOptions("QSQLITE_OPEN_READONLY");
        QString appDir = QCoreApplication::applicationDirPath();
        QString dbFolder = QString(DB_FOLDER);
        if (!dbFolder.isEmpty()) appDir = QFileInfo(appDir, dbFolder).absoluteFilePath();
        QFileInfo dbFileInfo = QFileInfo(appDir, "poet_assistant.db");
        db.setDatabaseName(dbFileInfo.absoluteFilePath());
        if (!db.open()) {
            qFatal("Couldn't open db");
        }
    });
}
