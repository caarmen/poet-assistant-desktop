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

ToolBar {
    signal searched
    property int textFieldLeftEdge: tfSearch.x + tfSearch.leftPadding
    background: Rectangle { color: Style.primary }
    RowLayout {
        anchors.fill: parent
        Rectangle {
            Layout.preferredHeight: childrenRect.height
            Layout.fillWidth: true
            Layout.topMargin: 4
            Layout.bottomMargin: 4
            Layout.leftMargin: 56
            Layout.rightMargin: 56
            color: Style.background
            TextField {
                id: tfSearch
                width: parent.width
                selectByMouse: true
                leftPadding: 48
                rightPadding: 48
                topPadding: 12
                bottomPadding: 12
                color: Style.primaryText
                selectionColor: Style.primary
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: Style.surface
                    Layout.fillWidth: true
                }
                placeholderText: qsTrId("hint_search")
                placeholderTextColor: Style.secondaryText
                Keys.onReleased: event => {
                                     if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                                         onSearch()
                                     }
                                 }
                onTextChanged: {
                    btnSearch.enabled = length > 0
                    btnClose.visible = length > 0
                    mainViewModel.searchSuggestions(tfSearch.text)
                }
            }

            ToolButton {
                id: btnSearch
                enabled: false
                icon.color: Style.primaryText
                icon.source: "qrc:/images/search.svg"
                Accessible.name: qsTrId("a11y_icon_search")
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                onClicked:  onSearch()
            }
            ToolButton {
                id: btnClose
                visible: false
                icon.color: Style.primaryText
                icon.source: "qrc:/images/close.svg"
                Accessible.name: qsTrId("a11y_icon_clear")
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                onClicked: tfSearch.clear()
            }
        }
    }

    Component.onCompleted: {
        tfSearch.forceActiveFocus()
    }

    function onSearch() {
        mainViewModel.search(tfSearch.text)
        searched()
    }

    function submitText(text) {
        tfSearch.text = text
        btnSearch.clicked()
    }
}
