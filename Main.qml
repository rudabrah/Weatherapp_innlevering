//Main.qml
import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts


Window {

    id: root
    width: 850
    height: 850
    visible: true
    title: qsTr("Freyr")//Nordic god of sunshine
    //********************************************************************************
    //Handeling colors
    property bool dark_Mode: dark_Mode_Switch.checked
    //fargevalg for darkmode og ikke
    property string dark_mode_on_top: "#1A1A2B"
    property string dark_mode_off_top: "#D1E5E8"
    property string dark_mode_on_right: "steelblue"
    property string dark_mode_off_right: "lightsteelblue"
    property string dark_mode_on_left: "darkslategrey"
    property string dark_mode_off_left: "lightslategrey"
    property string darkModeText: "white"
    property string lightModeText: "black"

    //Gjør textfargen-if-en til en variabel så jeg slipper å skrive den flere steder
    property string textColor: root.dark_Mode ? root.darkModeText : root.lightModeText
    //********************************************************************************
    //Variabler for å holde brukerinput
    property string userCityInput: ""
    property string userApiKey: ""

    //Må bruke double da float ikke finnes.
    property double currentTemperature: 0.0


    function getNewWeather( string1, string2)
    {
        console.log(string1, string2)
        //Update the stored values
        root.userCityInput = string1
        root.userApiKey = string2

        myWeather.getCurrentWeather(string1, string2)

    }


    Connections {
        target: myWeather
        onDataReady: {
            // Access myWeather.curTemp safely here
            console.log("Current Temperature in QML:", myWeather.curTemp);

            getNewWeather("Oslo", "xxxx");

        }
    }

    /*  //Keeping the data updated
    Timer {
        interval: 30000
        running: true
        repeat: true
        onTriggered: {
            // Trigger a function to update weather data
            myWeather.getCurrentWeather("Oslo", "");
        }
    }*/


    //Rectangle to house all the goodgood
    Rectangle {
        id: mainbkg
        anchors.fill: parent
        anchors.centerIn: parent
        anchors.rightMargin: 2
        anchors.bottomMargin: 2
        anchors.leftMargin: 2
        anchors.topMargin: 2
        color: root.dark_Mode ? root.dark_mode_on_top : root.dark_mode_off_top

        Column{
            id:topColumn
            spacing: 2

            Rectangle{
                id: topColRec;
                color: root.dark_Mode ? root.dark_mode_on_top : root.dark_mode_off_top
                height: root.height / 7
                width: root.width
                radius: 10

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

            }
            Rectangle{
                id: topColBottomRec
                height: (root.height / 7) * 6
                width: root.width

                Row{
                    id: rootRows1;
                    spacing: 2;
                    width: topColBottomRec.width / 2
                    height: topColBottomRec.height
                    anchors.left: topColBottomRec.left

                    Rectangle{
                        color: root.dark_Mode ? root.dark_mode_on_right : root.dark_mode_off_right
                        width: rootRows1.width
                        height: rootRows1.height
                        radius: 10

                        WeatherDetails{

                        }
                    }
                }

                Row{
                    id: rootRows2
                    spacing: 2
                    width: topColBottomRec.width / 2
                    height: topColBottomRec.height
                    anchors.left: rootRows1.right

                    Rectangle{
                        color: root.dark_Mode ? root.dark_mode_on_left : root.dark_mode_off_left
                        width: rootRows2.width
                        height: rootRows2.height
                        radius: 10

                        WeatherDetails{

                        }
                    }
                }

            }

        }

    }

}





