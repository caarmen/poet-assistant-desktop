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
#include "appcomponents.h"
#include "colortypeenum.h"
#include "nightmodeenum.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QTranslator>
#include <QtSvg>

void setupEngine(QQmlApplicationEngine &engine, AppComponents &components)
{
    qmlClearTypeRegistrations();
    qmlRegisterUncreatableType<ColorTypeEnum>("ColorType", 1, 0, "ColorType",
                                              "Not creatable as it is an enum type");
    qmlRegisterUncreatableType<NightModeEnum>("NightMode", 1, 0, "NightMode",
                                              "Not creatable as it is an enum type");
    qmlRegisterUncreatableType<StyleEnum>("Theme", 1, 0, "Theme",
                                          "Not creatable as it is an enum type");
    engine.rootContext()->setContextProperty("mainViewModel",
                                             QVariant::fromValue(&components.mainViewModel));
    engine.rootContext()->setContextProperty("rhymeListModel",
                                             QVariant::fromValue(&components.rhymeListModel));
    engine.rootContext()->setContextProperty("definitionsListModel",
                                             QVariant::fromValue(&components.definitionListModel));
    engine.rootContext()->setContextProperty("thesaurusListModel",
                                             QVariant::fromValue(&components.thesaurusListModel));
    engine.rootContext()->setContextProperty("composerViewModel",
                                             QVariant::fromValue(&components.composerViewModel));
    engine.rootContext()->setContextProperty("ttsViewModel",
                                             QVariant::fromValue(&components.ttsViewModel));
    engine.rootContext()->setContextProperty("favoriteListModel",
                                             QVariant::fromValue(&components.favoriteListModel));
    engine.rootContext()->setContextProperty("suggestionListModel",
                                             QVariant::fromValue(&components.suggestionListModel));
    engine.rootContext()->setContextProperty("preferencesViewModel",
                                             QVariant::fromValue(&components.preferencesViewModel));
    QString style = AppearanceRepository::getName(components.appearanceRepository.getStyle());
    QQuickStyle::setStyle(style);
    engine.rootContext()->setContextProperty("theme", style);
    engine.load(QUrl("qrc:/qml/main.qml"));
}

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    a.setOrganizationName("Poet Assistant");
    a.setOrganizationDomain("poetassistant.com");
    a.setApplicationName("Poet Assistant");
    a.setApplicationVersion(APP_VERSION);
    QSettings::setDefaultFormat(QSettings::IniFormat);

    QTranslator translator;
    if (translator.load(":/i18n/PoetAssistant_en_US")) {
        a.installTranslator(&translator);
    }
    Db db;
    QFuture<void> future = db.openDb();
    future.waitForFinished(); // TODO
    AppComponents components(&db);
    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    setupEngine(*engine, components);
    QObject context;
    QObject::connect(&components.appearanceRepository, &AppearanceRepository::styleChanged,
    &context, [ &context, &engine, &components] {
        engine->clearComponentCache();
        engine->deleteLater();
        QObject::connect(engine, &QObject::destroyed, &context, [&engine, &components]{
            engine = new QQmlApplicationEngine();
            setupEngine(*engine, components);
        });
    });
    // Prevent QML errors when closing the app
    // https://bugreports.qt.io/browse/QTBUG-81247?page=com.googlecode.jira-suite-utilities%3Atransitions-summary-tabpanel
    QObject::connect(&a, &QGuiApplication::aboutToQuit, &context, [&engine] {
        engine->deleteLater();
    });
    return a.exec();
}
