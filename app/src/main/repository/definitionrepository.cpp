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
#include "definitionrepository.h"
#include "db.h"
#include <QtConcurrent>

DefinitionRepository::DefinitionRepository(Db *db, QObject *parent)
    : QObject{parent}, db(db)
{

}

QFuture<QList<DefinitionEntity *>*> DefinitionRepository::readDefinitions(QString word)
{
    return QtConcurrent::run(db->getThreadPool(), [ = ]() {
        QSqlQuery query;
        query.prepare("SELECT part_of_speech, definition FROM dictionary WHERE word = :word");
        query.bindValue(":word", word);
        query.exec();
        QList<DefinitionEntity *> *result = new QList<DefinitionEntity *>();
        while (query.next()) {
            QString definition = query.value("definition").toString();
            QString partOfSpeech = query.value("part_of_speech").toString();
            result->append(new DefinitionEntity(partOfSpeech, definition));
        }
        return result;
    });
}
