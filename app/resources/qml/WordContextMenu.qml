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
import QtQuick
import QtQuick.Controls

Menu {
    property string word
    id: contextMenu
    enum Tabs {
        RHYMER, THESAURUS, DICTIONARY
    }

    MenuItem {
        text: word
        enabled: false
        background: Rectangle { color: Style.surface }
    }
    MenuSeparator {
        background: Rectangle { color: Style.surface }
    }
    Loader {
        sourceComponent: menuItem
        property string iconSource: "copy"
        property string label: "context_menu_copy"
        function menuAction() {
            mainViewModel.copy(word)
        }
    }
    Loader {
        sourceComponent: menuItem
        property string iconSource: "speak"
        property string label: "context_menu_speak"
        function menuAction() {
            ttsViewModel.play(word)
        }
    }
    Loader {
        sourceComponent: menuItem
        property string iconSource: "ic_rhymer"
        property string label: "context_menu_rhymer"
        function menuAction() {
            bar.currentIndex = Tabs.Tabs.RHYMER
            mainViewModel.searchRhymes(word)
        }
    }
    Loader {
        sourceComponent: menuItem
        property string iconSource: "ic_thesaurus"
        property string label: "context_menu_thesaurus"
        function menuAction() {
            bar.currentIndex = Tabs.Tabs.THESAURUS
            mainViewModel.searchThesaurus(word)
        }
    }
    Loader {
        sourceComponent: menuItem
        property string iconSource: "ic_definitions"
        property string label: "context_menu_dictionary"
        function menuAction() {
            bar.currentIndex = Tabs.Tabs.DICTIONARY
            mainViewModel.searchDefinitions(word)
        }
    }

    Component {
        id: menuItem
        MenuItem {
            background: MenuItemBackground {}
            icon.source: `qrc:/images/${iconSource}.svg`
            icon.color: Style.primary
            text: qsTrId(label)
            onTriggered: {
                menuAction()
                contextMenu.close()
            }
        }
    }
}
