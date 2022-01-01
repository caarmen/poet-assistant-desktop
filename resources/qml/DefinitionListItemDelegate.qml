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
                Text {
                    color: Material.primaryTextColor
                    text: model.definition.part_of_speech
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
        ColumnLayout {
            Rectangle {
                color: Material.backgroundColor
                Layout.alignment: Qt.AlignVCenter
                Layout.fillWidth: true
                Text {
                    color: Material.primaryTextColor
                    text: model.definition.definition
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                }
            }
        }
    }
}
