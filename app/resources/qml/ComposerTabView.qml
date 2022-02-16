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
import QtQuick.Dialogs
import QtQuick.Layouts

ColumnLayout {
    height: parent.height
    width: parent.width
    TtsControlsView {  }

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
            placeholderText: qsTrId("hint_compose")
            text: composerViewModel.poem
            onTextChanged: composerViewModel.poem = text
        }
    }
    Rectangle {
        height: 24
        Layout.fillWidth: true
        color: Style.background
        Text {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 16
            text: qsTrId(composerViewModel.poemFileName)
            color: Style.primaryText
        }
        Text {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 16
            text: qsTrId(composerViewModel.savedState)
            color: Style.primaryText
        }
    }

    /**
     * Return true if the menu item was handled
     */
    function handleMenuItemSelected(menuItemId)  {
        if (menuItemId === "new") {
            dlgNewConfirm.open()
            return true
        } else if (menuItemId === "open") {
            showFileDialog(dlgFileOpen)
            return true
        } else if (menuItemId === "saveas") {
            dlgFileSaveAs.currentFile = new URL(composerViewModel.getFileDialogFile())
            showFileDialog(dlgFileSaveAs)
            return true
        } else {
            return false;
        }
    }

    function showFileDialog(dialog) {
        dialog.currentFolder = new URL(composerViewModel.getFileDialogFolder())
        dialog.open()
    }

    FileDialog {
        id: dlgFileOpen
        fileMode: FileDialog.OpenFile
        nameFilters: [qsTrId("file_filter_text")]
        onAccepted: composerViewModel.open(selectedFile)
    }
    FileDialog {
        id: dlgFileSaveAs
        fileMode: FileDialog.SaveFile
        nameFilters: [qsTrId("file_filter_text")]
        onAccepted: composerViewModel.saveAs(selectedFile)
    }
    Dialog {
        id: dlgNewConfirm
        width: 320
        modal: true
        title: qsTrId("new_confirm_title")
        anchors.centerIn: parent
        contentItem: Text{
            text: qsTrId("new_confirm_message")
            color: Style.primaryText
        }
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: composerViewModel.newFile()
    }
}
