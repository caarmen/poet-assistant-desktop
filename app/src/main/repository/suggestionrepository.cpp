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
#include "suggestionrepository.h"
#include "db.h"
#include <QtConcurrent>

SuggestionRepository::SuggestionRepository(Db *db, QObject *parent)
    : QObject{parent}, db(db)
{

}

QFuture<QList<SuggestionEntity*>*> SuggestionRepository::readSuggestions(QString word) {
    return QtConcurrent::run(db->getThreadPool(), [=]() {
        QList<SuggestionEntity*> *result = new QList<SuggestionEntity*>();
        if (word.isEmpty()) {
            return result;
        }
        QSqlQuery query;
        query.prepare(R"(
            SELECT DISTINCT word
            FROM word_variants
            WHERE word LIKE :word
                AND has_definition = 1
            ORDER BY word
            LIMIT 15
)");
        query.bindValue(":word", QString("%1%").arg(word));
        query.exec();
        while(query.next()) {
            QString suggestion = query.value("word").toString();
            result->append(new SuggestionEntity(suggestion, SuggestionEntity::DICTIONARY));
        }
        return result;
    });
}
