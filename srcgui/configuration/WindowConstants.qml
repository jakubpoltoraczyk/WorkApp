pragma Singleton
import QtQuick 2.12

QtObject {
    /** Default window color */
    readonly property color defaultWindowColor: ColorConstants.extraLightGrey

    /** Default width of the application window */
    readonly property int defaultWindowWidth: 450

    /** Default height of the application window */
    readonly property int defaultWindowHeight: 400

    /** Default input components column spacing */
    readonly property int defaultInputComponentsColumnSpacing: 15

    /** Default buttons row spacing */
    readonly property int defaultButtonsRowSpacing: 20

    /** Default buttons row bottom margin */
    readonly property int defaultButtonsRowBottomMargin: 50
}
