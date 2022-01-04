pragma Singleton
import QtQuick 2.12

QtObject {
    /** Maximum text length used in input component */
    readonly property int maximumTextLength: 20

    /** Default height value used in input component */
    readonly property int defaultHeight: 40

    /** Default size of button used in input component */
    readonly property int defaultButtonSize: 12

    /** Path to visibility false eye image used in input component */
    readonly property string visibilityFalseEyeImagePath: "images/visibilityFalseEye.png"

    /** Path to visiblity true eye image used in input component */
    readonly property string visibilityTrueEyeImagePath: "images/visibilityTrueEye.png"
}
