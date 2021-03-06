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
    width: contentItem.childrenRect.width
    height: contentItem.childrenRect.height
    color: Style.background
    title: qsTrId("about_dialog_title")

    ColumnLayout {
        Text {
            Layout.topMargin: 64
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            text: qsTrId("about_content_title")
            Accessible.name: text
            font.bold: true
            color: Style.primaryText
            width: paintedWidth
            height: paintedHeight
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }
        Text {
            Layout.topMargin: 8
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            Layout.bottomMargin: 16
            text: Qt.application.version
            Accessible.name: text
            color: Style.primaryText
            width: paintedWidth
            height: paintedHeight
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }
        Text {
            Layout.topMargin: 16
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            Layout.bottomMargin: 16
            text: qsTrId("about_copyright")
            Accessible.name: text
            color: Style.primaryText
            width: paintedWidth
            height: paintedHeight
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }
        Loader {
            Layout.topMargin: 16
            Layout.leftMargin: 32
            Layout.rightMargin: 32
            sourceComponent: aboutLinkedItem
            property string iconSource: "ic_code"
            property string label: "about_source_label"
            property string link: "about_source_link"
        }
        RowLayout {
            Layout.leftMargin: 32
            Layout.rightMargin: 32
            Icon { source: "qrc:/images/ic_legal.svg" }
            Text {
                text: qsTrId("about_legal_label")
                Accessible.name: text
                font.bold: true
                color: Style.primaryText
            }
        }
        Loader {
            Layout.leftMargin: 64
            Layout.rightMargin: 32
            sourceComponent: aboutLinkedItem
            property string iconSource: "ic_right"
            property string label: "about_legal_app_license_label"
            property string link: "about_legal_app_license_link"
        }
        Loader {
            Layout.leftMargin: 64
            Layout.rightMargin: 32
            sourceComponent: aboutLinkedItem
            property string iconSource: "ic_right"
            property string label: "about_legal_rhymer_license_label"
            property string link: "about_legal_rhymer_license_link"
        }
        Loader {
            Layout.leftMargin: 64
            Layout.rightMargin: 32
            sourceComponent: aboutLinkedItem
            property string iconSource: "ic_right"
            property string label: "about_legal_thesaurus_license_label"
            property string link: "about_legal_thesaurus_license_link"
        }
        Loader {
            Layout.leftMargin: 64
            Layout.rightMargin: 32
            sourceComponent: aboutLinkedItem
            property string iconSource: "ic_right"
            property string label: "about_legal_dictionary_license_label"
            property string link: "about_legal_dictionary_license_link"
        }
        Loader {
            Layout.leftMargin: 64
            Layout.rightMargin: 32
            Layout.bottomMargin: 64
            sourceComponent: aboutLinkedItem
            property string iconSource: "ic_right"
            property string label: "about_legal_material_icons_license_label"
            property string link: "about_legal_material_icons_license_link"
        }
    }
    Component {
        id: aboutLinkedItem
        RowLayout {
            Icon { source: `qrc:/images/${iconSource}.svg` }
            Text {
                text: qsTrId(label)
                Accessible.name: text
                font.bold: true
                color: Style.primary
                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        Qt.openUrlExternally(qsTrId(link))
                    }
                }
            }
        }
    }
}
