#ifndef DEFINITIONENTITY_H
#define DEFINITIONENTITY_H

#include <QObject>

class DefinitionEntity : public QObject
{
    Q_OBJECT
public:
    explicit DefinitionEntity(QString partOfSpeech, QString definition, QObject *parent = nullptr);
    const QString partOfSpeech;
    const QString definition;
signals:

};

#endif // DEFINITIONENTITY_H
