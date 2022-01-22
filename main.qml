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

    /** 
     * @brief Create new window component using specified window type
     * @param type:WindowType windowType Type of the window, which will be created 
     */
    function createWindowComponent(windowType) {
        var component = Qt.createComponent(WindowManagerConstants.windowSources.get(windowType))
        if(component.status == Component.Ready) {
            component.createObject(splashScreen)
        } else {
            console.log("Error loading component: ", component.errorString())
        }
    }

    Connections {
        target: windowManager

        /** Called, when splash screen should be hidden */
        onHideSplashScreen: {
            splashScreen.visible = false
        }

        /** Called, when splash screen should be displayed */
        onShowSplashScreen: {
            splashScreen.visible = true
        }

        /** Called, when new window should be created */
        onCreateWindow: {
            createWindowComponent(windowType)
        }
    }

    Image {
        id: splashScreenImage
        source: "qrc:/srcgui/images/qtlogo.png"
        anchors.centerIn: parent
    }
}
