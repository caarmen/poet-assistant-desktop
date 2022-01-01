#include "definitiondisplaydata.h"

DefinitionDisplayData::DefinitionDisplayData(QString partOfSpeech, QString definition, QObject *parent)
    : QObject{parent}, partOfSpeech(partOfSpeech), definition(definition)
{

}
