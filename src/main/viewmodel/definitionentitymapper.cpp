#include "definitionentitymapper.h"

#include <QCoreApplication>

DefinitionEntityMapper::DefinitionEntityMapper()
{
}

const char * DefinitionEntityMapper::map(const QString &partOfSpeech)
{
    if (partOfSpeech == "a") {
        return "adjective";
    } else if (partOfSpeech == "n") {
        return "noun";
    } else if (partOfSpeech == "r") {
        return "adverb";
    } else if (partOfSpeech == "v") {
        return "verb";
    } else {
        return "unknown";
    }
}

DefinitionDisplayData* DefinitionEntityMapper::map(DefinitionEntity* entity)
{
    return new DefinitionDisplayData(QCoreApplication::translate("main", map(entity->partOfSpeech)), entity->definition);
}
