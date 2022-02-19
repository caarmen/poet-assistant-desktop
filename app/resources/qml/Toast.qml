/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/
import QtQuick
import QtQuick.Controls

Rectangle {
    id: toastContainer

    Timer {
        id: timer
        interval: 4000
        running: false
        repeat: false
        onTriggered: toastContainer.visible = false
    }

    radius: 12
    width: childrenRect.width
    height: childrenRect.height
    color: Style.primary
    visible: false
    Text {
        id: toastText
        leftPadding: 16
        rightPadding: 16
        topPadding: 12
        bottomPadding: 12
        color: Style.primaryTextNight
    }
    function show(text) {
        toastText.text = text
        toastContainer.visible = true
        timer.stop()
        timer.start()
    }

}
