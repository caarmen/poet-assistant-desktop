import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import Qt5Compat.GraphicalEffects

Rectangle {
    property Text wordView
    color: "transparent"
    height:childrenRect.height
    width: childrenRect.width
    visible: wordView.text.length > 0
    ToolButton {
        id: favorite
        icon.source: mainViewModel.getFavoriteIcon(wordView.text)
        icon.color: Material.primaryColor
        MouseArea {
            id: area
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked:  mainViewModel.toggleFavorite(wordView.text)
        }
        Connections {
            target: mainViewModel
            function onFavoritesChanged() {
                favorite.icon.source = mainViewModel.getFavoriteIcon(wordView.text)
            }
        }
        Connections {
            target: wordView
            function onTextChanged() {
                favorite.icon.source = mainViewModel.getFavoriteIcon(wordView.text)
            }
        }
    }
}
