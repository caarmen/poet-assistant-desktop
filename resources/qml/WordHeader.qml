import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

Rectangle {
    property string word
    color: Material.backgroundColor
    height: 48
    width: parent.width
    z: 2
    Text {
        x: 16
        color: Material.primaryTextColor
        font.bold: true
        text: word
        anchors.verticalCenter: parent.verticalCenter
    }
}
