//WeatherSearch.qml
import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts


//This QML will hold a rectangle with a grid for a button, textinput for a city and texinput for api-key
Item {
    id: weatherGetter


    //Function to get the input from the user.
    function getUserInput()
    {
        console.log(byInput.text, apiInput.text)
        root.userCityInput = byInput.text
        root.userApiKey = apiInput.text
        //console.log(root.userCityInput, root.userApiKey)
        startCurrentWeatherApiRequest()
    }

    function startCurrentWeatherApiRequest()
    {
        myWeather.getCurrentWeather(root.userCityInput, root.userApiKey);
        myModel.requestWeatherData(root.userCityInput, root.userApiKey);
    }



    Rectangle{
        id: weatherGetterRectangle
        width: 500

        color: root.dark_Mode ? root.dark_mode_on_top : root.dark_mode_off_top


        RowLayout{


            TextInput{
                width: weatherGetterRectangle.width/3
                id: byInput
                padding: 10
                color: root.textColor
                text: "Velg by"
                overwriteMode: true
                activeFocusOnTab: true


            }




            TextInput{
                width: weatherGetterRectangle.width/3
                id: apiInput
                padding: 10
                color: root.textColor
                text: "Legg inn API-nøkkel her"
                overwriteMode: true
                activeFocusOnTab: true

            }






            Button{
                id: searchBtn
                text: "Søk"
                padding: 50

                onClicked: {
                    getUserInput()

                }


            }

        }






    }



}
