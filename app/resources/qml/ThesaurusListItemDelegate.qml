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
        if (model.thesaurus.interactive) contextMenu.popup()
    }
    WordContextMenu {
        id: contextMenu
        word: model.thesaurus.text
    }
    contentItem: Rectangle {
        anchors.fill: parent
        color: Style.toColor(model.thesaurus.backgroundColor)
        RowLayout {
            anchors.fill: parent
            spacing: 0
            Layout.alignment: Qt.AlignVCenter
            anchors.leftMargin: 16
            FavoriteIcon {
                visible: model.thesaurus.interactive
                wordView: wordView
                Layout.alignment: Qt.AlignVCenter
            }
            Text {
                id: wordView
                color: Style.primaryText
                font.bold: model.thesaurus.bold
                font.italic: model.thesaurus.italic
                text: model.thesaurus.text
                Accessible.name: text
                Layout.fillWidth: true
            }
        }
    }
}
