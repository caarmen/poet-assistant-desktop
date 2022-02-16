/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(RhymeListModel *rhymeListModel,
                             ThesaurusListModel *thesaurusListModel,
                             DefinitionListModel *definitionsListModel,
                             FavoriteRepository *favoriteRepository,
                             SuggestionListModel *suggestionListModel,
                             QObject *parent)
    : QObject{parent},
      rhymeListModel(rhymeListModel),
      thesaurusListModel(thesaurusListModel),
      definitionsListModel(definitionsListModel),
      favoriteRepository(favoriteRepository),
      suggestionListModel(suggestionListModel)
{

}

void MainViewModel::search(QString searchText) {
    QString transformedSearchText = searchText.trimmed().toLower();
    rhymeListModel->readRhymes(transformedSearchText);
    definitionsListModel->readDefinitions(transformedSearchText);
    thesaurusListModel->readThesaurus(transformedSearchText);
    suggestionListModel->readSuggestions("");
}

void MainViewModel::searchSuggestions(QString searchText) {
    QString transformedSearchText = searchText.trimmed().toLower();
    suggestionListModel->readSuggestions(transformedSearchText);
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

void MainViewModel::clearFavorites() {
    favoriteRepository->clear();
    emit favoritesChanged();
}
