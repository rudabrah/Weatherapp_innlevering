#include "currentweather.h"


currentWeather::currentWeather(QObject *parent)
    : QObject{parent}
{
    myNetworkManager = new QNetworkAccessManager(this);
    connect(myNetworkManager, &QNetworkAccessManager::finished, this, &currentWeather::handleReply);

}


//Function to
void currentWeather::getCurrentWeather(const QString &currentCity, const QString &apiKey)
{
    //prepare the requesturl
    QString weatherRequestUrl ="http://api.openweathermap.org/data/2.5/forecast?q="
                                + currentCity
                                + "&appid="
                                + apiKey;

    //Handle the request
    QNetworkRequest currentRequest;
    currentRequest.setUrl(QUrl(weatherRequestUrl));
    myNetworkManager->get(currentRequest);
}

void currentWeather::handleReply(QNetworkReply *reply)
{
    QString response;//Lager variablen
    if (reply->error() == QNetworkReply::NoError) {
        // Leser all dataen fra replyen
        response = reply->readAll();
        //Printer ut for å sjekke den
        //qInfo() << data;
        //sender den dirrekte til handleForcars for videre behandling
        emit currentResponse(response);
    } else {
        // Handle error
        emit requestError(reply->errorString());
    }

}

