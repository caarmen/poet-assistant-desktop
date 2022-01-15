#ifndef THESAURUSDISPLAYDATA_H
#define THESAURUSDISPLAYDATA_H

#include "refcounter.h"
#include "colortypeenum.h"
#include <QObject>

class ThesaurusDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text CONSTANT)
    Q_PROPERTY(bool italic MEMBER italic CONSTANT)
    Q_PROPERTY(bool bold MEMBER bold CONSTANT)
    Q_PROPERTY(int indentLevel MEMBER indentLevel CONSTANT)
    Q_PROPERTY(int interactive MEMBER interactive CONSTANT)
    Q_PROPERTY(ColorType backgroundColor MEMBER backgroundColor CONSTANT)
public:
    explicit ThesaurusDisplayData(QString text,
                                  bool italic = false,
                                  bool bold = false,
                                  int indentLevel = 0,
                                  bool interactive = false,
                                  ColorType backgroundColor = ColorType::Background,
                                  QObject *parent = nullptr);
    ~ThesaurusDisplayData();
    const QString text;
    const bool italic;
    const bool bold;
    const int indentLevel;
    const bool interactive;
    const ColorType backgroundColor;

private:
    static inline RefCounter refCounter = RefCounter("ThesaurusDisplayData");

};

#endif // THESAURUSDISPLAYDATA_H
