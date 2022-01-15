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
    if (matchingWordsCsv.isEmpty()) return result;
    QStringList matchingWordsList = matchingWordsCsv.split(",");
    matchingWordsList.sort(Qt::CaseInsensitive);
    result->append(new ThesaurusDisplayData(QCoreApplication::translate("main", label), true));
    // QTBUG-72872: Would be nice to use QtConcurrent::blockingMapped() here, instead of manually doing the map
    // from word to ThesaurusDisplayData, but there's a bug with nested QtConcurrent::blockingMapped calls
    for (auto& matchingWord : matchingWordsList) {
        result->append(new ThesaurusDisplayData(matchingWord, false, false, 1, true));
    }
    return result;
}
QList<ThesaurusDisplayData*>* ThesaurusEntityMapper::map(ThesaurusEntity* entity) {
    QList<ThesaurusDisplayData*> *result = new QList<ThesaurusDisplayData*>();
    result->append(new ThesaurusDisplayData(
                       QCoreApplication::translate("main", map(entity->wordType)),
                       false,
                       true,
                       0,
                       false,
                       ColorType::Surface));
    QList<ThesaurusDisplayData*> *synonyms = mapMatchingWords("synonyms", entity->synonyms);
    result->append(*synonyms);
    delete synonyms;

    QList<ThesaurusDisplayData*> *antonyms = mapMatchingWords("antonyms", entity->antonyms);
    result->append(*antonyms);
    delete antonyms;

    return result;
}
