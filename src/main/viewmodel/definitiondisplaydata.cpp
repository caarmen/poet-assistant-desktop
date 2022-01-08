#include "definitiondisplaydata.h"

DefinitionDisplayData::DefinitionDisplayData(QString partOfSpeech, QString definition, QObject *parent)
    : QObject{parent}, partOfSpeech(partOfSpeech), definition(definition)
{
    DefinitionDisplayData::refCounter.inc();
}

DefinitionDisplayData::~DefinitionDisplayData(){
    DefinitionDisplayData::refCounter.dec();
}
