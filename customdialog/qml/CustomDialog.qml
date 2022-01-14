import QtQuick 2.12
import QtQuick.Dialogs 1.3

Item {
    id: customDialog

    Connections {
        target: customDialogService

        onDisplay: {
            messageDialog.title = titleText
            messageDialog.text = contentText
            messageDialog.visible = true
        }
    }

    MessageDialog {
        id: messageDialog
        icon: StandardIcon.Critical
    }
}

