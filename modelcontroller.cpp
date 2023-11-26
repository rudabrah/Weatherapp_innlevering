// modelcontroller.cpp

#include "modelcontroller.h"


QString valgtby = "Oslo";
QString apiNøkkel = "";
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
                     + valgtby
                     + "&appid="
                     + apiNøkkel;

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
        qInfo() << jsonObj;
        return jsonObj;
    }
    qDebug() << "Error parsing JSON:" << parseError.errorString();
    return QJsonObject();
}
//{"base":"stations",
//"clouds":{"all":100},
//"cod":200,
//"coord":{"lat":59.9127,"lon":10.7461},
//"dt":1700820364,
//"id":3143244,
//"main":{"feels_like":269.24,"grnd_level":990,"humidity":66,"pressure":994,"sea_level":994,"temp":273.37,"temp_max":274.14,"temp_min":272.55},
//"name":"Oslo",
//"sys":{"country":"NO","id":1624,"sunrise":1700811310,"sunset":1700836341,"type":1},
//"timezone":3600,
//"visibility":10000,
//"weather":[{"description":"overcast clouds","icon":"04d","id":804,"main":"Clouds"}],
//"wind":{"deg":350,"gust":14.64,"speed":3.85}

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


//Her tar vi inn "data" emited fra onReplyFinished og gjør den til jsonobjekter
void ModelController::handleForcast(QString responsData)
{
    //Tar inn QString data som er emited og sendes inn her som "responsData
    QJsonObject weatherData = convertStringToJson(responsData);
    //Sjekke at det faktisk kommer noe
    if(weatherData.isEmpty()) return ;
    //lager en map som holder klokkeslett og værinfo
    QMap<QTime, WeatherInfo*> map_date_weather;
    //Kjører igjennom hele JsonObjektet som enkelte linjer
    for(auto it = weatherData.constBegin(); it != weatherData.constEnd(); it++)
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

                WeatherInfo* new_weather = new WeatherInfo();
                new_weather->setDescription("x");
                new_weather->setTemp_cel(2);
                new_weather->setUrl("light");
                new_weather->setIconUrl("x");

                map_date_weather.insert(time, new_weather);

               /* for (auto it = map_date_weather.constBegin(); it != map_date_weather.constEnd(); ++it) {
                    qDebug() << "Key:" << it.key().toString("HH:mm:ss") << ", Value:" << it.value()->getDescription();
                }
*/


            }

        }

    }

  /*  //Prøve noe helt nytt
    QJsonObject mainObject = weatherData["main"].toObject();
    double temperature = mainObject["temp"].toDouble() - kelvTodegC;
    QJsonArray weatherArray = weatherData["weather"].toArray();
    QJsonObject firstWeatherObject = weatherArray[0].toObject();
    QString weatherDescription = firstWeatherObject["description"].toString();
    QString weatherIcon = firstWeatherObject["icon"].toString();






    qInfo() << new_weather->iconUrl();
    qInfo() << new_weather->description() << new_weather->temp_cel();

*/

}




// Clean up
//reply->deleteLater();


