#include "rhymedisplaydata.h"

RhymeDisplayData::RhymeDisplayData(QString text, bool italic, bool bold, int indentLevel, QObject *parent)
    : QObject{parent}, text(text), italic(italic), bold(bold), indentLevel(indentLevel)
{
    RhymeDisplayData::refCounter.inc();
}

RhymeDisplayData::~RhymeDisplayData() {
    RhymeDisplayData::refCounter.dec();
}
