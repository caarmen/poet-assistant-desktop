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
#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "rhymelistmodel.h"
#include "definitionlistmodel.h"
#include "thesauruslistmodel.h"
#include "favoriterepository.h"
#include "suggestionlistmodel.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(RhymeListModel *rhymeListModel,
                           RhymeViewModel *rhymeViewModel,
                           ThesaurusListModel *thesaurusListModel,
                           ThesaurusViewModel *thesaurusViewModel,
                           DefinitionListModel *definitionsListModel,
                           DefinitionViewModel *definitionViewModel,
                           FavoriteRepository *favoriteRepository,
                           SuggestionListModel *suggestionListModel,
                           QObject *parent = nullptr);
    Q_INVOKABLE void copy(QString query);
    Q_INVOKABLE void search(QString query);
    Q_INVOKABLE void searchSuggestions(QString searchText);
    Q_INVOKABLE void searchRhymes(QString query);
    Q_INVOKABLE void copyRhymes(QString query);
    Q_INVOKABLE void searchThesaurus(QString query);
    Q_INVOKABLE void copyThesaurus(QString query);
    Q_INVOKABLE void searchDefinitions(QString query);
    Q_INVOKABLE void copyDefinitions(QString query);
    Q_INVOKABLE QString getFavoriteIcon(QString word);
    Q_INVOKABLE void toggleFavorite(QString query);
    Q_INVOKABLE void copyFavorites();
    Q_INVOKABLE void clearFavorites();

signals:
    void favoritesChanged();

private:
    void copyWhenReady(QFuture<QString> future);
    RhymeListModel *rhymeListModel;
    RhymeViewModel *rhymeViewModel;
    ThesaurusListModel *thesaurusListModel;
    ThesaurusViewModel *thesaurusViewModel;
    DefinitionListModel *definitionsListModel;
    DefinitionViewModel *definitionViewModel;
    FavoriteRepository *favoriteRepository;
    SuggestionListModel *suggestionListModel;
};

#endif // MAINVIEWMODEL_H
