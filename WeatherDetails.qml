import QtQuick 2.0
import QtQuick.Controls 2.15

Item{

    id: weatherItem

    property string sunicon: "https://cdn-icons-png.flaticon.com/512/5115/5115625.png"


    Rectangle{
        id: wetrec1
        width: 300
        height: 200
        color: "lightblue"
        radius: 10

        property string weatherText: ""

        Text {
            anchors.centerIn: parent
            text: wetrec1.weatherText
        }

        Image{
            id: mypic1
            source: weatherItem.sunicon
            height: 100
            width: 100

        }
    }

}
