import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

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
