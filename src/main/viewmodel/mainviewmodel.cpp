#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(RhymeListModel *rhymeListModel, ThesaurusListModel *thesaurusListModel, DefinitionListModel *definitionsListModel, QObject *parent)
    : QObject{parent}, rhymeListModel(rhymeListModel), thesaurusListModel(thesaurusListModel), definitionsListModel(definitionsListModel)
{

}

void MainViewModel::search(QString searchText) {
    qDebug() << "search " << searchText;
    rhymeListModel->readRhymes(searchText);
    definitionsListModel->readDefinitions(searchText);
    thesaurusListModel->readThesaurus(searchText);
}
