import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import Qt5Compat.GraphicalEffects

Rectangle {
    property string word
    color: Material.backgroundColor
    height: 48
    width: parent.width
    visible: word.length > 0
    FavoriteIcon {
        id: favoriteIcon
        wordView: wordView
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
    }
    Text {
        id: wordView
        x: 16
        color: Material.primaryTextColor
        font.bold: true
        text: word
        anchors.left: favoriteIcon.right
        anchors.verticalCenter: parent.verticalCenter
    }
}
