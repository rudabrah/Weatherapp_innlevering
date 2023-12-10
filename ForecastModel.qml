// ForecastModel.qml
import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

Item {
    id: forecastModel

    property string holder: "Forecast here"


    function getForecastToGui(){
        holder = "Oppdaterer"
        holder = root.forecastHolder

    }


    Rectangle{
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout1
            anchors.fill: parent
            Text{
                text: holder
                color: root.textColor
                wrapMode: Text.WordWrap

            }

        }

    }


}
