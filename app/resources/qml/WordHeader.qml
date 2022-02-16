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

Rectangle {
    property string word
    onWordChanged: {
        contextMenu.word = word
    }

    color: Style.background
    height: 48
    width: parent.width
    visible: word.length > 0
    FavoriteIcon {
        id: favoriteIcon
        wordView: wordView
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
    }
    WordContextMenu {
        id: contextMenu
    }
    Text {
        id: wordView
        x: 16
        color: Style.primaryText
        font.bold: true
        text: word
        anchors.left: favoriteIcon.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked:  contextMenu.popup()
        }
    }
}
