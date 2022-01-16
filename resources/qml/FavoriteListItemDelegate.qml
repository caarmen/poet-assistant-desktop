import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    onClicked: {
        contextMenu.popup()
    }
    WordContextMenu {
        id: contextMenu
        word: model.favorite
    }
    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 0
        ColumnLayout {
            Rectangle {
                color: Style.background
                width: 50
                Layout.alignment: Qt.AlignVCenter
                FavoriteIcon {
                    id: favoriteIcon
                    wordView: wordView
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 16
                }
                Text {
                    id: wordView
                    color: Style.primaryText
                    text: model.favorite
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: favoriteIcon.right
                    anchors.leftMargin: 8
                }
            }
        }
    }
}
