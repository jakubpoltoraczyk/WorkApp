import QtQuick 2.12

import "../configuration"

Item {
    id: rectangleSolidBorder
    anchors.fill: parent

    /** Width of the border */
    property int borderWidth: SharedConstants.defaultBorderWidth

    /** Color of the border on the right side */
    property string rightBorderColor: ColorConstants.black

    /** Color of the border on the left side */
    property string leftBorderColor: ColorConstants.black

    /** Color of the border on the top side */
    property string topBorderColor: ColorConstants.black

    /** Color of the border on the bottom side */
    property string bottomBorderColor: ColorConstants.black

    /** Visibility of the border on the right side */
    property bool rightBorderVisibility: true

    /** Visibility of the border on the left side */
    property bool leftBorderVisibility: true

    /** Visibility of the border on the top side */
    property bool topBorderVisibility: true

    /** Visibility of the border on the bottom side */
    property bool bottomBorderVisibility: true

    Rectangle{
        color: rightBorderColor
        width: borderWidth
        height: parent.height + borderWidth
        visible: rightBorderVisibility
        anchors.left: parent.right
    }

    Rectangle{
        color: leftBorderColor
        width: borderWidth
        height: parent.height + borderWidth
        visible: leftBorderVisibility
        anchors.right: parent.left
    }

    Rectangle{
        color: topBorderColor
        width: parent.width + 2 * borderWidth
        height: borderWidth
        x: parent.x - borderWidth
        visible: topBorderVisibility
        anchors.bottom: parent.top
    }

    Rectangle{
        color: bottomBorderColor
        width: parent.width
        height: borderWidth
        visible: bottomBorderVisibility
        anchors.top: parent.bottom
    }
}
