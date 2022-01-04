pragma Singleton
import QtQuick 2.12

QtObject {
    /** Default border width value */
    readonly property int defaultBorderWidth: 1

    /** Default text color */
    readonly property color defaultTextColor: ColorConstants.black

    /** Default font pixel size */
    readonly property int defaultFontPixelSize: 15

    /** Default font family */
    readonly property string defaultFontFamily: "FreeSans" 

    /** Default window color */
    readonly property color defaultWindowColor: ColorConstants.extraLightGrey
}
