#include "rhymeentitymapper.h"
#include <QtConcurrent>

RhymeEntityMapper::RhymeEntityMapper()
{

}

QList<RhymeDisplayData*>* RhymeEntityMapper::map(const RhymeEntity* wordVariant, const QStringList* rhymes) {
    auto result = new QList<RhymeDisplayData*>();
    result->append(new RhymeDisplayData(wordVariant->stressSyllables, false, true));
    auto sortedRhymes = QStringList(*rhymes);
    sortedRhymes.sort(Qt::CaseInsensitive);
    for (auto& rhyme : sortedRhymes) {
        result->append(new RhymeDisplayData(rhyme));
    }
    return result;
}
