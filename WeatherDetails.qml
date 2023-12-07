import QtQuick 2.0
import QtQuick.Controls 2.15


Item{

    property string baseIconLink: "https://openweathermap.org/img/wn/01d@2x.png"

    function updateWeatherIcon()
    {
        weatherIcon.source = iconLink
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

    Rectangle{
        id: gridRectangle
        width: parent.width / 2
        height: parent.height
        anchors.left: parent.left
        color: "#00000000"
        radius: 10

        Grid{
            id: grid1
            height: parent.height / 3
            width: parent.width
            columns: 3
            columnSpacing: 2
            rows: 2

            Label {
                id: descriptionLbl
                padding: 10
                text:"Description"
                //width: parent /3
                font.pixelSize: 16
                color: root.textColor

            }



            Label{
                id: temperatureLbl
                padding: 10
                //width: parent /3
                text:"Temperature"
                font.pixelSize: 16
                color: root.textColor
                


            }


            Image{
                id: weatherIcon

                source: baseIconLink
                height: 100
                width: 100

            }

            Label{
                id: actualDescLbl
                padding: 10
                //width: parent /3
                text:"xx"
                color: root.textColor
                font.pixelSize: 16
            }

            Label{
                id: actualTempLbl
                padding: 10
                //width: parent /3
                text:"0.0"
                color: root.textColor
                font.pixelSize: 16
            }

        }


    }

}
