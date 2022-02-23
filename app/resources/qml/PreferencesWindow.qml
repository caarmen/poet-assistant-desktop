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
import NightMode
import Theme

Dialog {
    id: dlgPreference
    modal: true
    anchors.centerIn: parent
    ColumnLayout{
        Layout.fillWidth: true
        RowLayout {
            Layout.fillWidth: true
            Text {
                Layout.fillWidth: true
                Layout.margins: 16
                text: qsTrId("preferences_title")
                Accessible.name: text
                font.bold: true
                color: Style.primaryText
            }
            AnnotatedToolButton {
                iconsource: "qrc:/images/close.svg"
                label: qsTrId("a11y_icon_close")
                Layout.alignment: Qt.AlignRight
                onClicked: dlgPreference.close()
            }
        }

        GridLayout {
            Layout.margins: 16
            columns: 2
            Text {
                text:  qsTrId("preferences_label_history_enabled")
                Accessible.name: text
                color: Style.primaryText
            }

            Switch {
                id: switchHistoryEnabled
                onCheckedChanged: preferencesViewModel.historyEnabled = checked
                Component.onCompleted: checked = preferencesViewModel.historyEnabled
            }

            Text {
                text:  qsTrId("preferences_label_night_mode")
                Accessible.name: text
                color: Style.primaryText
            }

            StyledComboBox {
                textRole: "text"
                valueRole: "value"
                model: [
                    {
                        text: qsTrId("preferences_label_night_mode_day"),
                        value: NightMode.Day
                    },
                    {
                        text: qsTrId("preferences_label_night_mode_night"),
                        value: NightMode.Night
                    },
                    {
                        text: qsTrId("preferences_label_night_mode_auto"),
                        value: NightMode.Auto
                    }
                ]

                Component.onCompleted: currentIndex = indexOfValue(preferencesViewModel.nightMode)
                onActivated: preferencesViewModel.nightMode = currentValue
            }

            Text {
                text:  qsTrId("preferences_label_style")
                Accessible.name: text
                color: Style.primaryText
            }

            StyledComboBox {
                textRole: "text"
                valueRole: "value"
                model: [
                    {
                        text: qsTrId("preferences_label_style_basic"),
                        value: Theme.Basic
                    },
                    {
                        text: qsTrId("preferences_label_style_fusion"),
                        value: Theme.Fusion
                    },
                    {
                        text: qsTrId("preferences_label_style_material"),
                        value: Theme.Material
                    },
                    {
                        text: qsTrId("preferences_label_style_universal"),
                        value: Theme.Universal
                    },
                ]

                Component.onCompleted: currentIndex = indexOfValue(preferencesViewModel.style)
                onActivated: preferencesViewModel.style = currentValue
            }
        }
    }
}
