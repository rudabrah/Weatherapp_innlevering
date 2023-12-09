// modelcontroller.cpp

#include "modelcontroller.h"



double kelvTodegC = 272.15;

ModelController::ModelController(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &ModelController::onReplyFinished);
    connect(this, &ModelController::gotData, this, &ModelController::handleForcast);
}

void ModelController::requestWeatherData(const QString &cityName, const QString &apiKey)
{
    // Replace YOUR_API_KEY with your actual OpenWeatherMap API key
    QString apiUrl = "http://api.openweathermap.org/data/2.5/forecast?q="
                     + cityName
                     + "&appid="
                     + apiKey;

    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));
    networkManager->get(request);

}



//Function to convert QString to JsonObject. This needs a pass through JsonDocument.
QJsonObject convertStringToJson(QString stringToConvert)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(stringToConvert.toUtf8(), &parseError);
    QJsonObject jsonObj = jsonDocument.object();

    if (parseError.error == QJsonParseError::NoError)
    {
        //qInfo() << jsonObj;
        return jsonObj;
    }
    qDebug() << "Error parsing JSON:" << parseError.errorString();
    return QJsonObject();
}


//Her gjør vi om det vi får fra APIet til lesbar data
void ModelController::onReplyFinished(QNetworkReply *reply)
{
    QString data;//Lager variablen
    if (reply->error() == QNetworkReply::NoError) {
        // Leser all dataen fra replyen
        data = reply->readAll();
        //Printer ut for å sjekke den
        //qInfo() << data;
        //sender den dirrekte til handleForcars for videre behandling
        emit gotData(data);
    } else {
        // Handle error
        emit requestError(reply->errorString());
    }
}


void ModelController::handleForcast(QString responsData)
{
    //Tar inn QString data som er emited og sendes inn her som "responsData
    QJsonObject weatherData = convertStringToJson(responsData);

    //Sjekke at det faktisk kommer noe
    if(weatherData.isEmpty()) return ;

    //lager en map som holder dato, klokkeslett og værinfo
    QMap<QDateTime, WeatherInfo*> map_date_weather;

    //Kjører igjennom hele JsonObjektet som enkelte linjer
    for(auto it = weatherData.constBegin(); it != weatherData.constEnd(); ++it)
    {
        QString key = it.key();
        auto value = it.value();

        //Her kjører vi igjennom hvert lag i json og ser etter "list"
        if(key.contains("list"))
        {
            QDate date;
            QDateTime dateTime;
            QJsonObject obj;

            //Her tar vi hver "list" og legger inn i value for behandling
            for(auto const &weather: value.toArray())
            {


                //datetime
                obj = weather.toObject();
                dateTime = QDateTime::fromString(obj["dt_txt"].toString(),"yyyy-MM-dd HH:mm:ss");
                date = dateTime.date();

                QTime time = dateTime.time();

                //Denne bruker den nye konstrukøren
                DayInfo* day = new DayInfo(date);

                QJsonObject mainObject = obj["main"].toObject();
                double temperature = mainObject["temp"].toDouble() - kelvTodegC;

                QJsonArray weatherArray = obj["weather"].toArray();
                QJsonObject firstWeatherObject = weatherArray[0].toObject();
                QString weatherDescription = firstWeatherObject["description"].toString();
                QString weatherIconLink = firstWeatherObject["icon"].toString();

                WeatherInfo* new_weather = new WeatherInfo();
                new_weather->setDescription(weatherDescription);
                new_weather->setTemp_cel(temperature);
                //new_weather->setUrl("light");
                new_weather->setIconUrl(weatherIconLink);

                map_date_weather.insert(dateTime, new_weather);

                convertToVariantMap(map_date_weather);

                //This is to give the QML a heads up to start
                emit modelReady();

                /*for (auto it = map_date_weather.constBegin(); it != map_date_weather.constEnd(); ++it) {
                    qDebug() << "Key:" << it.key().toString("yyyy-MM-dd HH:mm:ss") << ", Value:" << it.value()->getDescription() << "&" << it.value()->getTemp() <<"°C" ;
                }*/
            }
        }
    }
}


//For å gjøre forcasten tilgjengelig for QML må QMap gjøres om til QVaraintMap
//Kjører en memberfunction ettersom den kun skal brukes som en del av modelcontroller
QVariantMap ModelController::convertToVariantMap(QMap<QDateTime, WeatherInfo*> map){
    QVariantMap variantMap;

    for (auto it = map.constBegin(); it != map.constEnd(); ++it) {
        // Gjør om QDateTime til String så den blir lesbar
        QString key = it.key().toString();

        // Gjør om til string her og av samme grunn som over
        QString value;
        if (it.value() != nullptr) {
            value = QString("Weather: %1, Temperature: %2")
                        .arg(it.value()->description())
                        .arg(it.value()->temp_cel());
        } else {
            value = "No data available";
        }

        // Putter det inn i variantmappen
        variantMap.insert(key, value);
        for (auto it = variantMap.constBegin(); it != variantMap.constEnd(); ++it) {
            qDebug() << it.key() << ": " << it.value();}

        return variantMap;
    }
}








    // Clean up
    //reply->deleteLater();


