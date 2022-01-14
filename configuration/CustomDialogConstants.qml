pragma Singleton
import QtQuick 2.12

QtObject {
    readonly property var buttonTypes: (new Map([
        [CustomDialogDataset.ButtonType.Ok, StandardButton.Ok],
        [CustomDialogDataset.ButtonType.Open, StandardButton.Open],
        [CustomDialogDataset.ButtonType.Save, StandardButton.Save]
    ]))
}