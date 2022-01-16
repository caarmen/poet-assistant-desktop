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
#include "rhymerepository.h"
#include <QtConcurrent>

RhymeRepository::RhymeRepository(Db *db, QObject *parent)
    : QObject{parent}, db(db)
{

}

QFuture<QList<RhymeEntity*>*> RhymeRepository::readStressSyllableRhymes(QString word){
    return QtConcurrent::run(db->getThreadPool(), [=]() {
        QSqlQuery query;
        query.prepare(R"(
            SELECT
              rhymes_word_variants.word,
              source_word_variants.stress_syllables
            FROM
              word_variants AS source_word_variants
              JOIN word_variants AS rhymes_word_variants ON source_word_variants.stress_syllables = rhymes_word_variants.stress_syllables
              AND source_word_variants.word != rhymes_word_variants.word
            WHERE
              source_word_variants.word = :word
            ORDER BY
              source_word_variants.variant_number,
              rhymes_word_variants.word;
)");
        query.bindValue(":word", word);
                query.exec();
        auto *result = new QList<RhymeEntity*>();
        while(query.next()) {
            result->append(create(query));
        }
        return result;
    });
}

RhymeEntity* RhymeRepository::create(QSqlQuery &query) {
    QString word = query.value("word").toString();
    QString stressSyllables = query.value("stress_syllables").toString();
    return new RhymeEntity(word, stressSyllables);
}
