#include "thesaurusdisplaydata.h"

ThesaurusDisplayData::ThesaurusDisplayData(QString text, bool italic, bool bold, QObject *parent)
    : QObject{parent}, text(text), italic(italic), bold(bold)
{

}
