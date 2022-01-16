import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15

ItemDelegate {
    anchors.left: parent ? parent.left : undefined
    anchors.right: parent ? parent.right : undefined
    contentItem: RowLayout {
        spacing: 0
        Rectangle {
            color: Style.background
            Layout.leftMargin: 16
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredWidth: childrenRect.width + 16
            Layout.fillHeight: true
            Text {
                color: Style.primaryText
                text: model.definition.part_of_speech
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        Rectangle {
            color: Style.background
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredHeight: childrenRect.height
            Layout.fillWidth: true
            Text {
                color: Style.primaryText
                text: model.definition.definition
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                wrapMode: Text.WordWrap
            }
        }
    }
}
