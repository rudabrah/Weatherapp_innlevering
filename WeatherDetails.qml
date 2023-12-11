//WeatherDetails.qml
import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts


Item{
    //********************************************************************************
    //Variabler for currentWeather aka myWeather
    property string baseIconLink: "https://openweathermap.org/img/wn/01d@2x.png"
    property string fullCurrentIconLink: "https://openweathermap.org/img/wn/" + root.iconLinkCurrent + "@2x.png"
    property double currentTempDet: root.currentTemperature.toFixed(2)
    property string currentWeathDescDet: root.currentDesc

    //********************************************************************************
    //Variabler for forecast aka mymodel


    //funtction to update variables on connectiontrigger in Main.qml
    function updateWeatherStatus()
    {
        weatherIcon.source = fullCurrentIconLink
        actualDescLbl.text = currentWeathDescDet
        actualTempLbl.text = currentTempDet + "°C"
    }


    /*Timer {
        interval: 30000
        running: true
        repeat: true
        onTriggered: {
            // Trigger a function to update weather data
            myWeather.getCurrentWeather("Oslo", "xxx");
        }
    }*/
    //just a housing
    Rectangle{
        id: gridRectangle
        width: parent.width / 2
        height: parent.height
        anchors.left: parent.left
        color: "#00000000"
        radius: 10

        ColumnLayout{
            id: grid1
            height: parent.height
            width: parent.width
            //columns: 2
            //columnSpacing: 2
            //rows: 2

            Row{

                Label {
                    id: descriptionLbl
                    padding: 10
                    text:"Description"
                    font.bold: true
                    font.pixelSize: 16
                    color: root.textColor
                    height: 50

                }

                Label{
                    id: actualDescLbl
                    padding: 10

                    text: ""
                    color: root.textColor
                    font.pixelSize: 16
                    height: 50

                }



            }
            Row{

                Label{
                    id: temperatureLbl
                    padding: 10
                    font.bold: true
                    text:"Temperature"
                    font.pixelSize: 16
                    color: root.textColor
                    height: 50

                }

                Label{
                    id: actualTempLbl
                    padding: 10
                    //width: parent /3
                    text: ""
                    color: root.textColor
                    font.pixelSize: 16
                    height: 50

                }

            }
            Row{
                Image{
                    id: weatherIcon

                    source: baseIconLink
                    height: 100
                    width: 100

                }

            }







        }



    }

}
