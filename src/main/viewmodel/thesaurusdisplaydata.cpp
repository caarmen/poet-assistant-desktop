#include "thesaurusdisplaydata.h"

ThesaurusDisplayData::ThesaurusDisplayData(QString text, bool italic, bool bold, int indentLevel, QObject *parent)
    : QObject{parent}, text(text), italic(italic), bold(bold), indentLevel(indentLevel)
{
    ThesaurusDisplayData::refCounter.inc();
}

ThesaurusDisplayData::~ThesaurusDisplayData() {
    ThesaurusDisplayData::refCounter.dec();
}
