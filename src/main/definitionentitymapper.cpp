#include "definitionentitymapper.h"

DefinitionEntityMapper::DefinitionEntityMapper()
{
}

QString DefinitionEntityMapper::map(const QString &partOfSpeech)
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
    return new DefinitionDisplayData(map(entity->partOfSpeech), entity->definition);
}
