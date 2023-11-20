// modelcontroller.cpp

#include "modelcontroller.h"

ModelController::ModelController(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &ModelController::onReplyFinished);
    connect(this, &ModelController::gotData, this, &ModelController::handleForcast);
}

void ModelController::requestWeatherData(const QString &cityName, const QString &apiKey)
{
    // Replace YOUR_API_KEY with your actual OpenWeatherMap API key
    QString apiUrl = "http://api.openweathermap.org/data/2.5/forecast?q=Oslo&appid=xxxxx";

    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));
    networkManager->get(request);

}

void ModelController::onReplyFinished(QNetworkReply *reply)
{
    QString data;
    if (reply->error() == QNetworkReply::NoError) {
        // Read the data from the reply
        data = reply->readAll();
        emit gotData(data);
    } else {
        // Handle error
        emit requestError(reply->errorString());
    }
}

//Function to convert QString to JsonObject. This needs a pass through JsonDocument.
QJsonObject convertStringToJson(QString stringToConvert)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(stringToConvert.toUtf8(), &parseError);

    if (parseError.error == QJsonParseError::NoError)
    {
        return jsonDocument.object();  // Return an empty object on error
    }

    qDebug() << "Error parsing JSON:" << parseError.errorString();
    return QJsonObject();
}


void ModelController::handleForcast(QString responsData)
{
    qInfo() << responsData;
    QJsonObject weatherData = convertStringToJson(responsData);//Bruker funksjonen rett over
    if(weatherData.isEmpty()) return ;

    for(auto it = weatherData.constBegin(); it != weatherData.constEnd(); it++)
    {
        QString key = it.key();
        auto value = it.value();

        if(key.contains("list"))
        {
            for(auto const &weather: value.toArray())
            {
                qInfo() << weather;
            }
        }

    }
}




// Clean up
//reply->deleteLater();


