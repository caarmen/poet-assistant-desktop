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
        QString fullQueryString = createFullQueryString();
        query.prepare(fullQueryString);
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
    QString syllablesTypeString = query.value("syllables_type").toString();
    QString syllables = query.value("syllables").toString();
    RhymeEntity::SyllablesType syllablesType = parse(syllablesTypeString);
    return new RhymeEntity(word, syllablesType, syllables);
}

QString RhymeRepository::createQueryString(QString syllablesTypeFieldName, QString syllablesTypeSortKey) {
    QString result = QString(R"(
            SELECT
              '%1' AS syllables_type,
              source_word_variants.%1 AS syllables,
              '%2' AS syllables_type_sort_key,
              source_word_variants.variant_number,
              rhymes_word_variants.word,
              rhymes_word_variants.has_definition,
              source_word_variants.%1
            FROM
              word_variants AS source_word_variants
              JOIN word_variants AS rhymes_word_variants ON source_word_variants.%1 = rhymes_word_variants.%1
              AND source_word_variants.word != rhymes_word_variants.word
            WHERE
              rhymes_word_variants.has_definition = 1
              AND source_word_variants.word = :word
)").arg(syllablesTypeFieldName, syllablesTypeSortKey);
    return result;
}

QString RhymeRepository::createFullQueryString() {
    QVector<QString> subQueries;
    subQueries.append(createQueryString("stress_syllables", "1"));
    subQueries.append(createQueryString("last_three_syllables", "2"));
    subQueries.append(createQueryString("last_two_syllables", "3"));
    subQueries.append(createQueryString("last_syllable", "4"));
    return subQueries.join("\nUNION\n").append(R"(
            ORDER BY
              syllables_type_sort_key,
              source_word_variants.variant_number,
              rhymes_word_variants.word;
)");
}

RhymeEntity::SyllablesType RhymeRepository::parse(QString syllablesTypeString) {
    if (syllablesTypeString == "stress_syllables") {
        return RhymeEntity::STRICT;
    } else if (syllablesTypeString == "last_three_syllables") {
        return RhymeEntity::LAST_3;
    } else if (syllablesTypeString == "last_two_syllables") {
        return RhymeEntity::LAST_2;
    } else {
        return RhymeEntity::LAST_1;
    }
}
