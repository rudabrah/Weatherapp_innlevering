.pragma library

//Gets the weather from API by city name
function get_current_weather(CityName, api_key) {

    //Makes API GEt request
    const api_link = "https://api.openweathermap.org/data/2.5/weather?q=" + encodeURIComponent(CityName) + "&appid=" + api_key;
    var request = new XMLHttpRequest();
    request.open("GET", api_link, false);
    request.send();

    //Sets respons as variable
    var response = JSON.parse(request.responseText);

    //Prints respons nore readable
    //console.log(JSON.stringify(response, null, 2));

    //returns the temps and icons as a list
    return [response.main.temp,
            response.main.feels_like,
            response.weather[0].icon,
            response.main.dtd_txt]
}

//gets the weather and returns the next 3 hours
function get_three_hour_forecast(CityName, APIkey) {

    //Makes API GEt request
    const api_link = "https://api.openweathermap.org/data/2.5/forecast?q="+CityName+"&appid="+APIkey;
    var request = new XMLHttpRequest();
    request.open("GET", api_link, false);
    request.send();

    //Sets respons as variable
    var response = JSON.parse(request.responseText);

    //console.log(JSON.stringify(response, null, 2));
    //console.log(response.list[0].main.temp);

    //returns the temps and icons to the list
    return [[response.list[1].main.temp,
                          response.list[1].main.feels_like,
                          response.list[1].dt_txt,
                          response.list[1].weather[0].icon],
                          [response.list[2].main.temp,
                           response.list[2].main.feels_like,
                           response.list[2].dt_txt,
                           response.list[2].weather[0].icon],
                          [response.list[3].main.temp,
                           response.list[3].main.feels_like,
                           response.list[3].dt_txt,
                           response.list[3].weather[0].icon]]
}

//gets and returns forcast for three days
function get_three_days_forecast(CityName, APIkey){

    //Makes API GEt request
    const api_link = "https://api.openweathermap.org/data/2.5/forecast?q="+CityName+"&appid="+APIkey;
    var request = new XMLHttpRequest();
    request.open("GET", api_link, false);
    request.send();

    //Sets respons as variable
    var response = JSON.parse(request.responseText);

    //console.log(JSON.stringify(response, null, 2));
    //console.log(response.list[13].dt_txt)

    return[[response.list[11].main.temp,
           response.list[11].main.feels_like,
           response.list[11].dt_txt,
           response.list[11].weather[0].icon],
            [response.list[26].main.temp,
            response.list[26].main.feels_like,
            response.list[19].dt_txt,
            response.list[19].weather[0].icon],
            [response.list[39].main.temp,
            response.list[39].main.feels_like,
            response.list[27].dt_txt,
            response.list[27].weather[0].icon]]
}
