#include "rhymeentitymapper.h"
#include <QtConcurrent>

RhymeEntityMapper::RhymeEntityMapper()
{

}

QList<RhymeDisplayData*>* RhymeEntityMapper::map(const QList<RhymeEntity*>* rhymeEntities) {
    auto *result = new QList<RhymeDisplayData*>();
    QString currentSyllables = "";
    for(auto *rhymeEntity : *rhymeEntities) {
        if (currentSyllables != rhymeEntity->stressSyllables) {
            result->append(new RhymeDisplayData(rhymeEntity->stressSyllables, false, true));
            currentSyllables = rhymeEntity->stressSyllables;
        }
        result->append(new RhymeDisplayData(rhymeEntity->word));
    }
    return result;
}
