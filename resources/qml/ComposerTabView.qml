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
import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15

ColumnLayout {
    height: parent.height
    width: parent.width
    ScrollView {
        Layout.fillHeight: true
        Layout.fillWidth: true
        clip: true
        TextArea{
            id: taPoem;
            background: Rectangle {
                color: Style.surface
            }
            color: Style.primaryText
            selectByMouse: true
            padding: 16
            placeholderText: qsTr("hint_compose")
            onTextChanged: {
                composerViewModel.writePoem(text)
            }
        }
    }
    Rectangle {
        height: 24
        Layout.fillWidth: true
        color: Style.background
        Text {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 16
            text: qsTr(composerViewModel.savedState)
            color: Style.primaryText
        }
    }
    Component.onCompleted: {
        taPoem.text = composerViewModel.readPoem()
    }
}
