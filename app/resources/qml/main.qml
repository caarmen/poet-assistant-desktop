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

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTrId("app_title")
    SystemPalette {
        id: systemPalette
        onPaletteChanged: applyTheme()
    }

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
        } else if (menuItemId == "quit") {
            Qt.quit()
        }

        tabs.handleMenuItemSelected(menuItemId)
    }

    function applyTheme() {
        const isDayMode = systemPalette.window.hsvValue > systemPalette.windowText.hsvValue
        if (theme === "Material") {
            Style.useMaterial(Material, Material.Light, Material.Dark, isDayMode)
        } else if (theme === "Universal") {
            Style.useUniversal(Universal, Universal.Light, Universal.Dark, isDayMode)
        } else {
            Style.useFusion(palette, isDayMode)
        }
        color = Style.background
        tabs.applyTheme()
    }

    Component.onCompleted: {
        applyTheme()
        if (useSystemMenu) {
            classicMenuBar.destroy()
        } else {
            menuBar = classicMenuBar
            labsMenuBar.destroy()
        }
    }

    header: ToolBarView {
        id: toolBarView
        onSearched: tabs.onSearched()
    }

    MainTabsView {
        id: tabs
        onToastTextChanged: (text) => toast.show(text)
    }

    SuggestionListView {
        x: toolBarView.textFieldLeftEdge
        onSuggestionSelected: (suggestion) => toolBarView.submitText(suggestion)
    }

    AboutDialog {
        id: dlgAbout
    }
    Toast {
        id: toast
        x: (parent.width - width)/2
        y: parent.height - height - 16
    }
}
