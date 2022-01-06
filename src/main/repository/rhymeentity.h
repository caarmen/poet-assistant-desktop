#ifndef RHYMEENTITY_H
#define RHYMEENTITY_H

#include "refcounter.h"
#include <QDebug>
#include <QObject>

class RhymeEntity : public QObject
{
    Q_OBJECT
public:
    explicit RhymeEntity(
            QString word,
            int variantNumber,
            QString stressSyllables,
            QString lastThreeSyllables,
            QString lastTwoSyllables,
            QString lastSyllable,
            QObject *parent = nullptr);
    ~RhymeEntity();
    const int variantNumber;
    const QString word;
    const QString stressSyllables;
    const QString lastThreeSyllables;
    const QString lastTwoSyllables;
    const QString lastSyllable;
signals:

private:
    static inline RefCounter refCounter = RefCounter("RhymeEntity");
};


#endif // RHYMEENTITY_H
