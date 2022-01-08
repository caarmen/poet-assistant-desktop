#ifndef DEFINITIONVIEWMODEL_H
#define DEFINITIONVIEWMODEL_H

#include "definitionrepository.h"
#include "definitiondisplaydata.h"
#include <QObject>
#include <QFuture>

class DefinitionViewModel : public QObject
{
    Q_OBJECT
public:
    explicit DefinitionViewModel(DefinitionRepository *repository, QObject *parent = nullptr);
    QFuture<QList<DefinitionDisplayData*>*> readDefinitions(QString searchText);

private:
    DefinitionRepository *repository;
};

#endif // DEFINITIONVIEWMODEL_H
