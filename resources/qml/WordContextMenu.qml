import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

Menu {
    property string word
    id: contextMenu
    MenuItem {
        text: word
        enabled: false
    }
    MenuSeparator {}
    MenuItem {
        text: qsTr("context_menu_rhymer")
        onTriggered: {
            bar.currentIndex = 0
            mainViewModel.searchRhymes(word)
        }
    }
    MenuItem {
        text: qsTr("context_menu_thesaurus")
        onTriggered: {
            bar.currentIndex = 1
            mainViewModel.searchThesaurus(word)
        }
    }
    MenuItem {
        text: qsTr("context_menu_dictionary")
        onTriggered: {
            bar.currentIndex = 2
            mainViewModel.searchDefinitions(word)
        }
    }
}
