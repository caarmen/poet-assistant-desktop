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
#include "db.h"
#include "mainviewmodel.h"
#include "favoritelistmodel.h"
#include "composerviewmodel.h"
#include "colortypeenum.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QTranslator>
#include <QtSvg>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    a.setOrganizationName("Poet Assistant");
    a.setOrganizationDomain("poetassistant.com");
    a.setApplicationName("Poet Assistant");
    a.setApplicationVersion(APP_VERSION);

    QTranslator translator;
    if (translator.load(":/i18n/PoetAssistant_en_US")) {
        a.installTranslator(&translator);
    }
    Db db;
    QFuture<void> future = db.openDb();
    future.waitForFinished(); // TODO
    RhymeRepository rhymeRepository(&db);
    RhymeViewModel rhymeViewModel(&rhymeRepository);
    RhymeListModel rhymeListModel(&rhymeViewModel);
    ThesaurusRepository thesaurusRepository(&db);
    ThesaurusViewModel thesaurusViewModel(&thesaurusRepository);
    ThesaurusListModel thesaurusListModel(&thesaurusViewModel);
    DefinitionRepository definitionRepository(&db);
    DefinitionViewModel definitionViewModel(&definitionRepository);
    DefinitionListModel definitionsListModel(&definitionViewModel);
    PoemRepository poemRepository;
    ComposerViewModel composerViewModel(&poemRepository);
    FavoriteRepository favoriteRepository;
    FavoriteListModel favoriteListModel(&favoriteRepository);
    MainViewModel mainViewModel(
                &rhymeListModel,
                &thesaurusListModel,
                &definitionsListModel,
                &favoriteRepository);

    QQmlApplicationEngine engine;
    qmlRegisterUncreatableType<ColorTypeEnum>("ColorType", 1, 0, "ColorType", "Not creatable as it is an enum type");
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&mainViewModel));
    engine.rootContext()->setContextProperty("rhymeListModel", QVariant::fromValue(&rhymeListModel));
    engine.rootContext()->setContextProperty("definitionsListModel", QVariant::fromValue(&definitionsListModel));
    engine.rootContext()->setContextProperty("thesaurusListModel", QVariant::fromValue(&thesaurusListModel));
    engine.rootContext()->setContextProperty("composerViewModel", QVariant::fromValue(&composerViewModel));
    engine.rootContext()->setContextProperty("favoriteListModel", QVariant::fromValue(&favoriteListModel));
    engine.rootContext()->setContextProperty("theme", QQuickStyle::name());
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
