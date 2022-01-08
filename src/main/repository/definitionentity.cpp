#include "definitionentity.h"

DefinitionEntity::DefinitionEntity(QString partOfSpeech, QString definition, QObject *parent)
    : QObject{parent}, partOfSpeech(partOfSpeech), definition(definition)
{
    DefinitionEntity::refCounter.inc();
}

DefinitionEntity::~DefinitionEntity() {
    DefinitionEntity::refCounter.dec();
}
