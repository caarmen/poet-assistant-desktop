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
#include "style.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QTranslator>
#include <QtSvg>

void setupEngine(QQmlApplicationEngine &engine, AppComponents &components, QString styleName) {
    qmlRegisterUncreatableType<ColorTypeEnum>("ColorType", 1, 0, "ColorType", "Not creatable as it is an enum type");
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&components.mainViewModel));
    engine.rootContext()->setContextProperty("rhymeListModel", QVariant::fromValue(&components.rhymeListModel));
    engine.rootContext()->setContextProperty("definitionsListModel", QVariant::fromValue(&components.definitionListModel));
    engine.rootContext()->setContextProperty("thesaurusListModel", QVariant::fromValue(&components.thesaurusListModel));
    engine.rootContext()->setContextProperty("composerViewModel", QVariant::fromValue(&components.composerViewModel));
    engine.rootContext()->setContextProperty("ttsViewModel", QVariant::fromValue(&components.ttsViewModel));
    engine.rootContext()->setContextProperty("favoriteListModel", QVariant::fromValue(&components.favoriteListModel));
    engine.rootContext()->setContextProperty("theme", styleName);
    engine.load(QUrl("qrc:/qml/main.qml"));
}

void clearEngine(QQmlApplicationEngine *engine) {
    engine->deleteLater();
    qmlClearTypeRegistrations();
}

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
    AppComponents components(&db);
    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    QString initialStyle = components.style.setStyle();
    setupEngine(*engine, components, initialStyle);
    QObject *context = new QObject();
    QObject::connect(&components.style, &Style::styleChanged, context, [
                     &engine,
                     &components
                     ](QString styleName) {
        qDebug() << "style changed to " << styleName;
        if (engine != nullptr) clearEngine(engine);
        QQuickStyle::setStyle(styleName);
        engine = new QQmlApplicationEngine();
        setupEngine(*engine, components, styleName);
    });
    return a.exec();
}
