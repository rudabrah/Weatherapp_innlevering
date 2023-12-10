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
    Q_PROPERTY(QVariantMap fullForecastData READ fullForecastData NOTIFY forecastDataReady)
    Q_PROPERTY(QString forecastDataString READ forecastDataString NOTIFY forecastDataStringReady)


public:
    explicit ModelController(QObject *parent = nullptr);

    Q_INVOKABLE void requestWeatherData(const QString &cityName, const QString &apiKey);

    QVariantMap fullForecastData() const;
    QVariantMap convertToVariantMap(QMap<QDateTime, WeatherInfo *> map);

    QString convertToVariantString(QMap<QDateTime, WeatherInfo *> map);

    Q_INVOKABLE QString forecastDataString() const;

    Q_INVOKABLE QString fullforecastDataString;

    Q_INVOKABLE void setforecastDataString(const QString newForecastDataString);
    Q_INVOKABLE QString getforecastDataString();

signals:
    void requestError(const QString &error);
    void gotData(QString);
    //This is to give the QML a heads up to start
    void modelReady();
    void weatherDataChanged();

    void forecastDataReady(QVariantMap forecastData);
    void forecastDataStringReady();


private slots:
    void onReplyFinished(QNetworkReply *reply);
    void handleForcast(QString responsData);

private:
    QNetworkAccessManager *networkManager;
    void ObjectFromString();
    QJsonObject converStringToJson(QString);
    //Denne er fra dayinfoklassen
    QList<DayInfo> m_day_info;

    QVariantMap fullforecastData;
    QString m_forecastDataString;




};

#endif // MODELCOMPONENT_H
