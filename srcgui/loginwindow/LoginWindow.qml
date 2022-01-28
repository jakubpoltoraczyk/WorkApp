import QtQuick 2.12
import QtQuick.Window 2.12
import InputComponentDataset 1.0

import "../configuration"
import "../inputcomponent"
import "../rectanglebutton"
import "../customdialog"

Window {
    id: loginWindow
    width: WindowConstants.defaultWindowWidth
    height: WindowConstants.defaultWindowHeight
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    color: WindowConstants.defaultWindowColor
    flags: Qt.Window | Qt.FramelessWindowHint
    visible: true

    /** Emitted, when login button has been released */
    signal loginButtonReleased(string loginText, string passwordText)

    /** Called, when component has been created */
    Component.onCompleted: {
        registerButton.released.connect(loginWindowService.onRegisterButtonReleased)
        loginButtonReleased.connect(loginWindowService.onLoginButtonReleased)
        exitButton.released.connect(loginWindowService.onBackButtonReleased)
    }

    Column {
        id: inputCompomentsColumn
        spacing: WindowConstants.defaultInputComponentsColumnSpacing
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
        spacing: WindowConstants.defaultButtonsRowSpacing
        anchors {
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: WindowConstants.defaultButtonsRowBottomMargin
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
                loginButtonReleased(loginInputComponent.contentText, passwordInputComponent.contentText)
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
