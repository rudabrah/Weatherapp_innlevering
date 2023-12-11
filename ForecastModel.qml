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
        anchors.centerIn: parent
        width: parent.width - 20
        height: parent.height - 20


        ColumnLayout {
            id: columnLayout1
            width: parent.width - 15

            anchors.fill: parent
            Label{
                width: parent.width
                text: "Date          Time               Description             Temperature"
                font.bold: true
                color: root.textColor

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
