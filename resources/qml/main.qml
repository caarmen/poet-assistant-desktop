import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    width: 500
    height: 500
    visible: true

    menuBar: MenuBar {
        Menu { MenuItem {} }
        Menu { MenuItem {} }
    }

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {}
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
