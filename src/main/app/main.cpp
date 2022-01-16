#include "db.h"
#include "mainviewmodel.h"
#include "favoritelistmodel.h"
#include "colortypeenum.h"

#include <QGuiApplication>
#include <QLocale>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QTranslator>
#include <QtSql>


int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    a.setOrganizationName("Poet Assistant");
    a.setOrganizationDomain("poetassistant.com");
    a.setApplicationName("Poet Assistant");

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
    FavoriteRepository favoriteRepository;
    FavoriteListModel favoriteListModel(&favoriteRepository);
    MainViewModel mainViewModel(&rhymeListModel, &thesaurusListModel, &definitionsListModel, &favoriteRepository);

    QQmlApplicationEngine engine;
    qmlRegisterUncreatableType<ColorTypeEnum>("ColorType", 1, 0, "ColorType", "Not creatable as it is an enum type");
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&mainViewModel));
    engine.rootContext()->setContextProperty("rhymeListModel", QVariant::fromValue(&rhymeListModel));
    engine.rootContext()->setContextProperty("definitionsListModel", QVariant::fromValue(&definitionsListModel));
    engine.rootContext()->setContextProperty("thesaurusListModel", QVariant::fromValue(&thesaurusListModel));
    engine.rootContext()->setContextProperty("favoriteListModel", QVariant::fromValue(&favoriteListModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
