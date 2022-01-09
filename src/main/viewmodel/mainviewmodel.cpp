#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(RhymeListModel *rhymeListModel, ThesaurusListModel *thesaurusListModel, DefinitionListModel *definitionsListModel, QObject *parent)
    : QObject{parent}, rhymeListModel(rhymeListModel), thesaurusListModel(thesaurusListModel), definitionsListModel(definitionsListModel)
{

}

void MainViewModel::search(QString searchText) {
    qDebug() << "search " << searchText;
    QString transformedSearchText = searchText.trimmed().toLower();
    rhymeListModel->readRhymes(transformedSearchText);
    definitionsListModel->readDefinitions(transformedSearchText);
    thesaurusListModel->readThesaurus(transformedSearchText);
}
