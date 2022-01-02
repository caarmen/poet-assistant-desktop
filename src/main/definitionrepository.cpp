#include "definitionrepository.h"
#include <QtConcurrent>

DefinitionRepository::DefinitionRepository(QThreadPool *threadPool, QSqlDatabase *db, QObject *parent)
    : QObject{parent}, db(db), threadPool(threadPool)
{

}

QFuture<QList<DefinitionDisplayData*>*> DefinitionRepository::readDefinitions(QString word) {
    return QtConcurrent::run(threadPool, [=]() {
        QSqlQuery query;
        query.prepare("SELECT part_of_speech, definition FROM dictionary WHERE word = :word");
        query.bindValue(":word", word);
        query.exec();
        QList<DefinitionDisplayData*> *result = new QList<DefinitionDisplayData*>();
        while(query.next()) {
            QString definition = query.value("definition").toString();
            QString partOfSpeech = query.value("part_of_speech").toString();
            result->append(new DefinitionDisplayData(partOfSpeech, definition));
        }
        return result;
    });
}
