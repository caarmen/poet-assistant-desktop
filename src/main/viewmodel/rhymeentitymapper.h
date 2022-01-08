#ifndef RHYMEENTITYMAPPER_H
#define RHYMEENTITYMAPPER_H

#include "rhymedisplaydata.h"
#include "rhymeentity.h"
#include <QStringList>

class RhymeEntityMapper
{
public:
    static QList<RhymeDisplayData*>* map(const QList<RhymeEntity*>* rhymeEntities);
private:
    RhymeEntityMapper();
};

#endif // RHYMEENTITYMAPPER_H
