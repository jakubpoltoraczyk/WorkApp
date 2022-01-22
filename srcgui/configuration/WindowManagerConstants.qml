pragma Singleton
import QtQuick 2.12
import WindowManagerDataset 1.0

QtObject {
    /** Map, which links window types with window sources */
    readonly property var windowSources: (new Map([
        [WindowManagerDataset.WindowType.LoginWindow, "qrc:/srcgui/loginwindow/LoginWindow.qml"],
        [WindowManagerDataset.WindowType.RegisterWindow, "qrc:/srcgui/registerwindow/RegisterWindow.qml"]
    ]))
}
