import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

Rectangle {
    property string emptyText
    color: Material.backgroundColor
    Text {
        color: Material.primaryTextColor
        font.bold: true
        text: emptyText
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
