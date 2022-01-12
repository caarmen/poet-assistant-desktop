import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

Rectangle {
    color: Material.backgroundColor
    height: parent.height
    width: parent.width
    ScrollView {
        anchors.fill: parent
        clip: true
        ListView {
            id: thesaurusList
            header: WordHeader {
                word: thesaurusListModel.word
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
