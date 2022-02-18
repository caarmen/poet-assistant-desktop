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
            text: qsTrId("label_locale");
            Accessible.name: text
        }
        ComboBox {
            palette.dark: Style.primary // indicator
            palette.window: Style.surface
            palette.buttonText: Style.primaryText
            palette.button: Style.surface
            palette.text: Style.primaryText
            palette.highlightedText: Style.primary
            model: ttsViewModel.getAvailableLocaleNames()
            Component.onCompleted: currentIndex = indexOfValue(ttsViewModel.getLocaleName())
            onActivated: ttsViewModel.useLocale(currentValue)
        }
        Text {
            color: Style.primaryText
            text: qsTrId("label_voice");
            Accessible.name: text
        }
        ResizingComboBox {
            id: cbVoices
            palette.dark: Style.primary // indicator
            palette.window: Style.surface
            palette.buttonText: Style.primaryText
            palette.button: Style.surface
            palette.text: Style.primaryText
            palette.highlightedText: Style.primary
            model: ttsViewModel.availableVoiceNames
            Component.onCompleted: reselectVoice()
            onActivated: ttsViewModel.useVoice(currentValue)
            onModelChanged: reselectVoice()
            function reselectVoice() {
                currentIndex = indexOfValue(ttsViewModel.voiceName)
            }
        }
    }
    Rectangle {
        height: 58
        Layout.fillWidth: true
        color: Style.background
        ToolButton {
            icon.source: ttsViewModel.playButtonIcon
            Accessible.name: qsTrId(ttsViewModel.playButtonLabel)
            icon.color: Style.primary
            icon.height: 32
            icon.width: 32
            anchors.centerIn: parent
            onClicked: {
                if (taPoem.selectedText) {
                    ttsViewModel.play(taPoem.selectedText)
                } else {
                    ttsViewModel.play(taPoem.text, taPoem.selectionStart)
                }
            }
        }
    }
    GridLayout {
        columns: 2

        Text {
            color: Style.primaryText
            text: qsTrId("label_pitch");
            Accessible.name: text
        }
        Slider {
            id: ttsPitch
            from: ttsViewModel.minPitch
            value: ttsViewModel.pitch
            to: ttsViewModel.maxPitch
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
            text: qsTrId("label_rate");
            Accessible.name: text
        }
        Slider {
            id: ttsRate
            from: ttsViewModel.minRate
            value: ttsViewModel.rate
            to: ttsViewModel.maxRate
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
