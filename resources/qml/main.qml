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
            TextField {
                id: tfSearch
                color: Material.toolTextColor
                placeholderTextColor: Material.toolTextColor
                Layout.leftMargin: 16
                placeholderText: qsTr("hint_search")
                Layout.fillWidth: true
            }
            ToolButton {
                icon.name: "search"
                icon.source: "qrc:/images/search.svg"
                Layout.rightMargin: 16
                onClicked: mainViewModel.search(tfSearch.text)
            }
        }
    }

    footer: TabBar {
        // ...
    }

    ColumnLayout {
        width: parent.width
        height: parent.height
        RowLayout {
            width: parent.width
            TabBar {
                id: bar
                Layout.fillWidth: true
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
        RowLayout {
            StackLayout {
                currentIndex: bar.currentIndex
                Item {
                    id: rhymesTab
                }
                Item {
                    id: thesaurusTab
                }
                Item {
                    id: definitionsTab
                    ScrollView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.fill: parent
                        ListView {
                            id: definitionsList
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            anchors.fill: parent
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            model: definitionsListModel
                            delegate: DefinitionListItemDelegate {}
                        }
                    }
                }
            }
        }
    }
}