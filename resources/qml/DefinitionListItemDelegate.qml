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
import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    background: Rectangle { color: Style.background }
    contentItem:  RowLayout {
        spacing: 0
        Rectangle {
            color: "transparent"
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredWidth: childrenRect.width + 16
            Layout.fillHeight: true
            Text {
                color: Style.primaryText
                text: model.definition.part_of_speech
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        Rectangle {
            color: "transparent"
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredHeight: childrenRect.height
            Layout.fillWidth: true
            Text {
                color: Style.primaryText
                text: model.definition.definition
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                wrapMode: Text.WordWrap
            }
        }
    }
}
