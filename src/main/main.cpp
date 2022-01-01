#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QTranslator translator;
    if (translator.load(":/i18n/PoetAssistant_en_US")) {
        a.installTranslator(&translator);
    } else {
        qDebug() << "Failed to load translation file";
    }

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");
    engine.load(QUrl("qrc:/qml/main.qml"));
    return a.exec();
}
