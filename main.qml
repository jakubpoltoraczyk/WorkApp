import QtQuick 2.12
import QtQuick.Window 2.12
import InputComponentDataset 1.0

import "configuration"
import "inputcomponent/qml"
import "rectanglebutton/qml"

Window {
    id: loginWindow
    width: 450
    height: 400
    color: SharedConstants.defaultWindowColor
    visible: true

    Column {
        id: inputCompomentColumn
        spacing: 15
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }

        InputComponent {
            id: loginInputComponent
            labelText: "Login:"
            placeholderText: "Enter your login"
            mode: InputComponentDataset.Mode.NORMAL
        }

        InputComponent {
            id: passwordInputComponent
            labelText: "Password:"
            placeholderText: "Enter your password"
            mode: InputComponentDataset.Mode.PASSWORD
        }
    }

    Row {
        id: buttonsRow
        spacing: 20
        anchors {
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
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
