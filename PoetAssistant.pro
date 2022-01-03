QT       += core gui quick quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql concurrent core

CONFIG += c++11 app_bundl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCE_DIR=src
SOURCES += \
    $${SOURCE_DIR}/main/app/main.cpp \
    $${SOURCE_DIR}/main/repository/db.cpp \
    $${SOURCE_DIR}/main/repository/definitionentity.cpp \
    $${SOURCE_DIR}/main/repository/definitionrepository.cpp \
    $${SOURCE_DIR}/main/repository/thesaurusentity.cpp \
    $${SOURCE_DIR}/main/repository/thesaurusrepository.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitiondisplaydata.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitionentitymapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitionlistmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/mainviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesaurusdisplaydata.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesaurusentitymapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesauruslistmodel.cpp

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
    $${SOURCE_DIR}/main/repository/db.h \
    $${SOURCE_DIR}/main/repository/definitionentity.h \
    $${SOURCE_DIR}/main/repository/definitionrepository.h \
    $${SOURCE_DIR}/main/repository/thesaurusentity.h \
    $${SOURCE_DIR}/main/repository/thesaurusrepository.h \
    $${SOURCE_DIR}/main/viewmodel/definitiondisplaydata.h \
    $${SOURCE_DIR}/main/viewmodel/definitionentitymapper.h \
    $${SOURCE_DIR}/main/viewmodel/definitionlistmodel.h \
    $${SOURCE_DIR}/main/viewmodel/mainviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/thesaurusdisplaydata.h \
    $${SOURCE_DIR}/main/viewmodel/thesaurusentitymapper.h \
    $${SOURCE_DIR}/main/viewmodel/thesauruslistmodel.h

INCLUDEPATH +=  \
    $${SOURCE_DIR}/main/repository \
    $${SOURCE_DIR}/main/viewmodel
