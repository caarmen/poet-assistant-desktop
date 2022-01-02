#include "db.h"
#include "mainviewmodel.h"
#include "definitionslistmodel.h"
#include "definitionrepository.h"

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
    QThreadPool dbThreadPool;
    dbThreadPool.setMaxThreadCount(1);
    QFuture<QSqlDatabase> future = Db::openDb(dbThreadPool, a);
    future.waitForFinished(); // TODO
    QSqlDatabase db = future.result();
    DefinitionRepository definitionRepository(&dbThreadPool, &db);
    DefinitionsListModel definitionsListModel(&definitionRepository);
    MainViewModel mainViewModel(&definitionsListModel);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&mainViewModel));
    engine.rootContext()->setContextProperty("definitionsListModel", QVariant::fromValue(&definitionsListModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
