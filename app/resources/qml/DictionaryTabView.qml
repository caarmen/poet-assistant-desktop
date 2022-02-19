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
    color: Style.background
    height: parent.height
    width: parent.width
    ScrollView {
        anchors.fill: parent
        clip: true
        ListView {
            id: definitionsList
            header: WordHeader {
                word: definitionsListModel.word
                copyLabel: qsTrId("a11y_icon_copy_definitions")
                onCopyClicked: mainViewModel.copyDefinitions(definitionsListModel.word)
            }
            headerPositioning: ListView.PullBackHeader
            model: definitionsListModel
            delegate: DefinitionListItemDelegate {}
        }
    }
    EmptyResultsView {
        visible: definitionsListModel.isEmptyTextVisible
        emptyText: definitionsListModel.emptyText
        anchors.fill: parent
    }
}
