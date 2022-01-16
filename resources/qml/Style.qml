import QtQuick 2.12
import QtQuick.Controls.Material 2.12
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
