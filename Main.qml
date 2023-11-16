import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts


Window {
    id: root
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Freyr")//Nordic god of sunshine

    property bool dark_Mode: false

    property string dark_mode_on: "#1A1A1A"
    property string dark_mode_off: "#D1E5E8"


    //Rectangle to house all the goodgood
    Rectangle {
        id: mainbkg
        anchors.fill: parent
        color: root.dark_Mode ? root.dark_mode_on : root.dark_mode_off

    }


}

