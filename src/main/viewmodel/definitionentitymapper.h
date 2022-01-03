#ifndef DEFINITIONENTITYMAPPER_H
#define DEFINITIONENTITYMAPPER_H

#include "definitionentity.h"
#include "definitiondisplaydata.h"
#include <QString>


class DefinitionEntityMapper
{
public:
    static QList<DefinitionDisplayData*>* map(QList<DefinitionEntity*> *entities);
private:
    static DefinitionDisplayData* map(DefinitionEntity* entity);
    static const char * map(const QString &partOfSpeech);
    DefinitionEntityMapper();
};

#endif // DEFINITIONENTITYMAPPER_H
