import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    //Rectangle to house all the goodgood
    Rectangle {
        id: mainbkg
        anchors.fill: parent
        color: "#D1E5E8"//Found this on jscolor.com


        //Central column layout to keep things in order
        ColumnLayout {
            spacing: 3
            id: columnLo1
            anchors.centerIn: parent
            anchors.fill: parent

            RowLayout {
                spacing: 2
                id: rowLo1
                //anchors.top: parent.top
                Layout.alignment: Qt.AlignRight
                height: parent.height / 4 - 3
                width: 60

                Button{
                    id: test1


                }


            }

        }





    }
}
