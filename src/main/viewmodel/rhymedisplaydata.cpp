#include "rhymedisplaydata.h"

RhymeDisplayData::RhymeDisplayData(QString text,
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
    RhymeDisplayData::refCounter.inc();
}

RhymeDisplayData::~RhymeDisplayData() {
    RhymeDisplayData::refCounter.dec();
}
