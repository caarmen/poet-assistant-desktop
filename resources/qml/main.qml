import QtQuick.Controls 2.4
import QtQuick 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    color: Material.backgroundColor
    width: 500
    height: 500
    visible: true
    title: qsTr("app_title")

    Material.theme: Material.System
    Material.primary: Material.theme === Material.Light? "#607D8B" : "#879fab"
    Material.accent: Material.theme === Material.Light? "#607D8B" : "#879fab"
    Material.background : Material.theme === Material.Light? "#fff" : "#000"
    Component.onCompleted: {
        Style.surface = Material.theme === Material.Light? "#f6f7f9" : "#181818"
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
                color: Material.backgroundColor
                TextField {
                    id: tfSearch
                    width: parent.width
                    selectByMouse: true
                    leftPadding: 48
                    rightPadding: 48
                    topPadding: 12
                    bottomPadding: 12
                    color: Material.primaryTextColor
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
                    icon.color: Material.primaryTextColor
                    icon.source: "qrc:/images/search.svg"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    onClicked:  mainViewModel.search(tfSearch.text)
                }
                ToolButton {
                    id: btnClose
                    visible: false
                    icon.color: Material.primaryTextColor
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
            color: Material.backgroundColor
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
