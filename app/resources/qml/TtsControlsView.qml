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
    id: zoneTts
    visible: ttsViewModel.isTtsSupported()
    height: childrenRect.height
    Layout.fillWidth: true
    Layout.margins: 16
    GridLayout {
        id: ttsControls
        columns: 2

        Text {
            color: Style.primaryText
            text: qsTr("label_locale");
        }
        ComboBox {
            palette.dark: Style.primary
            model: ttsViewModel.getAvailableLocaleNames()
            Component.onCompleted: currentIndex = indexOfValue(ttsViewModel.getLocaleName())
            onActivated: ttsViewModel.useLocale(currentValue)
        }
        Text {
            color: Style.primaryText
            text: qsTr("label_voice");
        }
        ComboBox {
            id: cbVoices
            palette.dark: Style.primary
            model: ttsViewModel.availableVoiceNames
            Component.onCompleted: currentIndex = indexOfValue(ttsViewModel.voiceName)
            onActivated: ttsViewModel.useVoice(currentValue)
            Connections {
                target: ttsViewModel
                function onVoiceNameChanged() {
                    cbVoices.currentIndex = cbVoices.indexOfValue(ttsViewModel.voiceName)
                }
            }
        }
    }
    Rectangle {
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
    GridLayout {
        columns: 2

        Text {
            color: Style.primaryText
            text: qsTr("label_pitch");
        }
        Slider {
            id: ttsPitch
            from: 0
            value: ttsViewModel.pitch
            to: 10
            onMoved: ttsViewModel.pitch = value
            Connections {
                target: ttsViewModel
                function onPitchChanged() {
                    ttsPitch.value = ttsViewModel.pitch
                }
            }
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
            onMoved: ttsViewModel.rate = value
            Connections {
                target: ttsViewModel
                function onRateChanged() {
                    ttsRate.value = ttsViewModel.rate
                }
            }
        }
    }
}
