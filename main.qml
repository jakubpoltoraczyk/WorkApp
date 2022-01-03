import QtQuick 2.12
import QtQuick.Window 2.12

import "configuration"
import "rectanglebutton/qml"

Window {
    id: loginWindow
    width: 450
    height: 400
    color: SharedConstants.defaultWindowColor
    visible: true

    Row {
        id: buttonsRow
        spacing: 20
        anchors {
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            leftMargin: 50
            rightMargin: 50
            bottomMargin: 50
        }

        RectangleButton {
            id: registerButton
            text: "Register"
        }

        RectangleButton {
            id: loginButton
            text: "Login"
        }

        RectangleButton {
            id: exitButton
            text: "Exit"
        }
    }
}
