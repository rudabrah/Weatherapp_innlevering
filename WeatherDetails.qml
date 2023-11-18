import QtQuick 2.0

Item{
    id: weatherItem
    property string sunicon: "https://cdn-icons-png.flaticon.com/512/5115/5115625.png"

    Column{

        Text{
            id: temptext
            text: "her skal temp stå"
            color: root.textColor

        }

        Text{
            id: moistText
            text:"her skal luftfuktighet stå"
            color: root.textColor
        }

    }
}

