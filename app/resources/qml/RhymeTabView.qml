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

Rectangle {
    signal rhymeToastTextChanged(string text)
    color: Style.background
    height: parent.height
    width: parent.width
    ScrollView {
        anchors.fill: parent
        clip: true
        ListView {
            id: rhymeList
            header: WordHeader {
                word: rhymeListModel.word
                copyLabel: qsTrId("a11y_icon_copy_rhymes")
                onCopyClicked: {
                    mainViewModel.copyRhymes(rhymeListModel.word)
                    rhymeToastTextChanged(qsTrId("toast_copied_rhymes"))
                }
            }
            headerPositioning: ListView.PullBackHeader
            model: rhymeListModel
            delegate: RhymeListItemDelegate {}
        }
    }
    EmptyResultsView {
        visible: rhymeListModel.isEmptyTextVisible
        emptyText: rhymeListModel.emptyText
        anchors.fill: parent
    }
}
