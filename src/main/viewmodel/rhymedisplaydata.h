#ifndef RHYMEDISPLAYDATA_H
#define RHYMEDISPLAYDATA_H

#include "refcounter.h"
#include <QObject>

class RhymeDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text CONSTANT)
    Q_PROPERTY(bool italic MEMBER italic CONSTANT)
    Q_PROPERTY(bool bold MEMBER bold CONSTANT)
    Q_PROPERTY(int indentLevel MEMBER indentLevel CONSTANT)
    Q_PROPERTY(int interactive MEMBER interactive CONSTANT)
public:
    explicit RhymeDisplayData(QString text,
                              bool italic = false,
                              bool bold = false,
                              int indentLevel = 0,
                              bool interactive = false,
                              QObject *parent = nullptr);
    ~RhymeDisplayData();
    const QString text;
    const bool italic;
    const bool bold;
    const int indentLevel;
    const bool interactive;

private:
    static inline RefCounter refCounter = RefCounter("RhymeDisplayData");

};

#endif // RHYMEDISPLAYDATA_H
