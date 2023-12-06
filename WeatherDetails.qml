import QtQuick 2.0
import QtQuick.Controls 2.15


Item{

    id: weatherItem

    property string currentWeatherDetail: myWeather.currentWeatherDescription
    property string currentWeatherTemp: "Current Temperature: " + myWeather.curTemp.toFixed(2) + "°C"
    property string currentWeatherIcon: myWeather.currentWeatherIcon
    property string iconlink: "https://openweathermap.org/img/wn/" + currentWeatherIcon + "@2x.png"
    property string loadupIconLink: "https://openweathermap.org/img/wn/01d@2x.png"

    function updateWeatherIcon()
    {
        weatherIcon.source = iconLink
    }


    Timer {
        interval: 30000
        running: true
        repeat: true
        onTriggered: {
            // Trigger a function to update weather data
            myWeather.getCurrentWeather("Oslo", "xxx");
        }
    }

    Rectangle{
        id: wetrec1
        width: 300
        height: 200
        color: "lightblue"
        radius: 10

        Grid{

            Label {
                anchors.centerIn: parent
                text: weatherItem.currentWeatherIcon
                color: root.textColor
            }


            Image{
                id: weatherIcon
                source: weatherItem.loadupIconLink
                height: 100
                width: 100

            }

        }


    }

}
