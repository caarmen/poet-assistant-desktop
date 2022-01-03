#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(ThesaurusListModel *thesaurusListModel, DefinitionListModel *definitionsListModel, QObject *parent)
    : QObject{parent}, thesaurusListModel(thesaurusListModel), definitionsListModel(definitionsListModel)
{

}

void MainViewModel::search(QString searchText) {
    qDebug() << "search " << searchText;
    definitionsListModel->readDefinitions(searchText);
    thesaurusListModel->readThesaurus(searchText);
}
