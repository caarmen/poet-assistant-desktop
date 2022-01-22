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
    property color accent: "#607D8B"
    property color background: "#fff"
    property color primary: "#607D8B"
    property color primaryText: "#000"
    property color secondaryText: "#888"
    property color surface: "#f6f7f9"
    function toColor(colorType) {
        switch (colorType) {
        case ColorType.Accent: return Style.accent
        case ColorType.Background: return Style.background
        case ColorType.Primary: return Style.primary
        case ColorType.PrimaryText: return Style.primaryText
        case ColorType.SecondaryText: return Style.secondaryText
        case ColorType.Surface: return Style.surface
        default: return undefined
        }
    }
    function useMaterial(material, systemTheme, lightTheme) {
        material.theme = systemTheme
        material.primary = material.theme === lightTheme? "#607D8B" : "#879fab"
        material.accent =  material.theme === lightTheme? "#607D8B" : "#879fab"
        material.background = material.theme === lightTheme? "#fff" : "#111"
        Style.accent = material.accent
        Style.background = material.background
        Style.primary= material.primary
        Style.primaryText = material.primaryTextColor
        Style.secondaryText = material.theme === lightTheme? "#888" : "#888"
        Style.surface = material.theme === lightTheme? "#f6f7f9" : "#222"
    }
    function useUniversal(universal, systemTheme, lightTheme) {
        universal.theme = systemTheme
        universal.accent =  universal.theme === lightTheme? "#607D8B" : "#879fab"
        universal.background = universal.theme === lightTheme? "#fff" : "#000"
        universal.foreground = universal.theme === lightTheme? "#000" : "#fff"
        Style.accent = universal.accent
        Style.background = universal.background
        Style.primary= universal.accent
        Style.primaryText = universal.foreground
        Style.secondaryText = universal.theme === lightTheme? "#888" : "#888"
        Style.surface = universal.theme === lightTheme? "#f6f7f9" : "#181818"
    }
    function useFusion(appPalette) {
        appPalette.button = Style.surface
        appPalette.buttonText = Style.primary
        appPalette.dark = Style.primaryText
        appPalette.highlight = Style.accent
        appPalette.light = Style.background
        appPalette.mid = Style.surface
        appPalette.midlight = Style.surface
        appPalette.placeholderText = Style.secondaryText
        appPalette.shadow = Style.surface
        appPalette.text = Style.primaryText
        appPalette.window = Style.background
        appPalette.windowText = Style.primaryText
    }

}
