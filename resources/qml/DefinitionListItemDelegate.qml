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
        Rectangle {
            color: Material.backgroundColor
            Layout.leftMargin: 16
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredWidth: childrenRect.width + 16
            Layout.fillHeight: true
            Text {
                color: Material.primaryTextColor
                text: model.definition.part_of_speech
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }
        }
        Rectangle {
            color: Material.backgroundColor

            Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            Text {
                color: Material.primaryTextColor
                text: model.definition.definition
                anchors.left: parent.left
                anchors.right: parent.right
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                wrapMode: Text.WordWrap
            }
        }
    }
}
