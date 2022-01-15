#include "thesaurusdisplaydata.h"

ThesaurusDisplayData::ThesaurusDisplayData(QString text,
                                           bool italic,
                                           bool bold,
                                           int indentLevel,
                                           bool interactive,
                                           ColorType backgroundColor,
                                           QObject *parent)
    : QObject{parent}, text(text), italic(italic), bold(bold), indentLevel(indentLevel), interactive(interactive), backgroundColor(backgroundColor)
{
    ThesaurusDisplayData::refCounter.inc();
}

ThesaurusDisplayData::~ThesaurusDisplayData() {
    ThesaurusDisplayData::refCounter.dec();
}
