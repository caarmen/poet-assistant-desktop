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
#include "thesaurusrepository.h"
#include <QtConcurrent>

ThesaurusRepository::ThesaurusRepository(Db *db, QObject *parent)
    : QObject{parent}, db(db)
{

}

QFuture<QList<ThesaurusEntity*>*> ThesaurusRepository::readThesaurus(QString word)
{
    return QtConcurrent::run(db->getThreadPool(), [=]() {
        QSqlQuery query;
        query.prepare("SELECT word_type, synonyms, antonyms FROM thesaurus WHERE word = :word");
        query.bindValue(":word", word);
        query.exec();
        QList<ThesaurusEntity*> *result = new QList<ThesaurusEntity*>();
        while(query.next()) {
            QString wordType = query.value("word_type").toString();
            QString synonyms = query.value("synonyms").toString();
            QString antonyms = query.value("antonyms").toString();
            result->append(new ThesaurusEntity(wordType, synonyms, antonyms));
        }
        return result;
    });
}
