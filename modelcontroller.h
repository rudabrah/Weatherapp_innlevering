// modelcontroller.h

#ifndef MODELCOMPONENT_H
#define MODELCOMPONENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qqml.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>
#include <QVariantMap>
#include "dayinfo.h"

class ModelController : public QObject
{
    Q_OBJECT


public:
    explicit ModelController(QObject *parent = nullptr);
    Q_INVOKABLE void requestWeatherData(const QString &cityName, const QString &apiKey);




signals:
    void requestError(const QString &error);
    void gotData(QString);
    //This is to give the QML a heads up to start
    void modelReady();
    void weatherDataChanged();
    void forecastDataReady(QVariantMap forecastData);


private slots:
    void onReplyFinished(QNetworkReply *reply);
    void handleForcast(QString responsData);

private:
    QNetworkAccessManager *networkManager;
    void ObjectFromString();
    QJsonObject converStringToJson(QString);
    //Denne er fra dayinfoklassen
    QList<DayInfo> m_day_info;

    QVariantMap convertToVariantMap(QMap<QDateTime, WeatherInfo *> map);

    QVariantMap fullForecastData;



};

#endif // MODELCOMPONENT_H
