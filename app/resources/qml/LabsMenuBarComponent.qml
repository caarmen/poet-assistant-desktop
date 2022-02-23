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
import Qt.labs.platform
import QtQuick
import QtQuick.Controls

MenuBar {
    signal menuItemSelected(string id)
    Menu {
        title: qsTrId("menu_file")
        MenuItem {
            text: qsTrId("menu_edit_preferences")
            role: MenuItem.PreferencesRole
            onTriggered: menuItemSelected("preferences")
        }
        MenuItem {
            text: qsTrId("menu_file_new")
            onTriggered: menuItemSelected("new")
        }
        MenuItem {
            text: qsTrId("menu_file_open")
            onTriggered: menuItemSelected("open")
        }
        MenuItem {
            text: qsTrId("menu_file_saveas")
            onTriggered: menuItemSelected("saveas")
        }
        MenuItem {
            separator: true
        }
        MenuItem {
            text: qsTrId("menu_file_quit")
            role: MenuItem.QuitRole
            onTriggered: menuItemSelected("quit")
        }
    }
    Menu {
        title: qsTrId("menu_help")
        MenuItem {
            text: qsTrId("menu_help_about")
            onTriggered: menuItemSelected("about")
        }
    }
}
