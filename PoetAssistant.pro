QT       += core gui quick quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 app_bundl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCE_DIR=src
SOURCES += \
    $${SOURCE_DIR}/main/main.cpp

#HEADERS += \
#    $${SOURCE_DIR}/main/mainwindow.h

TRANSLATIONS += \
    resources/i18n/PoetAssistant_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/qml.qrc
