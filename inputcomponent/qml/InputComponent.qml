import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
import InputComponentDataset 1.0

import "../../configuration"

Row {
    id: inputComponent
    spacing: 5

    /** Mode of the input component */
    property int mode: InputComponentDataset.Mode.NORMAL

    /** Label text displayed in the input component */
    property alias labelText: inputComponentLabel.text

    /** Placeholder text of the text field displayed in the input component */
    property alias placeholderText: inputComponentField.placeholderText

    /** Called, when input component has been created */
    Component.onCompleted: {
        inputComponentField.editingFinished.connect(InputComponentService.onEditingFinished)
    }

    Label {
        id: inputComponentLabel
        width: 80
        height: InputComponentConstants.defaultHeight
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: SharedConstants.defaultTextColor
        font {
            pixelSize: SharedConstants.defaultFontPixelSize
            family: SharedConstants.defaultFontFamily
        }
    }

    TextField {
        id: inputComponentField
        width: 250
        height: InputComponentConstants.defaultHeight
        maximumLength: InputComponentConstants.maximumTextLength
        color: SharedConstants.defaultTextColor
        echoMode: mode == InputComponentDataset.Mode.NORMAL ? TextInput.Normal : TextInput.Password
        font {
            pixelSize: SharedConstants.defaultFontPixelSize
            family: SharedConstants.defaultFontFamily
        }
        background: Rectangle {
            id: inputComponentFieldBackground
            color: ColorConstants.white
            border {
                color: ColorConstants.lightGrey
                width: SharedConstants.defaultBorderWidth 
            }
        }
    }

    RoundButton {
        id: inputComponentButton 
        width: InputComponentConstants.defaultButtonSize
        height: InputComponentConstants.defaultButtonSize
        visible: mode == InputComponentDataset.Mode.PASSWORD ? true : false
        background: Rectangle {
            id: rectangleBackground
            color: ColorConstants.transparent
        }
        contentItem: Image {
            id: contentItemImage
            source: InputComponentConstants.visibilityFalseEyeImagePath
            anchors.fill: parent
            layer.enabled: true
            layer.effect: OpacityMask {
                id: imageOpacityMask
                maskSource: Rectangle {
                    width: InputComponentConstants.defaultButtonSize
                    height: InputComponentConstants.defaultButtonSize
                    radius: InputComponentConstants.defaultButtonSize / 2
                }
            }
        }

        /** Called, when round button has been pressed and hold */
        onPressAndHold: {
            contentItemImage.source = InputComponentConstants.visibilityTrueEyeImagePath
            inputComponentField.echoMode = TextInput.Normal
        }

        /** Called, when round button has been relased */
        onReleased: {
            contentItemImage.source = InputComponentConstants.visibilityFalseEyeImagePath
            inputComponentField.echoMode = TextInput.Password
        }
        
        /** Called, when round button has been canceled */
        onCanceled: {
            contentItemImage.source = InputComponentConstants.visibilityFalseEyeImagePath
            inputComponentField.echoMode = TextInput.Password
        }
    }
}
