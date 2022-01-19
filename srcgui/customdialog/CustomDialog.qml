import QtQuick 2.12
import QtQuick.Dialogs 1.3

import "../configuration"

Item {
    id: customDialog

    function getStandardButtons(buttonTypes) {
        var standardButtons
        for(var i = 0; i < buttonTypes.length; ++i) {
            standardButtons |= buttonTypes[i]
        }
        return standardButtons
    }

    Connections {
        target: customDialogService

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

