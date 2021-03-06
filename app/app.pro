# Copyright (c) 2022 - present Carmen Alvarez
#
# This file is part of Poet Assistant.
#
# Poet Assistant is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Poet Assistant is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
!defined(VERSION, var):VERSION= "0.0.0"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QT       += core gui quick quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql concurrent core svg xml

CONFIG += c++11 app_bundle lrelease embed_translations

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET=PoetAssistant
SOURCE_DIR=src
SOURCES += \
    $${SOURCE_DIR}/main/app/appcomponents.cpp \
    $${SOURCE_DIR}/main/app/main.cpp \
    $${SOURCE_DIR}/main/debug/refcounter.cpp \
    $${SOURCE_DIR}/main/repository/appearancerepository.cpp \
    $${SOURCE_DIR}/main/repository/db.cpp \
    $${SOURCE_DIR}/main/repository/definitionentity.cpp \
    $${SOURCE_DIR}/main/repository/definitionrepository.cpp \
    $${SOURCE_DIR}/main/repository/favoriterepository.cpp \
    $${SOURCE_DIR}/main/repository/poemrepository.cpp \
    $${SOURCE_DIR}/main/repository/rhymeentity.cpp \
    $${SOURCE_DIR}/main/repository/rhymerepository.cpp \
    $${SOURCE_DIR}/main/repository/suggestionentity.cpp \
    $${SOURCE_DIR}/main/repository/suggestionrepository.cpp \
    $${SOURCE_DIR}/main/repository/thesaurusentity.cpp \
    $${SOURCE_DIR}/main/repository/thesaurusrepository.cpp \
    $${SOURCE_DIR}/main/viewmodel/appearancemapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/composerviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitiondisplaydata.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitionentitymapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitionlistmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/definitionviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/favoritelistmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/mainviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/preferencesviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/rhymedisplaydata.cpp \
    $${SOURCE_DIR}/main/viewmodel/rhymeentitymapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/rhymelistmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/rhymeviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/suggestiondisplaydata.cpp \
    $${SOURCE_DIR}/main/viewmodel/suggestionlistmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/suggestionviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/suggesttionentitymapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesaurusdisplaydata.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesaurusentitymapper.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesauruslistmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/thesaurusviewmodel.cpp \
    $${SOURCE_DIR}/main/viewmodel/ttsviewmodel.cpp \

TRANSLATIONS += \
    resources/i18n/PoetAssistant_en_US.ts

CONFIG += lrelease
QMAKE_LRELEASE_FLAGS += -idbased
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/qml.qrc

HEADERS += \
    $${SOURCE_DIR}/main/app/appcomponents.h \
    $${SOURCE_DIR}/main/debug/refcounter.h \
    $${SOURCE_DIR}/main/repository/appearancerepository.h \
    $${SOURCE_DIR}/main/repository/db.h \
    $${SOURCE_DIR}/main/repository/definitionentity.h \
    $${SOURCE_DIR}/main/repository/definitionrepository.h \
    $${SOURCE_DIR}/main/repository/favoriterepository.h \
    $${SOURCE_DIR}/main/repository/poemrepository.h \
    $${SOURCE_DIR}/main/repository/rhymeentity.h \
    $${SOURCE_DIR}/main/repository/rhymerepository.h \
    $${SOURCE_DIR}/main/repository/suggestionentity.h \
    $${SOURCE_DIR}/main/repository/suggestionrepository.h \
    $${SOURCE_DIR}/main/repository/thesaurusentity.h \
    $${SOURCE_DIR}/main/repository/thesaurusrepository.h \
    $${SOURCE_DIR}/main/viewmodel/appearancemapper.h \
    $${SOURCE_DIR}/main/viewmodel/colortypeenum.h \
    $${SOURCE_DIR}/main/viewmodel/composerviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/definitiondisplaydata.h \
    $${SOURCE_DIR}/main/viewmodel/definitionentitymapper.h \
    $${SOURCE_DIR}/main/viewmodel/definitionlistmodel.h \
    $${SOURCE_DIR}/main/viewmodel/definitionviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/favoritelistmodel.h \
    $${SOURCE_DIR}/main/viewmodel/mainviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/nightmodeenum.h \
    $${SOURCE_DIR}/main/viewmodel/preferencesviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/rhymedisplaydata.h \
    $${SOURCE_DIR}/main/viewmodel/rhymeentitymapper.h \
    $${SOURCE_DIR}/main/viewmodel/rhymelistmodel.h \
    $${SOURCE_DIR}/main/viewmodel/rhymeviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/styleenum.h \
    $${SOURCE_DIR}/main/viewmodel/suggestiondisplaydata.h \
    $${SOURCE_DIR}/main/viewmodel/suggestionentitymapper.h \
    $${SOURCE_DIR}/main/viewmodel/suggestionlistmodel.h \
    $${SOURCE_DIR}/main/viewmodel/suggestionviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/thesaurusdisplaydata.h \
    $${SOURCE_DIR}/main/viewmodel/thesaurusentitymapper.h \
    $${SOURCE_DIR}/main/viewmodel/thesauruslistmodel.h \
    $${SOURCE_DIR}/main/viewmodel/thesaurusviewmodel.h \
    $${SOURCE_DIR}/main/viewmodel/ttsviewmodel.h \

INCLUDEPATH +=  \
    $${SOURCE_DIR}/main/debug \
    $${SOURCE_DIR}/main/repository \
    $${SOURCE_DIR}/main/viewmodel

BUILD_DIR=build
TMP_DIR=$${BUILD_DIR}/tmp

MOC_DIR=$${TMP_DIR}/moc
RCC_DIR=$${TMP_DIR}/rcc
UI_DIR=$${TMP_DIR}/ui
OBJECTS_DIR=$${TMP_DIR}/obj

DESTDIR=$${BUILD_DIR}/out

RC_ICONS = ../deploy/config/icon.ico
ICON = ../deploy/icon.icns

# Package the database file
BUILD_DIR=$$shadowed($$PWD)/build/out/
DB_SOURCE_PATH = $$shell_path($$PWD/resources/poet_assistant.db)
macx{
    DB_TARGET_FOLDER = $$shell_path($${BUILD_DIR}/$${TARGET}.app/Contents/Resources)
    DEFINES += DB_FOLDER=\\\"../Resources\\\"
} else {
    DB_TARGET_FOLDER = $$shell_path($${BUILD_DIR})
    DEFINES += DB_FOLDER=\\\"\\\"
}
dbTargetFolder.target = $${DB_TARGET_FOLDER}
win32 {
    dbTargetFolder.commands = $(CHK_DIR_EXISTS) $${DB_TARGET_FOLDER} $(MKDIR) $${DB_TARGET_FOLDER}
} else {
    dbTargetFolder.commands = $(MKDIR) $${DB_TARGET_FOLDER}
}

dbTargetFile.depends = dbTargetFolder
dbTargetFile.target = $${DB_TARGET_FOLDER}/poet_assistant.db
dbTargetFile.commands = $(COPY_FILE) $${DB_SOURCE_PATH} $${DB_TARGET_FOLDER}
QMAKE_EXTRA_TARGETS += dbTargetFolder dbTargetFile
PRE_TARGETDEPS += $${dbTargetFile.target}

# TextToSpeech
QTSPEECH_DIR=$$PWD/../lib/qtspeech
LIBS += -L$${QTSPEECH_DIR}/lib/  -lQt6TextToSpeech
INCLUDEPATH += $${QTSPEECH_DIR}/include
macx:{
    TARGET_PATH=$${BUILD_DIR}/$${TARGET}.app

    QtSpeechOsxPlugin.target = $${TARGET_PATH}/Contents/Plugins/texttospeech/libqtexttospeech_speechosx.dylib
    QtSpeechOsxPlugin.commands = \
            mkdir -p $${TARGET_PATH}/Contents/Plugins && \
            cp -pr $${QTSPEECH_DIR}/plugins/* $${TARGET_PATH}/Contents/Plugins/.
    PRE_TARGETDEPS += $${QtSpeechOsxPlugin.target}
    QMAKE_EXTRA_TARGETS += QtSpeechOsxPlugin
}
win32:{
    BUILD_DIR=$$shadowed($$PWD)/build/out/
    QtSpeechWinPlugin.target = $${BUILD_DIR}/texttospeech/qtexttospeech_sapi.dll
    QtSpeechWinPlugin.commands = \
            md $$shell_path($${BUILD_DIR}\texttospeech) && \
            copy $$shell_path($${QTSPEECH_DIR}\plugins\texttospeech\qtexttospeech_sapi.dll) $$shell_path($${BUILD_DIR}\texttospeech)
    PRE_TARGETDEPS += $${QtSpeechWinPlugin.target}
    QMAKE_EXTRA_TARGETS += QtSpeechWinPlugin
}
