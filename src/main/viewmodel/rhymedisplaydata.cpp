#include "rhymedisplaydata.h"

RhymeDisplayData::RhymeDisplayData(QString text,
                                   bool italic,
                                   bool bold,
                                   int indentLevel,
                                   bool interactive,
                                   ColorType backgroundColor,
                                   QObject *parent)
    : QObject{parent}, text(text), italic(italic), bold(bold), indentLevel(indentLevel), interactive(interactive), backgroundColor(backgroundColor)
{
    RhymeDisplayData::refCounter.inc();
}

RhymeDisplayData::~RhymeDisplayData() {
    RhymeDisplayData::refCounter.dec();
}
