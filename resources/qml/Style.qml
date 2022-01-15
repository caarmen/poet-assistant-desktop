import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import ColorType
pragma Singleton
QtObject {
    property color surface
    property color background
    function toColor(colorType) {
        if (colorType === ColorType.Surface) {
            return Style.surface
        } else if(colorType === ColorType.Background) {
            return Style.background
        }
        else {
            return undefined
        }
    }
}
