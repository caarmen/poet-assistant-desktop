import QtQuick.Controls 2.12
import QtQuick 2.11
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12

ScrollView {
    Layout.fillWidth: true
    Layout.fillHeight: true
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.fill: parent
    ListView {
        id: thesaurusList
        Layout.fillWidth: true
        Layout.fillHeight: true
        anchors.fill: parent
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        model: rhymeListModel
        delegate: RhymeListItemDelegate {}
    }
}
