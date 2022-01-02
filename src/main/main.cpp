#include "mainviewmodel.h"
#include "definitionslistmodel.h"

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
    // TODO move somewhere else
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QTemporaryFile tmpFile(qApp);
    tmpFile.setFileTemplate("XXXXXX.db");
    if (tmpFile.open()) {
        QString tmp_filename=tmpFile.fileName();
        qDebug() << "temporary" << tmp_filename;

        QFile file(":/poet_assistant.db");
        if (file.open(QIODevice::ReadOnly)) {
            qint64 wrote = tmpFile.write(file.readAll());
            qDebug() << "Wrote " << wrote;
        } else {
            qDebug() << "Couldn't read db file " ;
        }
        tmpFile.close();
    }
    db.setDatabaseName(tmpFile.fileName());
    if (!db.open()) {
        qDebug() << "Couldn't open db";
    }
    DefinitionsListModel definitionsListModel(&db);
    MainViewModel mainViewModel(&definitionsListModel);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&mainViewModel));
    engine.rootContext()->setContextProperty("definitionsListModel", QVariant::fromValue(&definitionsListModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
