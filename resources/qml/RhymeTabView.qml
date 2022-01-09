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
            word: rhymeListModel.word
        }
        headerPositioning: ListView.PullBackHeader
        model: rhymeListModel
        delegate: RhymeListItemDelegate {}
    }
    Rectangle {
        color: Material.backgroundColor
        visible: rhymeListModel.isEmptyTextVisible
        anchors.fill: parent
        Text {
            color: Material.primaryTextColor
            font.bold: true
            text: rhymeListModel.emptyText
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
