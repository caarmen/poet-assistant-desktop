import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 0
        ColumnLayout {
            Rectangle {
                color: Material.backgroundColor
                width: 50
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: 16 + (model.thesaurus.indentLevel * 16)
                Text {
                    color: Material.primaryTextColor
                    font.bold: model.thesaurus.bold
                    font.italic: model.thesaurus.italic
                    text: model.thesaurus.text
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}
