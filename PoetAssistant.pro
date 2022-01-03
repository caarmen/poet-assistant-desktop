QT       += core gui quick quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql concurrent core

CONFIG += c++11 app_bundl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCE_DIR=src
SOURCES += \
    $${SOURCE_DIR}/main/main.cpp \
    $${SOURCE_DIR}/main/definitionrepository.cpp \
    $${SOURCE_DIR}/main/db.cpp \
    $${SOURCE_DIR}/main/definitiondisplaydata.cpp \
    $${SOURCE_DIR}/main/mainviewmodel.cpp \
    $${SOURCE_DIR}/main/definitionlistmodel.cpp \
    $${SOURCE_DIR}/main/definitionentity.cpp \
    $${SOURCE_DIR}/main/definitionentitymapper.cpp

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

HEADERS += \
    $${SOURCE_DIR}/main/definitionrepository.h \
    $${SOURCE_DIR}/main/db.h \
    $${SOURCE_DIR}/main/definitiondisplaydata.h \
    $${SOURCE_DIR}/main/mainviewmodel.h \
    $${SOURCE_DIR}/main/definitionlistmodel.h \
    $${SOURCE_DIR}/main/definitionentity.h \
    $${SOURCE_DIR}/main/definitionentitymapper.h
