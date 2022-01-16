import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15

Rectangle {
    color: Style.background
    height: parent.height
    width: parent.width
    ScrollView {
        anchors.fill: parent
        clip: true
        ListView {
            id: favoriteList
            model: favoriteListModel
            header: Text {
                height: 48
                color: Style.primaryText
                font.bold: true
                text: qsTr("favorites_header")
                x: 16
                verticalAlignment: Text.AlignVCenter
            }
            headerPositioning: ListView.PullBackHeader
            delegate: FavoriteListItemDelegate {}
        }
    }
    EmptyResultsView {
        visible: favoriteListModel.isEmptyTextVisible
        emptyText: qsTr("favorites_empty")
        anchors.fill: parent
    }
}
