import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ScrollView {
    anchors.fill: parent
    clip: true
    ListView {
        id: definitionsList
        header: WordHeader {
            word: definitionsListModel.word
        }
        headerPositioning: ListView.PullBackHeader
        model: definitionsListModel
        delegate: DefinitionListItemDelegate {}
    }
    Rectangle {
        color: Material.backgroundColor
        visible: definitionsListModel.isEmptyTextVisible
        anchors.fill: parent
        Text {
            color: Material.primaryTextColor
            font.bold: true
            text: definitionsListModel.emptyText
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
