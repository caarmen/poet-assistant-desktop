import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    width: 500
    height: 500
    visible: true
    title: qsTr("app_title")

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Rectangle {
                Layout.preferredHeight: childrenRect.height
                Layout.fillWidth: true
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
                        Layout.fillWidth: true
                    }
                    placeholderText: qsTr("hint_search")
                    Keys.onReleased: {
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
            }
        }
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
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
            }
        }
    }
}
