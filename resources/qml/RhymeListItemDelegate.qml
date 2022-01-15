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
    contentItem: Rectangle {
        anchors.fill: parent
        color: model.rhyme.interactive ? Material.backgroundColor : Style.surface
        RowLayout {
            anchors.fill: parent
            spacing: 0
            Layout.alignment: Qt.AlignVCenter
            anchors.leftMargin: 16
            FavoriteIcon {
                visible: model.rhyme.interactive
                wordView: wordView
                Layout.alignment: Qt.AlignVCenter
            }
            Text {
                id: wordView
                color: Material.primaryTextColor
                font.bold: model.rhyme.bold
                font.italic: model.rhyme.italic
                text: model.rhyme.text
                Layout.fillWidth: true
            }
        }
    }
}
