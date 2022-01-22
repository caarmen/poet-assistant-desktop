/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/
import QtQuick.Controls 2.4
import QtQuick 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ColumnLayout {
    anchors.fill: parent
    Rectangle {
        Layout.preferredHeight: childrenRect.height
        Layout.fillWidth: true
        TabBar {
            Material.background: Style.surface
            id: bar
            width: parent.width
            TabButton {
                icon.source: "qrc:/images/ic_rhymer.svg"
                text: qsTr("tab_rhymes")
            }
            TabButton {
                icon.source: "qrc:/images/ic_thesaurus.svg"
                text: qsTr("tab_thesaurus")
            }
            TabButton {
                icon.source: "qrc:/images/ic_definitions.svg"
                text: qsTr("tab_definitions")
            }
            TabButton {
                icon.source: "qrc:/images/ic_composer.svg"
                text: qsTr("tab_composer")
            }
            TabButton {
                icon.source: "qrc:/images/star.svg"
                text: qsTr("tab_favorites")
            }
        }
    }
    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        color: Style.background
        StackLayout {
            anchors.fill: parent
            currentIndex: bar.currentIndex
            Item {
                id: rhymesTab
                RhymeTabView {}
            }
            Item {
                id: thesaurusTab
                ThesaurusTabView {}
            }
            Item {
                id: definitionsTab
                DictionaryTabView {}
            }
            Item {
                id: composerTab
                ComposerTabView{}
            }
            Item {
                id: favoritesTab
                FavoriteTabView{}
            }
        }
    }
}
