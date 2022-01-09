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
                selectByMouse: true
                color: Material.toolTextColor
                placeholderTextColor: Material.toolTextColor
                Layout.leftMargin: 16
                placeholderText: qsTr("hint_search")
                Layout.fillWidth: true
                Keys.onReleased: {
                    if (event.key === Qt.Key_Return) {
                        mainViewModel.search(text)
                    }
                }
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
