//currentweather.cpp

#include "currentweather.h"


currentWeather::currentWeather(QObject *parent)
    : QObject{parent}
{
    myNetworkManager = new QNetworkAccessManager(this);
    connect(myNetworkManager, &QNetworkAccessManager::finished, this, &currentWeather::handleReply);
    connect(this, &currentWeather::currentResponse, this, &currentWeather::handleWeather);


}


//Function to
void currentWeather::getCurrentWeather(const QString &currentCity, const QString &apiKey)
{
    //prepare the requesturl
    QString weatherRequestUrl ="http://api.openweathermap.org/data/2.5/weather?q="
                                + currentCity
                                + "&appid="
                                + apiKey;

    //Handle the request
    QNetworkRequest currentRequest;
    currentRequest.setUrl(QUrl(weatherRequestUrl));
    myNetworkManager->get(currentRequest);
}

QJsonObject currentWeather::makeStringToJson(QString myString)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(myString.toUtf8(), &parseError);
    QJsonObject jsonWObj = jsonDocument.object();

    if (parseError.error == QJsonParseError::NoError)
    {
        qInfo() << jsonWObj;
        return jsonWObj;
    }
    qDebug() << "Error parsing JSON:" << parseError.errorString();
    return QJsonObject();
}



void currentWeather::handleReply(QNetworkReply *reply)
{
    QString response;//Lager variablen
    if (reply->error() == QNetworkReply::NoError) {
        // Leser all dataen fra replyen
        response = reply->readAll();
        //Printer ut for å sjekke den
        //qInfo() << response;
        //sender den dirrekte til handleForcars for videre behandling
        emit currentResponse(response);
    } else {
        // Handle error
        emit reqError(reply->errorString());
    }

}

void currentWeather::handleWeather(QString replyResponse)
{
    QJsonObject weatherJson = makeStringToJson(replyResponse);

    if (weatherJson.isEmpty()) return;

    //Get the temp
    double kelvToC = 272.15;
    QJsonObject currentWeatherMainObject = weatherJson["main"].toObject();
    curTemp = currentWeatherMainObject["temp"].toDouble() - kelvToC;
    qInfo() << "Current temp is" << curTemp << "°C";

    //Description
    QJsonArray currentWeatherdescToArray = weatherJson["weather"].toArray();
    QJsonObject currentWeatherDescriptionObject = currentWeatherdescToArray[0].toObject();
    QString currentWeatherDescription = currentWeatherDescriptionObject["description"].toString();
    QString currentWeatherIcon = currentWeatherDescriptionObject["icon"].toString();
    qInfo() << "Description" << currentWeatherDescription << "icon" << currentWeatherIcon;

    // Emit signals to notify QML about the changes
    emit curTempChanged();
    emit currentWeatherDescriptionChanged();

    QMap<QString, double> temp_and_desc_map;



}





