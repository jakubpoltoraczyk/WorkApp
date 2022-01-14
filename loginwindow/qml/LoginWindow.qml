import QtQuick 2.12
import QtQuick.Window 2.12
import InputComponentDataset 1.0
import QtQuick.Dialogs 1.3

import "../../configuration"
import "../../inputcomponent"
import "../../rectanglebutton"
import "../../customdialog/qml"

Window {
    id: loginWindow
    width: 450
    height: 400
    color: SharedConstants.defaultWindowColor
    visible: true

    /** Emit, when login button has been released */
    signal loginRequested(string loginText, string passwordText)

    /** Called, when component has been created */
    Component.onCompleted: {
        registerButton.released.connect(loginWindowService.onRegisterRequested)
        loginRequested.connect(loginWindowService.onLoginRequested)
        exitButton.released.connect(loginWindowService.onExitRequested)
    }

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
            placeholderFieldText: "Enter your login"
            mode: InputComponentDataset.Mode.NORMAL
        }

        InputComponent {
            id: passwordInputComponent
            labelText: "Password:"
            placeholderFieldText: "Enter your password"
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

            /** Called, when button has been released */
            onReleased: {
                loginRequested(loginInputComponent.contentText, passwordInputComponent.contentText)
            }
        }

        RectangleButton {
            id: exitButton
            text: "Exit"
        }
    }

    CustomDialog {
        id: customDialog
    }
}
