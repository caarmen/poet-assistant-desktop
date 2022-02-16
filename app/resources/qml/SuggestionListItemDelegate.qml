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
    background: Rectangle { color: Style.surface}
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    height: 48
    contentItem:  RowLayout {
        spacing: 0
        anchors.leftMargin: 16
        Icon { source: model.suggestion.icon }
        Text {
            color: Style.primaryText
            text: model.suggestion.word
            horizontalAlignment: Text.AlignLeft
            Layout.fillWidth: true
        }
    }
}
