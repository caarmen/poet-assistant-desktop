import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15

Rectangle {
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
