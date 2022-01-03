#ifndef DEFINITIONDISPLAYDATA_H
#define DEFINITIONDISPLAYDATA_H

#include <QObject>

class DefinitionDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString part_of_speech MEMBER partOfSpeech CONSTANT)
    Q_PROPERTY(QString definition MEMBER definition CONSTANT)
public:
    explicit DefinitionDisplayData(QString partOfSpeech, QString definition, QObject *parent = nullptr);
    const QString partOfSpeech;
    const QString definition;

signals:

};

#endif // DEFINITIONDISPLAYDATA_H
