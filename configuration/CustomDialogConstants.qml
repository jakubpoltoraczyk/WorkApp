pragma Singleton
import QtQuick 2.12
import QtQuick.Dialogs 1.3
import CustomDialogDataset 1.0

QtObject {
    /** Map, which links custom button types with QT standard button types */
    readonly property var standardButtonsTypes: (new Map([
        [CustomDialogDataset.ButtonType.Ok, StandardButton.Ok],
        [CustomDialogDataset.ButtonType.Open, StandardButton.Open],
        [CustomDialogDataset.ButtonType.Save, StandardButton.Save]
    ]))
}
