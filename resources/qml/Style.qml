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
import QtQuick 2.12
import ColorType
pragma Singleton
QtObject {
    property color accent
    property color background
    property color primary
    property color primaryText
    property color surface
    function toColor(colorType) {
        switch (colorType) {
        case ColorType.Accent: return Style.accent
        case ColorType.Background: return Style.background
        case ColorType.Primary: return Style.primary
        case ColorType.PrimaryText: return Style.primaryText
        case ColorType.Surface: return Style.surface
        default: return undefined
        }
    }
}
