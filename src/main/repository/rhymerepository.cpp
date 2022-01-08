#include "rhymerepository.h"
#include <QtConcurrent>

RhymeRepository::RhymeRepository(Db *db, QObject *parent)
    : QObject{parent}, db(db)
{

}

QFuture<QList<RhymeEntity*>*> RhymeRepository::readStressSyllableRhymes(QString word){
    return QtConcurrent::run(db->getThreadPool(), [=]() {
        QSqlQuery query;
        query.prepare(R""""(
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
)"""");
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
