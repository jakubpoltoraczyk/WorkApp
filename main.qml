import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import "srcgui/configuration"

Window {
    id: splashScreen
    width: 1000
    height: 800
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    flags: Qt.SplashScreen
    visible: true

    /** Map, which links window types with existing windows */
    property var windows: (new Map())

    /**
     * @brief Hide window of specified type
     * @param type:WindowType windowType Type of the window, which will be hidden
    */
    function hideWindow(windows, windowType) {
        if(!windows.has(windowType)) {
            return
        }
        windows.get(windowType).visible = false
    }

    /**
     * @brief Show window of specified type
     * @param type:WindowType windowType Type of the window, which will be displayed
    */
    function showWindow(windows, windowType) {
        if(!windows.has(windowType)) {
            return
        }
        windows.get(windowType).visible = true
    }

    /** 
     * @brief Create new window of specified type
     * @param type:Map windows Map, which links window types with existing windows
     * @param type:WindowType windowType Type of the window, which will be created
     * @return Updated map of existing windows
     */
    function createWindow(windows, windowType) {
        if(!windows.has(windowType)) {
            var component = Qt.createComponent(WindowManagerConstants.windowSources.get(windowType))
            var object = component.createObject(splashScreen)
            windows.set(windowType, object)
        }
        return windows
    }

    /**
     * @brief Delete existing window of specified type
     * @param type:Map windows Map, which links window types with existing windows
     * @param type:WindowType windowType Type of the window, which will be removed
     * @return Updated map of existing windows
    */
    function deleteWindow(windows, windowType) {
        if(windows.has(windowType)) {
            windows.get(windowType).destroy()
            windows.delete(windowType)
        }
        return windows
    }

    Connections {
        target: windowManager

        /** Called, when specified window should be displayed */
        onShowWindow: {
            showWindow(windows, windowType)
        }

        /** Called, when specified window should be hidden */
        onHideWindow: {
            hideWindow(windows, windowType)
        }

        /** Called, when new window should be created */
        onCreateWindow: {
            windows = createWindow(windows, windowType)
        }

        /** Called, when specified window should be removed */
        onDeleteWindow: {
            windows = deleteWindow(windows, windowType)
        }
    }

    Image {
        id: splashScreenImage
        source: "qrc:/srcgui/images/qtlogo.png"
        anchors.centerIn: parent
    }
}
