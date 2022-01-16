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
//import QtQuick.Controls.Universal 2.12

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("app_title")

    Component.onCompleted: {
        useMaterial()
        color = Style.background
    }
    function useMaterial() {
        Material.theme = Material.System
        Material.primary = Material.theme === Material.Light? "#607D8B" : "#879fab"
        Material.accent =  Material.theme === Material.Light? "#607D8B" : "#879fab"
        Material.background = Material.theme === Material.Light? "#fff" : "#000"
        Style.accent = Material.accent
        Style.background = Material.background
        Style.primary= Material.primary
        Style.primaryText = Material.primaryTextColor
        Style.surface = Material.theme === Material.Light? "#f6f7f9" : "#181818"
    }

    function useUniversal() {
        Universal.theme = Universal.System
        Universal.accent =  Universal.theme === Universal.Light? "#607D8B" : "#879fab"
        Universal.background = Universal.theme === Universal.Light? "#fff" : "#000"
        Universal.foreground = Universal.theme === Universal.Light? "#000" : "#fff"
        Style.accent = Universal.accent
        Style.background = Universal.background
        Style.primary= Universal.accent
        Style.primaryText = Universal.foreground
        Style.surface = Universal.theme === Universal.Light? "#f6f7f9" : "#181818"
    }

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Rectangle {
                Layout.preferredHeight: childrenRect.height
                Layout.fillWidth: true
                Layout.topMargin: 4
                Layout.bottomMargin: 4
                Layout.leftMargin: 56
                Layout.rightMargin: 56
                color: Style.background
                TextField {
                    id: tfSearch
                    width: parent.width
                    selectByMouse: true
                    leftPadding: 48
                    rightPadding: 48
                    topPadding: 12
                    bottomPadding: 12
                    color: Style.primaryText
                    anchors.verticalCenter: parent.verticalCenter
                    background: Rectangle {
                        color: Style.surface
                        Layout.fillWidth: true
                    }
                    placeholderText: qsTr("hint_search")
                    Keys.onReleased: event => {
                        if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                            mainViewModel.search(text)
                        }
                    }
                    onTextChanged: {
                        btnSearch.enabled = length > 0
                        btnClose.visible = length > 0
                    }
                }
                ToolButton {
                    id: btnSearch
                    enabled: false
                    icon.color: Style.primaryText
                    icon.source: "qrc:/images/search.svg"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    onClicked:  mainViewModel.search(tfSearch.text)
                }
                ToolButton {
                    id: btnClose
                    visible: false
                    icon.color: Style.primaryText
                    icon.source: "qrc:/images/close.svg"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    onClicked: tfSearch.clear()
                }
            }
        }
    }

    footer: TabBar {
        // ...
    }

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
                    text: qsTr("tab_rhymes")
                }
                TabButton {
                    text: qsTr("tab_thesaurus")
                }
                TabButton {
                    text: qsTr("tab_definitions")
                }
                TabButton {
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
                    id: favoritesTab
                    FavoriteTabView{}
                }
            }
        }
    }
}
