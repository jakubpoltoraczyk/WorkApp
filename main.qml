import QtQuick 2.12
import QtQuick.Window 2.12

import "rectanglebutton/qml"
import "configuration"

Window {
    id: loginWindow
    width: 400
    height: 400
    color: SharedConstants.defaultWindowColor
    visible: true

    Row {
        id: buttonsRow
        x: 180
        y: 280
        spacing: 20

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
