function set_short_data(data_short_forecast) {
    //gets 3 hour forecast
    let short_forecast = data_short_forecast

    /*
        Example from short_forecast function:
        Actual temp, feels like, date and time, icon
        [[-5.5499999999999545,-8.889999999999986,2023-11-16 03:00:00,03n]

    */

    //converts with C++ function: temperature and feels like to correct units when is_celesius is true or false
    let top_left_temperature_actual = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(short_forecast[0][0]) : convertion.kelvin_to_fahrenheit(short_forecast[0][0]);
    let top_left_temperature_feelsLike = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(short_forecast[0][1]) : convertion.kelvin_to_fahrenheit(short_forecast[0][1]);

    //Sets temperature and feels like in top left corner
    main_rectangle.top_view_left_text = "Actual: "+ top_left_temperature_actual + main_rectangle.f_or_c + "\nFeels like: " + top_left_temperature_feelsLike + main_rectangle.f_or_c;
    //Sets icon in top left corner
    main_rectangle.top_view_left_image = "https://openweathermap.org/img/wn/"+ short_forecast[0][3] +"@2x.png"
    //Sets date and time top left
    main_rectangle.top_view_left_text_top = timeConvertion.timestamp_to_time(short_forecast[0][2])

    //converts with C++ function: temperature and feels like to correct units when is_celesius is true or false
    let top_middle_temperature_actual = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(short_forecast[1][0]) : convertion.kelvin_to_fahrenheit(short_forecast[1][0]);
    let top_middle_temperature_feelsLike = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(short_forecast[1][1]) : convertion.kelvin_to_fahrenheit(short_forecast[1][1]);

    //Sets temperature and feels like in top middle
    main_rectangle.top_view_middle_text = "Actual: "+ top_middle_temperature_actual + main_rectangle.f_or_c + "\nFeels like: " + top_middle_temperature_feelsLike + main_rectangle.f_or_c;
    //Sets icon in top middle
    main_rectangle.top_view_middle_image = "https://openweathermap.org/img/wn/"+ short_forecast[1][3] +"@2x.png"
    //Sets date and time top middle
    main_rectangle.top_view_middle_text_top = timeConvertion.timestamp_to_time(short_forecast[1][2])

    //converts with C++ function: temperature and feels like to correct units when is_celesius is true or false
    let top_right_temperature_actual = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(short_forecast[1][0]) : convertion.kelvin_to_fahrenheit(short_forecast[1][0]);
    let top_right_temperature_feelsLike = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(short_forecast[1][1]) : convertion.kelvin_to_fahrenheit(short_forecast[1][1]);

    //Sets temperature and feels like in top right
    main_rectangle.top_view_right_text = "Actual: "+ top_right_temperature_actual + main_rectangle.f_or_c + "\nFeels like: " + top_right_temperature_feelsLike + main_rectangle.f_or_c
    //Sets icon in top right
    main_rectangle.top_view_right_image = "https://openweathermap.org/img/wn/"+ short_forecast[2][3] +"@2x.png"
    //Sets date and time top right
    main_rectangle.top_view_right_text_top = timeConvertion.timestamp_to_time(short_forecast[2][2])

    //This triggers signal to update weather in main_rectangle
    main_rectangle.updateWeather++;
}

function set_long_data(data_long_forecast){
    //gets three day forecast
    let long_forecast = data_long_forecast

    /*
        Example from three_days_forecast function:
        Actual temp, feels like, date and time, icon
        [-4.659999999999968,-4.659999999999968,2023-11-17 12:00:00,03d]
    */

    //converts with C++ function: temperature and feels like to correct units when is_celesius is true or false
    let bottom_left_temperature_actual = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(long_forecast[0][0]) : convertion.kelvin_to_fahrenheit(long_forecast[0][0]);
    let bottom_left_temperature_feelsLike = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(long_forecast[0][1]) : convertion.kelvin_to_fahrenheit(long_forecast[0][1]);

    //Sets temperature and feels like in bottom left
    main_rectangle.bottom_view_left_text = "Actual: "+ bottom_left_temperature_actual + main_rectangle.f_or_c +
                                            "\nFeels like: " + bottom_left_temperature_feelsLike + main_rectangle.f_or_c

    //converts date with C++ function and Sets icon in bottom left
    main_rectangle.bottom_view_left_text_top = timeConvertion.timestamp_to_date(long_forecast[0][2])
    main_rectangle.bottom_view_left_image =  "https://openweathermap.org/img/wn/"+long_forecast[0][3]+"@2x.png"

    //converts with C++ function: temperature and feels like to correct units when is_celesius is true or false
    let bottom_middle_temperature_actual = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(long_forecast[1][0]) : convertion.kelvin_to_fahrenheit(long_forecast[1][0]);
    let bottom_middle_temperature_feelsLike = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(long_forecast[1][1]) : convertion.kelvin_to_fahrenheit(long_forecast[1][1]);

    //Sets temperature and feels like in bottom middle
    main_rectangle.bottom_view_middle_text = "Actual: "+ bottom_middle_temperature_actual + main_rectangle.f_or_c +
                                             "\nFeels like: " + bottom_middle_temperature_feelsLike + main_rectangle.f_or_c

    //converts date with C++ function and Sets icon in bottom middle
    main_rectangle.bottom_view_middle_text_top = timeConvertion.timestamp_to_date(long_forecast[1][2])
    main_rectangle.bottom_view_middle_image =  "https://openweathermap.org/img/wn/"+long_forecast[1][3]+"@2x.png"

    //converts with C++ function: temperature and feels like to correct units when is_celesius is true or false
    let bottom_right_temperature_actual = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(long_forecast[2][0]) : convertion.kelvin_to_fahrenheit(long_forecast[2][0]);
    let bottom_right_temperature_feelsLike = main_rectangle.is_celsius ? convertion.kelvin_to_celsius(long_forecast[2][1]) : convertion.kelvin_to_fahrenheit(long_forecast[2][1]);

    //Sets temperature and feels like in bottom right
    main_rectangle.bottom_view_right_text = "Actual: "+ bottom_right_temperature_actual + main_rectangle.f_or_c +
                                            "\nFeels like: " + bottom_right_temperature_feelsLike + main_rectangle.f_or_c

    //converts date with C++ function and Sets icon in bottom right
    main_rectangle.bottom_view_right_text_top = timeConvertion.timestamp_to_date(long_forecast[2][2])
    main_rectangle.bottom_view_right_image =  "https://openweathermap.org/img/wn/"+long_forecast[2][3]+"@2x.png"

    main_rectangle.updateWeather++;
}
