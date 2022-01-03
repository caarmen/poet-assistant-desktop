#ifndef THESAURUSENTITYMAPPER_H
#define THESAURUSENTITYMAPPER_H

#include "thesaurusdisplaydata.h"
#include "thesaurusentity.h"
#include <QString>

class ThesaurusEntityMapper
{
public:
    static QList<ThesaurusDisplayData*>* map(QList<ThesaurusEntity*> *entities);
private:
    static QList<ThesaurusDisplayData*>* map(ThesaurusEntity* entity);
    static const char * map(const QString &wordType);
    static QList<ThesaurusDisplayData*>* mapMatchingWords(const char * label, QString matchingWordsCsv);
    ThesaurusEntityMapper();
};

#endif // THESAURUSENTITYMAPPER_H
