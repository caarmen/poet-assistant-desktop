#ifndef DEFINITIONENTITYMAPPER_H
#define DEFINITIONENTITYMAPPER_H

#include "definitionentity.h"
#include "definitiondisplaydata.h"
#include <QString>


class DefinitionEntityMapper
{
public:
    static QString map(const QString &partOfSpeech);
    static DefinitionDisplayData* map(DefinitionEntity* entity);
private:
    DefinitionEntityMapper();
};

#endif // DEFINITIONENTITYMAPPER_H
