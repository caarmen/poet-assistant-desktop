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
    signal thesaurusToastTextChanged(string text)
    color: Style.background
    height: parent.height
    width: parent.width
    ScrollView {
        anchors.fill: parent
        clip: true
        ListView {
            id: thesaurusList
            header: WordHeader {
                word: thesaurusListModel.word
                copyLabel: qsTrId("a11y_icon_copy_thesaurus")
                onCopyClicked: {
                    mainViewModel.copyThesaurus(thesaurusListModel.word)
                    thesaurusToastTextChanged(qsTrId("toast_copied_thesaurus"))
                }
            }
            headerPositioning: ListView.PullBackHeader
            model: thesaurusListModel
            delegate: ThesaurusListItemDelegate {}
        }
    }
    EmptyResultsView {
        visible: thesaurusListModel.isEmptyTextVisible
        emptyText: thesaurusListModel.emptyText
        anchors.fill: parent
    }
}
