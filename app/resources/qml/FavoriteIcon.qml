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
    property Text wordView
    color: "transparent"
    height:childrenRect.height
    width: childrenRect.width
    visible: wordView.text.length > 0
    ToolButton {
        id: favorite
        icon.source: mainViewModel.getFavoriteIcon(wordView.text)
        Accessible.name: qsTrId(mainViewModel.getFavoriteLabel(wordView.text))
        icon.color: Style.primary
        MouseArea {
            id: area
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked:  mainViewModel.toggleFavorite(wordView.text)
        }
        Connections {
            target: mainViewModel
            function onFavoritesChanged() {
                favorite.icon.source = mainViewModel.getFavoriteIcon(wordView.text)
            }
        }
        Connections {
            target: wordView
            function onTextChanged() {
                favorite.icon.source = mainViewModel.getFavoriteIcon(wordView.text)
            }
        }
    }
}
