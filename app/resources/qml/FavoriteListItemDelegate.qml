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
import QtQuick.Layouts

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    height: 48
    onClicked: {
        contextMenu.popup()
    }
    WordContextMenu {
        id: contextMenu
        word: model.favorite
    }
    contentItem: Rectangle {
        anchors.fill: parent
        color: Style.background
        RowLayout {
            spacing: 0
            FavoriteIcon {
                wordView: wordView
                Layout.leftMargin: 16
            }
            Text {
                id: wordView
                color: Style.primaryText
                text: model.favorite
                Layout.fillWidth: true
            }
        }
    }
}
