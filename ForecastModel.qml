// ForecastModel.qml
import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: forecastModel

    property var forecastData: []

    ListView {
        id: forecastListView
        width: parent.width
        height: parent.height
        model: forecastModel.forecastData
        delegate: Text {
            text: forecastData
            color: root.textColor

        }
    }

    function updateForecast(data) {
        console.log("Data received in QML:", JSON.stringify(data));
        forecastData = []; // Clear the existing data
        for (var key in data) {
            var value = data[key];
            forecastData.push("Key: " + key + ", Value: " + value);
        }
        // Trigger a refresh of the ListView if necessary
        forecastListView.model = forecastData;
    }



}
