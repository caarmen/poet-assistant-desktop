#include "rhymeentity.h"

RhymeEntity::RhymeEntity(
        QString word,
        QString stressSyllables,
        QObject *parent)
    : QObject{parent},
      word(word),
      stressSyllables(stressSyllables)
{
    RhymeEntity::refCounter.inc();
}

RhymeEntity::~RhymeEntity() {
    RhymeEntity::refCounter.dec();
}
