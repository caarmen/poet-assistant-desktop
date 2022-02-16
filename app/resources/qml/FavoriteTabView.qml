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

Rectangle {
    color: Style.background
    height: parent.height
    width: parent.width
    ScrollView {
        anchors.fill: parent
        clip: true
        ListView {
            id: favoriteList
            model: favoriteListModel
            header: RowLayout {
                width: parent.width
                Text {
                    height: 48
                    color: Style.primaryText
                    font.bold: true
                    text: qsTrId("favorites_header")
                    Layout.leftMargin: 16
                }
                ToolButton {
                    icon.source: "qrc:/images/delete.svg"
                    icon.color: Style.primary
                    Layout.alignment: Qt.AlignRight
                    Layout.rightMargin: 16
                    onClicked: {
                        dlgDeleteConfirm.open()
                    }
                }
            }
            headerPositioning: ListView.PullBackHeader
            delegate: FavoriteListItemDelegate {}
        }
    }
    EmptyResultsView {
        visible: favoriteListModel.isEmptyTextVisible
        emptyText: qsTrId("favorites_empty")
        anchors.fill: parent
    }
    Dialog {
        id: dlgDeleteConfirm
        width: 320
        modal: true
        title: qsTrId("delete_confirm_title")
        anchors.centerIn: parent
        contentItem: Text{
            text: qsTrId("delete_confirm_message")
            color: Style.primaryText
        }
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: mainViewModel.clearFavorites();
    }
}
