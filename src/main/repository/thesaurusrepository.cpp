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
