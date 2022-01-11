#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(RhymeListModel *rhymeListModel, ThesaurusListModel *thesaurusListModel, DefinitionListModel *definitionsListModel, QObject *parent)
    : QObject{parent}, rhymeListModel(rhymeListModel), thesaurusListModel(thesaurusListModel), definitionsListModel(definitionsListModel)
{

}

void MainViewModel::search(QString searchText) {
    QString transformedSearchText = searchText.trimmed().toLower();
    rhymeListModel->readRhymes(transformedSearchText);
    definitionsListModel->readDefinitions(transformedSearchText);
    thesaurusListModel->readThesaurus(transformedSearchText);
}

void MainViewModel::searchRhymes(QString searchText) {
    QString transformedSearchText = searchText.trimmed().toLower();
    rhymeListModel->readRhymes(transformedSearchText);
}

void MainViewModel::searchThesaurus(QString searchText) {
    QString transformedSearchText = searchText.trimmed().toLower();
    thesaurusListModel->readThesaurus(transformedSearchText);
}

void MainViewModel::searchDefinitions(QString searchText) {
    QString transformedSearchText = searchText.trimmed().toLower();
    definitionsListModel->readDefinitions(transformedSearchText);
}
