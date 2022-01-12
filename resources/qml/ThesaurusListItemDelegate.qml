import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    onClicked: {
        if (model.thesaurus.interactive) contextMenu.popup()
    }
    WordContextMenu {
        id: contextMenu
        word: model.thesaurus.text
    }
    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 0
        ColumnLayout {
            Rectangle {
                color: Material.backgroundColor
                width: 50
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: model.thesaurus.indentLevel * 16
                FavoriteIcon {
                    id: favoriteIcon
                    visible: model.thesaurus.interactive
                    wordView: wordView
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 16
                }
                Text {
                    id: wordView
                    color: Material.primaryTextColor
                    font.bold: model.thesaurus.bold
                    font.italic: model.thesaurus.italic
                    text: model.thesaurus.text
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: favoriteIcon.right
                    anchors.leftMargin: 8
                }
            }
        }
    }
}
