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

MenuBar {
    signal menuItemSelected(string id)
    palette.button: Style.background
    palette.buttonText: Style.primaryText
    palette.mid: Style.surface
    Menu {
        title: qsTrId("menu_file")
        MenuItem {
            text: qsTrId("menu_file_new")
            background: MenuItemBackground {}
            onTriggered: menuItemSelected("new")
        }
        MenuItem {
            text: qsTrId("menu_file_open")
            background: MenuItemBackground {}
            onTriggered: menuItemSelected("open")
        }
        MenuItem {
            text: qsTrId("menu_file_saveas")
            background: MenuItemBackground {}
            onTriggered: menuItemSelected("saveas")
        }
        MenuSeparator {
            background: Rectangle { color: Style.surface }
        }
        MenuItem {
            text: qsTrId("menu_file_quit")
            background: MenuItemBackground {}
            onTriggered: menuItemSelected("quit")
        }
    }
    Menu {
        title: qsTrId("menu_help")
        MenuItem {
            text: qsTrId("menu_help_about")
            background: MenuItemBackground {}
            onTriggered: menuItemSelected("about")
        }
    }
}
