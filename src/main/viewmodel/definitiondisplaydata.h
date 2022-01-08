#ifndef DEFINITIONDISPLAYDATA_H
#define DEFINITIONDISPLAYDATA_H

#include "refcounter.h"
#include <QObject>

class DefinitionDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString part_of_speech MEMBER partOfSpeech CONSTANT)
    Q_PROPERTY(QString definition MEMBER definition CONSTANT)
public:
    explicit DefinitionDisplayData(QString partOfSpeech, QString definition, QObject *parent = nullptr);
    ~DefinitionDisplayData();
    const QString partOfSpeech;
    const QString definition;

private:
    static inline RefCounter refCounter = RefCounter("DefinitionDisplayData");
};

#endif // DEFINITIONDISPLAYDATA_H
