import QtQuick 2.12
import QtQuick.Window 2.12
import InputComponentDataset 1.0

import "../configuration"
import "../inputcomponent"
import "../rectanglebutton"
import "../customdialog"

Window {
    id: registerWindow
    width: WindowConstants.defaultWindowWidth
    height: WindowConstants.defaultWindowHeight
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    color: WindowConstants.defaultWindowColor
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint
    visible: true

    /** Emit, when register button has been released */
    signal registerButtonReleased(string loginText, string passwordText)

    /** Called, when component has been created */
    Component.onCompleted: {
        registerButtonReleased.connect(registerWindowService.onRegisterButtonReleased)
        backButton.released.connect(registerWindowService.onBackButtonReleased)
    }

    Column {
        id: inputCompomentColumn
        spacing: WindowConstants.defaultInputComponentsColumnSpacing
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }

        InputComponent {
            id: loginInputComponent
            labelText: "Login:"
            placeholderFieldText: "Create your login"
            mode: InputComponentDataset.Mode.NORMAL
        }

        InputComponent {
            id: passwordInputComponent
            labelText: "Password:"
            placeholderFieldText: "Create your password"
            mode: InputComponentDataset.Mode.PASSWORD
        }

        InputComponent {
            id: confirmPasswordInputComponent
            labelText: "Confirm:"
            placeholderFieldText: "Confirm your password"
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

            /** Called, when register button has been released */
            onReleased: {
                registerButtonReleased(loginInputComponent.contentText, passwordInputComponent.contentText)
            }
        }

        RectangleButton {
            id: backButton
            text: "Back"
        }
    }
}
