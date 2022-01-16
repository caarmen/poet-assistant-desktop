import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import ColorType 1.0

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
        color: Style.toColor(model.rhyme.backgroundColor)
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
                color: Style.primaryText
                font.bold: model.rhyme.bold
                font.italic: model.rhyme.italic
                text: model.rhyme.text
                Layout.fillWidth: true
            }
        }
    }
}
