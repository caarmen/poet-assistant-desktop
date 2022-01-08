#include "definitionviewmodel.h"
#include "definitionentitymapper.h"

DefinitionViewModel::DefinitionViewModel(DefinitionRepository *repository, QObject *parent)
    : QObject{parent}, repository(repository)
{

}

QFuture<QList<DefinitionDisplayData*>*> DefinitionViewModel::readDefinitions(QString searchText) {
    return repository->readDefinitions(searchText)
            .then([](QList<DefinitionEntity*>* entities){
        QList<DefinitionDisplayData*> *result = DefinitionEntityMapper::map(entities);
        qDeleteAll(*entities);
        delete entities;
        return result;
    });
}
