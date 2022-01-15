import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import ColorType 1.0

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
    contentItem: Rectangle {
        anchors.fill: parent
        color: Style.toColor(model.thesaurus.backgroundColor)
        RowLayout {
            anchors.fill: parent
            spacing: 0
            Layout.alignment: Qt.AlignVCenter
            anchors.leftMargin: 16
            FavoriteIcon {
                visible: model.thesaurus.interactive
                wordView: wordView
                Layout.alignment: Qt.AlignVCenter
            }
            Text {
                id: wordView
                color: Material.primaryTextColor
                font.bold: model.thesaurus.bold
                font.italic: model.thesaurus.italic
                text: model.thesaurus.text
                Layout.fillWidth: true
            }
        }
    }
}
