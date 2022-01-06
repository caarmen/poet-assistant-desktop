#ifndef RHYMEENTITYMAPPER_H
#define RHYMEENTITYMAPPER_H

#include "rhymedisplaydata.h"
#include "rhymeentity.h"
#include <QStringList>

class RhymeEntityMapper
{
public:
    static QList<RhymeDisplayData*>* map(const RhymeEntity* wordVariant, const QStringList* rhymes);
private:
    RhymeEntityMapper();
};

#endif // RHYMEENTITYMAPPER_H
