#include "thesaurusentitymapper.h"
#include <QtConcurrent>

ThesaurusEntityMapper::ThesaurusEntityMapper()
{

}

QList<ThesaurusDisplayData*>* ThesaurusEntityMapper::map(QList<ThesaurusEntity*> *entities)
{
    QList<ThesaurusDisplayData*>* result = QtConcurrent::blockingMappedReduced<QList<ThesaurusDisplayData*>*>(
                *entities,
                [=] (ThesaurusEntity *entity) {
        return map(entity);
    },
    [=](QList<ThesaurusDisplayData*>* acc, QList<ThesaurusDisplayData*>* entry) {
        acc->append(*entry);
        return acc;
    },
    new QList<ThesaurusDisplayData*>()
    );
    return result;
}

const char *ThesaurusEntityMapper::map(const QString &wordType)
{
    if (wordType == "ADJ") {
        return "adjective";
    } else if (wordType == "NOUN") {
        return "noun";
    } else if (wordType == "ADV") {
        return "adverb";
    } else if (wordType == "VERB") {
        return "verb";
    } else {
        return "unknown";
    }
}

QList<ThesaurusDisplayData*>* ThesaurusEntityMapper::mapMatchingWords(const char *label, QString matchingWordsCsv) {
    QList<ThesaurusDisplayData*> *result = new QList<ThesaurusDisplayData*>();
    QStringList matchingWordsList = matchingWordsCsv.split(",");
    matchingWordsList.sort(Qt::CaseInsensitive);
    QStringList nonEmptyMatchingWordsList = QtConcurrent::blockingFiltered(
                matchingWordsList,
                [=] (QString word) { return !word.isEmpty(); }
    );
    if (!nonEmptyMatchingWordsList.isEmpty()) {
        result->append(new ThesaurusDisplayData(QCoreApplication::translate("main", label)));
        result->append(QtConcurrent::blockingMapped(nonEmptyMatchingWordsList, [=](QString matchingWord){
            return new ThesaurusDisplayData(matchingWord);
        }
        ));
    }
    return result;
}
QList<ThesaurusDisplayData*>* ThesaurusEntityMapper::map(ThesaurusEntity* entity) {
    QList<ThesaurusDisplayData*> *result = new QList<ThesaurusDisplayData*>();
    result->append(new ThesaurusDisplayData(QCoreApplication::translate("main", map(entity->wordType))));
    QList<ThesaurusDisplayData*> *synonyms = mapMatchingWords("synonyms", entity->synonyms);
    result->append(*synonyms);
    delete synonyms;

    QList<ThesaurusDisplayData*> *antonyms = mapMatchingWords("antonyms", entity->antonyms);
    result->append(*antonyms);
    delete antonyms;

    return result;
}
