import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    onClicked: {
        if (model.rhyme.interactive) contextMenu.popup()
    }
    WordContextMenu {
        id: contextMenu
        word: model.rhyme.text
    }
    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 0
        ColumnLayout {
            Rectangle {
                width: 50
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: model.rhyme.indentLevel * 16
                FavoriteIcon {
                    visible: model.rhyme.interactive
                    id: favoriteIcon
                    wordView: wordView
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 16
                }
                Text {
                    id: wordView
                    color: Material.primaryTextColor
                    font.bold: model.rhyme.bold
                    font.italic: model.rhyme.italic
                    text: model.rhyme.text
                    anchors.right: parent.right
                    anchors.left: favoriteIcon.right
                    anchors.leftMargin: 8
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }
}
