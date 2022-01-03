#include "db.h"
#include "mainviewmodel.h"

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

    QTranslator translator;
    if (translator.load(":/i18n/PoetAssistant_en_US")) {
        a.installTranslator(&translator);
    }
    Db db;
    QFuture<void> future = db.openDb(a);
    future.waitForFinished(); // TODO
    ThesaurusRepository thesaurusRepository(&db);
    ThesaurusListModel thesaurusListModel(&thesaurusRepository);
    DefinitionRepository definitionRepository(&db);
    DefinitionListModel definitionsListModel(&definitionRepository);
    MainViewModel mainViewModel(&thesaurusListModel, &definitionsListModel);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&mainViewModel));
    engine.rootContext()->setContextProperty("definitionsListModel", QVariant::fromValue(&definitionsListModel));
    engine.rootContext()->setContextProperty("thesaurusListModel", QVariant::fromValue(&thesaurusListModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
