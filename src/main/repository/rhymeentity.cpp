#include "rhymeentity.h"

RhymeEntity::RhymeEntity(
        QString word,
        int variantNumber,
        QString stressSyllables,
        QString lastThreeSyllables,
        QString lastTwoSyllables,
        QString lastSyllable,
        QObject *parent)
    : QObject{parent},
      variantNumber(variantNumber),
      word(word),
      stressSyllables(stressSyllables),
      lastThreeSyllables(lastThreeSyllables),
      lastTwoSyllables(lastTwoSyllables),
      lastSyllable(lastSyllable)
{
    RhymeEntity::refCounter.inc();
}

RhymeEntity::~RhymeEntity() {
    RhymeEntity::refCounter.dec();
}
