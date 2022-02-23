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
#include <QClipboard>
#include <QDebug>
#include <QGuiApplication>
MainViewModel::MainViewModel(RhymeListModel *rhymeListModel,
                             RhymeViewModel *rhymeViewModel,
                             ThesaurusListModel *thesaurusListModel,
                             ThesaurusViewModel *thesaurusViewModel,
                             DefinitionListModel *definitionsListModel,
                             DefinitionViewModel *definitionViewModel,
                             FavoriteRepository *favoriteRepository,
                             SuggestionListModel *suggestionListModel,
                             SuggestionViewModel *suggestionViewModel,
                             AppearanceRepository *appearanceRepository,
                             QObject *parent)
    : QObject{parent},
      rhymeListModel(rhymeListModel),
      rhymeViewModel(rhymeViewModel),
      thesaurusListModel(thesaurusListModel),
      thesaurusViewModel(thesaurusViewModel),
      definitionsListModel(definitionsListModel),
      definitionViewModel(definitionViewModel),
      favoriteRepository(favoriteRepository),
      suggestionListModel(suggestionListModel),
      suggestionViewModel(suggestionViewModel),
      appearanceRepository(appearanceRepository)
{
    QObject::connect(appearanceRepository, &AppearanceRepository::nightModeChanged, this, [ = ] { emit nightModeChanged();});
}

void MainViewModel::copy(QString word)
{
    QGuiApplication::clipboard()->setText(word);
}

void MainViewModel::search(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    rhymeListModel->readRhymes(transformedSearchText);
    definitionsListModel->readDefinitions(transformedSearchText);
    thesaurusListModel->readThesaurus(transformedSearchText);
    suggestionListModel->clearSuggestions();
    suggestionViewModel->addSuggestionFromHistory(transformedSearchText);
}

void MainViewModel::clearSuggestions()
{
    suggestionListModel->clearSuggestions();
}
void MainViewModel::searchSuggestions(QString searchText, bool ignoreEmptySearchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    if (ignoreEmptySearchText && transformedSearchText.isEmpty()) {
        suggestionListModel->clearSuggestions();
    } else {
        suggestionListModel->readSuggestions(transformedSearchText);
    }
}

void MainViewModel::searchRhymes(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    rhymeListModel->readRhymes(transformedSearchText);
    suggestionViewModel->addSuggestionFromHistory(transformedSearchText);
}

void MainViewModel::copyRhymes(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    copyWhenReady(rhymeViewModel->readRhymesText(transformedSearchText));
}

void MainViewModel::searchThesaurus(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    thesaurusListModel->readThesaurus(transformedSearchText);
    suggestionViewModel->addSuggestionFromHistory(transformedSearchText);
}

void MainViewModel::copyThesaurus(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    copyWhenReady(thesaurusViewModel->readThesaurusText(transformedSearchText));
}

void MainViewModel::searchDefinitions(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    definitionsListModel->readDefinitions(transformedSearchText);
    suggestionViewModel->addSuggestionFromHistory(transformedSearchText);
}

void MainViewModel::copyDefinitions(QString searchText)
{
    QString transformedSearchText = searchText.trimmed().toLower();
    copyWhenReady(definitionViewModel->readDefinitionsText(transformedSearchText));
}

QString MainViewModel::getFavoriteIcon(QString word)
{
    return favoriteRepository->isFavorite(word) ?  "qrc:/images/star.svg" :
           "qrc:/images/star_border.svg";
}
QString MainViewModel::getFavoriteLabel(QString word)
{
    return favoriteRepository->isFavorite(word) ?  "a11y_icon_favorite_checked" :
           "a11y_icon_favorite_unchecked";
}
void MainViewModel::toggleFavorite(QString query)
{
    favoriteRepository->toggleFavorite(query);
    emit favoritesChanged();
}

void MainViewModel::copyFavorites()
{
    QStringList result;
    result.append(*favoriteRepository->readAll());
    result.prepend(qtTrId("favorites_text_title"));
    copy(result.join("\n"));
}
void MainViewModel::clearFavorites()
{
    favoriteRepository->clear();
    emit favoritesChanged();
}

bool MainViewModel::isNightMode()
{
    AppearanceRepository::NightMode nightMode = appearanceRepository->getNightMode();
    if (nightMode == AppearanceRepository::NightMode::Day) {
        return false;
    } else if (nightMode == AppearanceRepository::NightMode::Night) {
        return true;
    } else {
        QPalette systemPalette = QGuiApplication::palette();
        return systemPalette.window().color().value() < systemPalette.windowText().color().value();
    }
}
void MainViewModel::copyWhenReady(QFuture<QString> future)
{
    auto *watcher = new QFutureWatcher<QString>();
    QObject::connect(watcher, &QFutureWatcher<QString>::finished, this, [ = ]() {
        copy(future.result());
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}
