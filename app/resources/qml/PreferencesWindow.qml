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

Window {
    visible: false
    width: contentItem.childrenRect.width + 32
    height: contentItem.childrenRect.height + 32
    color: Style.background
    title: qsTrId("preferences_title")

    Rectangle {
        color: Style.background
        anchors.centerIn: parent
        width: childrenRect.width
        height: childrenRect.height

        GridLayout {
            columns: 2
            Text {
                text:  qsTrId("preferences_label_history_enabled")
                color: Style.primaryText
            }

            Switch {
                id: switchHistoryEnabled
                onCheckedChanged: preferencesViewModel.historyEnabled = checked
                Component.onCompleted: checked = preferencesViewModel.historyEnabled
            }
        }
    }
}
