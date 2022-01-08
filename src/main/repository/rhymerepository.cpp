#include "rhymerepository.h"
#include <QtConcurrent>

RhymeRepository::RhymeRepository(Db *db, QObject *parent)
    : QObject{parent}, db(db)
{

}


QFuture<QList<RhymeEntity*>*> RhymeRepository::readWordVariants(QString word)
{
    return QtConcurrent::run(db->getThreadPool(), [=]() {
        QSqlQuery query;
        query.prepare("SELECT word, variant_number, stress_syllables, last_three_syllables, last_two_syllables, last_syllable FROM word_variants WHERE word = :word");
        query.bindValue(":word", word);
        query.exec();
        QList<RhymeEntity*> *result = new QList<RhymeEntity*>();
        while(query.next()) {
            result->append(create(query));
        }
        return result;
    });
}


QFuture<QStringList*> RhymeRepository::readByStressSyllablesExcludingWord(QString stressSyllables, QString word) {
    return QtConcurrent::run(db->getThreadPool(), [=]() {
        QSqlQuery query;
        query.prepare(R""""(
            SELECT word
            FROM word_variants
            WHERE
                stress_syllables = :stressSyllables
                AND  word <> :word
)"""");
        query.bindValue(":word", word);
        query.bindValue(":stressSyllables", stressSyllables);
                query.exec();
        QStringList *result = new QStringList();
        while(query.next()) {
            result->append(query.value("word").toString());
        }
        return result;
    });
}

RhymeEntity* RhymeRepository::create(QSqlQuery &query) {
    QString word = query.value("word").toString();
    int variantNumber = query.value("variant_number").toInt();
    QString stressSyllables = query.value("stress_syllables").toString();
    QString lastThreeSyllables = query.value("last_three_syllables").toString();
    QString lastTwoSyllables = query.value("last_two_syllables").toString();
    QString lastSyllable = query.value("last_syllable").toString();
    return new RhymeEntity(word, variantNumber, stressSyllables, lastThreeSyllables, lastTwoSyllables, lastSyllable);

}
