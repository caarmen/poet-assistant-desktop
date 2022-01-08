#ifndef THESAURUSDISPLAYDATA_H
#define THESAURUSDISPLAYDATA_H

#include "refcounter.h"
#include <QObject>

class ThesaurusDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text CONSTANT)
    Q_PROPERTY(bool italic MEMBER italic CONSTANT)
    Q_PROPERTY(bool bold MEMBER bold CONSTANT)
public:
    explicit ThesaurusDisplayData(QString text, bool italic = false, bool bold = false, QObject *parent = nullptr);
    ~ThesaurusDisplayData();
    const QString text;
    const bool italic;
    const bool bold;

private:
    static inline RefCounter refCounter = RefCounter("ThesaurusDisplayData");

};

#endif // THESAURUSDISPLAYDATA_H
