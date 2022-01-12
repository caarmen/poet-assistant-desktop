import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import Qt5Compat.GraphicalEffects

Rectangle {
    property Text wordView
    color: "transparent"
    height: 24
    width: 24
    visible: wordView.text.length > 0
    Image {
        id: favorite
        source: mainViewModel.getFavoriteIcon(wordView.text)
        MouseArea {
            id: area
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked:  mainViewModel.toggleFavorite(wordView.text)
        }
        Connections {
            target: mainViewModel
            function onFavoritesChanged() {
                favorite.source = mainViewModel.getFavoriteIcon(wordView.text)
            }
        }
        Connections {
            target: wordView
            function onTextChanged() {
                favorite.source = mainViewModel.getFavoriteIcon(wordView.text)
            }
        }
    }
    ColorOverlay {
        anchors.fill: favorite
        source: favorite
        color: Material.primaryTextColor
    }
}
