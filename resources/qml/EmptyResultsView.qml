import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15

Rectangle {
    property string emptyText
    color: Style.background
    Text {
        color: Style.primaryText
        font.bold: true
        text: emptyText
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
