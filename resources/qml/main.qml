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
import QtQuick.Controls 2.4
import QtQuick 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("app_title")

    property bool useSystemMenu : Qt.platform.os === "osx"
    MenuBarComponent {
        id: classicMenuBar
        onMenuItemSelected: (menuItemId) => handleMenuItemSelected(menuItemId)
    }

    LabsMenuBarComponent {
        id: labsMenuBar
        onMenuItemSelected: (menuItemId) => handleMenuItemSelected(menuItemId)
    }

    function handleMenuItemSelected(menuItemId) {
        if (menuItemId === "about") {
            dlgAbout.show()
        }
    }

    Component.onCompleted: {
        useMaterial()
        color = Style.background
        if (useSystemMenu) {
            classicMenuBar.destroy()
        } else {
            menuBar = classicMenuBar
            labsMenuBar.destroy()
        }
    }
    function useMaterial() {
        Material.theme = Material.System
        Material.primary = Material.theme === Material.Light? "#607D8B" : "#879fab"
        Material.accent =  Material.theme === Material.Light? "#607D8B" : "#879fab"
        Material.background = Material.theme === Material.Light? "#fff" : "#111"
        Style.accent = Material.accent
        Style.background = Material.background
        Style.primary= Material.primary
        Style.primaryText = Material.primaryTextColor
        Style.surface = Material.theme === Material.Light? "#f6f7f9" : "#222"
    }

    function useUniversal() {
        Universal.theme = Universal.System
        Universal.accent =  Universal.theme === Universal.Light? "#607D8B" : "#879fab"
        Universal.background = Universal.theme === Universal.Light? "#fff" : "#000"
        Universal.foreground = Universal.theme === Universal.Light? "#000" : "#fff"
        Style.accent = Universal.accent
        Style.background = Universal.background
        Style.primary= Universal.accent
        Style.primaryText = Universal.foreground
        Style.surface = Universal.theme === Universal.Light? "#f6f7f9" : "#181818"
    }

    header: ToolBarView { }

    MainTabsView {}

    AboutDialog {
        id: dlgAbout
    }
}
