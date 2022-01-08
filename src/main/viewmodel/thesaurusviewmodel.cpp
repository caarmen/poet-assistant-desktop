#include "thesaurusviewmodel.h"
#include "thesaurusentitymapper.h"

ThesaurusViewModel::ThesaurusViewModel(ThesaurusRepository *repository, QObject *parent)
    : QObject{parent}, repository(repository)
{

}

QFuture<QList<ThesaurusDisplayData*>*> ThesaurusViewModel::readThesaurus(QString searchText) {
    return repository->readThesaurus(searchText)
            .then([](QList<ThesaurusEntity*>* entities){
        QList<ThesaurusDisplayData*> *result = ThesaurusEntityMapper::map(entities);
        qDeleteAll(*entities);
        delete entities;
        return result;
    });
}
