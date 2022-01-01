import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true

    menuBar: MenuBar {
        // ...
    }

    header: ToolBar {
        // ...
    }

    footer: TabBar {
        // ...
    }

    StackView {
        anchors.fill: parent
    }
}
