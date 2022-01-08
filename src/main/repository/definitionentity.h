#ifndef DEFINITIONENTITY_H
#define DEFINITIONENTITY_H

#include "refcounter.h"
#include <QObject>

class DefinitionEntity : public QObject
{
    Q_OBJECT
public:
    explicit DefinitionEntity(QString partOfSpeech, QString definition, QObject *parent = nullptr);
    ~DefinitionEntity();
    const QString partOfSpeech;
    const QString definition;

private:
    static inline RefCounter refCounter = RefCounter("DefinitionEntity");
};

#endif // DEFINITIONENTITY_H
