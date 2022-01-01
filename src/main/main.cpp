#include "mainviewmodel.h"

#include <QGuiApplication>
#include <QLocale>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QTranslator translator;
    if (translator.load(":/i18n/PoetAssistant_en_US")) {
        a.installTranslator(&translator);
    }
    MainViewModel mainViewModel;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainViewModel", QVariant::fromValue(&mainViewModel));
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
