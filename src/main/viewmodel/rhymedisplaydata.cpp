#include "rhymedisplaydata.h"

RhymeDisplayData::RhymeDisplayData(QString text, bool italic, bool bold, QObject *parent)
    : QObject{parent}, text(text), italic(italic), bold(bold)
{
    RhymeDisplayData::refCounter.inc();
}

RhymeDisplayData::~RhymeDisplayData() {
    RhymeDisplayData::refCounter.dec();
}
