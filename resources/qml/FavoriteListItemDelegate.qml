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
    contentItem: Rectangle {
        anchors.fill: parent
        color: Style.background
        RowLayout {
            spacing: 0
            FavoriteIcon {
                wordView: wordView
                Layout.leftMargin: 16
            }
            Text {
                id: wordView
                color: Style.primaryText
                text: model.favorite
                Layout.fillWidth: true
            }
        }
    }
}
