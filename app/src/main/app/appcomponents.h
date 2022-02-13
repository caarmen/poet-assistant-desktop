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

#ifndef APPCOMPONENTS_H
#define APPCOMPONENTS_H

#include "db.h"
#include "rhymelistmodel.h"
#include "thesauruslistmodel.h"
#include "definitionlistmodel.h"
#include "composerviewmodel.h"
#include "favoritelistmodel.h"
#include "mainviewmodel.h"
#include "ttsviewmodel.h"
#include "style.h"

#include <QObject>

class AppComponents : public QObject
{
    Q_OBJECT
public:
    explicit AppComponents(Db *db, QObject *parent = nullptr);

private:
    RhymeRepository rhymeRepository;
    RhymeViewModel rhymeViewModel;
public:
    RhymeListModel rhymeListModel;
private:
    ThesaurusRepository thesaurusRepository;
    ThesaurusViewModel thesaurusViewModel;
public:
    ThesaurusListModel thesaurusListModel;
private:
    DefinitionRepository definitionRepository;
    DefinitionViewModel definitionViewModel;
public:
    DefinitionListModel definitionListModel;
private:
    PoemRepository poemRepository;
public:
    ComposerViewModel composerViewModel;
    TtsViewModel ttsViewModel;
private:
    FavoriteRepository favoriteRepository;
public:
    FavoriteListModel favoriteListModel;
    Style style;
    MainViewModel mainViewModel;
};

#endif // APPCOMPONENTS_H
