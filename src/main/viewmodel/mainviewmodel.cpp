#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(RhymeListModel *rhymeListModel,
                             ThesaurusListModel *thesaurusListModel,
                             DefinitionListModel *definitionsListModel,
                             FavoriteRepository *favoriteRepository,
                             QObject *parent)
    : QObject{parent},
      rhymeListModel(rhymeListModel),
      thesaurusListModel(thesaurusListModel),
      definitionsListModel(definitionsListModel),
      favoriteRepository(favoriteRepository)
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

QString MainViewModel::getFavoriteIcon(QString word) {
    return favoriteRepository->isFavorite(word) ?  "qrc:/images/star.svg" : "qrc:/images/star_border.svg";
}
void MainViewModel::toggleFavorite(QString query) {
    favoriteRepository->toggleFavorite(query);
    emit favoritesChanged();
}
