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
    readonly property color accentDay: "#607D8B"
    readonly property color accentNight: "#879fab"
    readonly property color primaryDay: "#607D8B"
    readonly property color primaryNight: "#879fab"
    readonly property color backgroundDay: "#ffffff"
    readonly property color backgroundNight: "#111111"
    readonly property color primaryTextDay: "#000000"
    readonly property color primaryTextNight: "#ffffff"
    readonly property color secondaryTextDay: "#888888"
    readonly property color secondaryTextNight: "#888888"
    readonly property color surfaceDay: "#f6f7f9"
    readonly property color surfaceNight: "#222222"

    property color accent: accentDay
    property color background: backgroundDay
    property color primary: primaryDay
    property color primaryText: primaryTextDay
    property color secondaryText: secondaryTextDay
    property color surface: surfaceDay
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
    function useNightPalette() {
        Style.accent = accentNight
        Style.background = backgroundNight
        Style.primary = primaryNight
        Style.primaryText = primaryTextNight
        Style.secondaryText = secondaryTextNight
        Style.surface = surfaceNight
    }

    function useDayPalette() {
        Style.accent = accentDay
        Style.background = backgroundDay
        Style.primary = primaryDay
        Style.primaryText = primaryTextDay
        Style.secondaryText = secondaryTextDay
        Style.surface = surfaceDay
    }

    function useMaterial(material, lightTheme, darkTheme, isDayMode) {
        material.theme = isDayMode? lightTheme : darkTheme
        if (isDayMode) useDayPalette()
        else useNightPalette()
        material.primary = Style.primary
        material.accent = Style.accent
        material.background = Style.background
        material.primaryText = Style.primaryText
    }
    function useUniversal(universal, lightTheme, darkTheme, isDayMode) {
        universal.theme = isDayMode? lightTheme : darkTheme
        if (isDayMode) useDayPalette()
        else useNightPalette()
        universal.accent =  Style.accent
        universal.background = Style.background
        universal.foreground = Style.foreground
    }
    function useFusion(appPalette, isDayMode) {
        if (isDayMode) useDayPalette()
        else useNightPalette()
        appPalette.button = Style.surface
        appPalette.buttonText = Style.primary
        appPalette.dark = Style.surface
        appPalette.highlight = Style.accent
        appPalette.highlightedText = Style.primaryText
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
