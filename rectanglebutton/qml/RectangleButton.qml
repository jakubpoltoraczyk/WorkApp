import QtQuick 2.12
import QtQuick.Controls 2.12

import "../../rectanglesolidborder"
import "../../configuration"

Button {
    id: rectangleButton
    width: 80
    height: 40
    background: Rectangle {
        id: buttonBackground
        color: ColorConstants.lightGrey
    }
    contentItem: Text {
        id: contentItemText
        text: rectangleButton.text
        color: SharedConstants.defaultTextColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font {
            pixelSize: SharedConstants.defaultFontPixelSize
            family: SharedConstants.defaultFontFamily
        }
    }

    /** Set button's pressed style */
    function setPressedStyle() {
        contentItemText.color = ColorConstants.darkGrey
        solidBorder.topBorderColor = ColorConstants.darkGrey
        solidBorder.leftBorderColor = ColorConstants.darkGrey
        solidBorder.bottomBorderColor = ColorConstants.white
        solidBorder.rightBorderColor = ColorConstants.white
    }

    /** Set button's released style */
    function setReleasedStyle() {
        contentItemText.color = ColorConstants.black
        solidBorder.topBorderColor = ColorConstants.white
        solidBorder.leftBorderColor = ColorConstants.white
        solidBorder.bottomBorderColor = ColorConstants.darkGrey
        solidBorder.rightBorderColor = ColorConstants.darkGrey
    }

    /** Called, when button has been created */
    Component.onCompleted: {
        mouseArea.released.connect(RectangleButtonService.onReleased)
    }

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent

        /** Called, when mouse entered the mouse area */
        onEntered: {
            buttonBackground.color = ColorConstants.mediumDarkGrey
        }

        /** Called, when mouse exited the mouse area */
        onExited: {
            if (pressed) {
                return
            }
            buttonBackground.color = ColorConstants.lightGrey
        }

        /** Called, when button is pressed */
        onPressed: {
            setPressedStyle()
        }

        /** Called, when button is released */
        onReleased: {
            if (!containsMouse) {
                buttonBackground.color = ColorConstants.lightGrey
            }
            setReleasedStyle()
        }
    }

    RectangleSolidBorder {
        id: solidBorder
        topBorderColor: ColorConstants.white
        leftBorderColor: ColorConstants.white
        bottomBorderColor: ColorConstants.darkGrey
        rightBorderColor: ColorConstants.darkGrey
    }
}
