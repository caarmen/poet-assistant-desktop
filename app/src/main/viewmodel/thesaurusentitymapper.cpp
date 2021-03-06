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
#include "thesaurusentitymapper.h"
#include <QtConcurrent>

ThesaurusEntityMapper::ThesaurusEntityMapper()
{

}

QList<ThesaurusDisplayData *> *ThesaurusEntityMapper::map(const QList<ThesaurusEntity *> *entities)
{
    QList<ThesaurusDisplayData *> *result =
        QtConcurrent::blockingMappedReduced<QList<ThesaurusDisplayData *>*>(
            *entities,
    [ = ] (ThesaurusEntity * entity) {
        return map(entity);
    },
    [ = ](QList<ThesaurusDisplayData *> *acc, QList<ThesaurusDisplayData *> *entry) {
        acc->append(*entry);
        return acc;
    },
    new QList<ThesaurusDisplayData *>()
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

QList<ThesaurusDisplayData *> *ThesaurusEntityMapper::mapMatchingWords(const char *label,
                                                                       QString matchingWordsCsv)
{
    QList<ThesaurusDisplayData *> *result = new QList<ThesaurusDisplayData *>();
    if (matchingWordsCsv.isEmpty()) return result;
    QStringList matchingWordsList = matchingWordsCsv.split(",");
    matchingWordsList.sort(Qt::CaseInsensitive);
    result->append(new ThesaurusDisplayData(qtTrId(label), true));
    // QTBUG-72872: Would be nice to use QtConcurrent::blockingMapped() here, instead of manually doing the map
    // from word to ThesaurusDisplayData, but there's a bug with nested QtConcurrent::blockingMapped calls
    for (auto &matchingWord : matchingWordsList) {
        result->append(new ThesaurusDisplayData(matchingWord, false, false, true));
    }
    return result;
}
QList<ThesaurusDisplayData *> *ThesaurusEntityMapper::map(ThesaurusEntity *entity)
{
    QList<ThesaurusDisplayData *> *result = new QList<ThesaurusDisplayData *>();
    result->append(new ThesaurusDisplayData(
                       qtTrId(map(entity->wordType)),
                       false,
                       true,
                       false,
                       ColorType::Surface));
    QList<ThesaurusDisplayData *> *synonyms = mapMatchingWords("synonyms", entity->synonyms);
    result->append(*synonyms);
    delete synonyms;

    QList<ThesaurusDisplayData *> *antonyms = mapMatchingWords("antonyms", entity->antonyms);
    result->append(*antonyms);
    delete antonyms;

    return result;
}
const QString ThesaurusEntityMapper::mapListText(QString word,
                                                 const QList<ThesaurusEntity *> *entities)
{
    QList<ThesaurusDisplayData *> *displayDataList = map(entities);
    QStringList entitiesAsText = QtConcurrent::blockingMapped(*displayDataList,
                                                              &ThesaurusEntityMapper::mapItemText);
    entitiesAsText.prepend(qtTrId("thesaurus_results_text_title").arg(word));
    QString result = entitiesAsText.join("\n");
    qDeleteAll(*displayDataList);
    delete displayDataList;
    return result;
}

QString ThesaurusEntityMapper::mapItemText(ThesaurusDisplayData *thesaurusDisplayData)
{
    if (thesaurusDisplayData->bold)  {
        return thesaurusDisplayData->text;
    } else if (thesaurusDisplayData->italic)  {
        return qtTrId("text_indent_1").arg(thesaurusDisplayData->text);
    } else {
        return qtTrId("text_indent_2").arg(thesaurusDisplayData->text);
    }
}
