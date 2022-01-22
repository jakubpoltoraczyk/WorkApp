import QtQuick 2.12
import QtQuick.Dialogs 1.3

import "../configuration"

Item {
    id: customDialog

    /**
     * @brief Create bitwise-or combination of QML standard buttons
     * @param buttonTypes Types of button, which will be used to create appropriate combination
     * @return Bitwise-or combination of QML standard buttons
     */
    function getStandardButtons(buttonTypes) {
        var standardButtons
        for(var i = 0; i < buttonTypes.length; ++i) {
            standardButtons |= buttonTypes[i]
        }
        return standardButtons
    }

    Connections {
        target: customDialogService

        /** Called, when custom dialog should be displayed */
        onDisplay: {
            messageDialog.title = titleText
            messageDialog.text = contentText
            messageDialog.icon = iconType
            messageDialog.standardButtons = getStandardButtons(buttonTypes)
            messageDialog.visible = true
        }
    }

    MessageDialog {
        id: messageDialog
    }
}

