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

    property bool dark_Mode: dark_Mode_Switch.checked

    //fargevalg for darkmode og ikke
    property string dark_mode_on: "#1A1A1A"
    property string dark_mode_off: "#D1E5E8"

    property string darkModeText: "white"
    property string lightModeText: "black"

    property string textColor: root.dark_Mode ? root.darkModeText : root.lightModeText




    //Rectangle to house all the goodgood
    Rectangle {
        id: mainbkg
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        color: root.dark_Mode ? root.dark_mode_on : root.dark_mode_off

        Switch {
            id: dark_Mode_Switch

            anchors.right: parent.right
            anchors.top: parent.top

            Text {
                text: qsTr("Dark Mode")
                color: root.textColor
                anchors.top: dark_Mode_Switch.bottom
                anchors.horizontalCenter: dark_Mode_Switch.horizontalCenter
            }
            checked: false



        }

        TextInput {
            id: textInput
            anchors.top: cityInputLbl.bottom
            anchors.left: parent.left
            color: root.textColor
            padding: 5
            width: 80
            height: 20
            text: qsTr("Skriv by her")
            font.pixelSize: 14
        }

        Label{
            id: cityInputLbl
            text: "Hvilken by vil du se?"
            anchors.top: parent.top
            anchors.left: parent.left
            color: root.textColor
            padding: 5

        }
        Button{
            id:searchCityBtn
            text: "Søk"
            anchors.top: textInput.bottom
            anchors.left: parent.left
            padding: 10
        }


    }
    Grid {
        id: grid
        x: 300
        y: 300

        columns: 2
        rows: 2
        width: 400
        height: 400
        spacing: 5

        Text{
            id: tempText
            text:"testest"
            color: root.textColor


        }
        Text{
            id: weatherText
            text:"testesttest"
            color: root.textColor

        }

        WeatherDetails{

        }

    }

}

