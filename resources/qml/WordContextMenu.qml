import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15

Menu {
    property string word
    id: contextMenu
    MenuItem {
        text: word
        enabled: false
        background: Rectangle { color: Style.surface }
    }
    MenuSeparator {
        background: Rectangle { color: Style.surface }
    }
    MenuItem {
        background: Rectangle { color: Style.surface }
        text: qsTr("context_menu_rhymer")
        onTriggered: {
            bar.currentIndex = 0
            mainViewModel.searchRhymes(word)
        }
    }
    MenuItem {
        background: Rectangle { color: Style.surface }
        text: qsTr("context_menu_thesaurus")
        onTriggered: {
            bar.currentIndex = 1
            mainViewModel.searchThesaurus(word)
        }
    }
    MenuItem {
        background: Rectangle { color: Style.surface }
        text: qsTr("context_menu_dictionary")
        onTriggered: {
            bar.currentIndex = 2
            mainViewModel.searchDefinitions(word)
        }
    }
}
