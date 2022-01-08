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
            QString stressSyllables,
            QObject *parent = nullptr);
    ~RhymeEntity();
    const QString word;
    const QString stressSyllables;
signals:

private:
    static inline RefCounter refCounter = RefCounter("RhymeEntity");
};


#endif // RHYMEENTITY_H
