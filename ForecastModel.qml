// ForecastModel.qml
import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts

Item {
    id: forecastModel
    //String for å holde forecasten
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
            Label{
                width: parent.width
                text: "Date          Time               Description             Temperature"
                font.bold: true

            }

            Text{
                text: holder
                color: root.textColor
                wrapMode: Text.WordWrap
                font.pixelSize: 12

            }

        }

    }


}
