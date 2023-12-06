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
    property string dark_mode_on: "#1A1A1A"
    property string dark_mode_off: "#D1E5E8"
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

            WeatherDetails.updateWeatherIcon();


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
        WeatherDetails{
            anchors.centerIn: parent

        }






    }


}





