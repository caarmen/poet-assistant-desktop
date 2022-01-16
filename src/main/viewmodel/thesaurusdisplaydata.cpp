#include "thesaurusdisplaydata.h"

ThesaurusDisplayData::ThesaurusDisplayData(QString text,
                                           bool italic,
                                           bool bold,
                                           bool interactive,
                                           ColorType backgroundColor,
                                           QObject *parent)
    : QObject{parent},
      text(text),
      italic(italic),
      bold(bold),
      interactive(interactive),
      backgroundColor(backgroundColor)
{
    ThesaurusDisplayData::refCounter.inc();
}

ThesaurusDisplayData::~ThesaurusDisplayData() {
    ThesaurusDisplayData::refCounter.dec();
}
