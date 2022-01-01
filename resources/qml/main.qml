import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    width: 500
    height: 500
    visible: true

    menuBar: MenuBar {
        background: Rectangle { color: Material.toolBarColor }
        Menu { MenuItem {} }
        Menu { MenuItem {} }
    }

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            TextField {
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
            }
        }
    }

    footer: TabBar {
        // ...
    }

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

    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: rhymesTab
        }
        Item {
            id: thesaurusTab
        }
        Item {
            id: definitionsTab
        }
    }
}
