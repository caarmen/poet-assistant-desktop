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

RowLayout{
    visible: ttsViewModel.isTtsSupported()
    height: childrenRect.height
    Layout.fillWidth: true
    Layout.margins: 16
    GridLayout {
        id: ttsControls
        columns: 2

        Text {
            color: Style.primaryText
            text: qsTr("label_voice");
        }
        ComboBox {
            palette.dark: Style.primary
            model: ttsViewModel.getAvailableVoiceNames()
            Component.onCompleted: currentIndex = indexOfValue(ttsViewModel.getVoiceName())
            onActivated: ttsViewModel.useVoice(currentValue)
        }
        Text {
            color: Style.primaryText
            text: qsTr("label_pitch");
        }
        Slider {
            id: ttsPitch
            from: 0
            value: 5
            to: 10
            onMoved: ttsViewModel.setPitch(value)
        }
        Text {
            color: Style.primaryText
            text: qsTr("label_rate");
        }
        Slider {
            id: ttsRate
            from: -0.5
            value: 0
            to: 1
            onMoved: ttsViewModel.setRate(value)
        }
    }
    Rectangle {
        id: zoneTts
        height: 58
        Layout.fillWidth: true
        color: Style.background
        ToolButton {
            icon.source: ttsViewModel.playButtonIcon
            icon.color: Style.primary
            icon.height: 32
            icon.width: 32
            anchors.centerIn: parent
            onClicked: {
                ttsViewModel.play(taPoem.selectedText || taPoem.text)
            }
        }
    }
    Item {
        width: ttsControls.width
        height: 1
    }
}
