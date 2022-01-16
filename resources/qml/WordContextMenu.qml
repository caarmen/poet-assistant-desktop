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
