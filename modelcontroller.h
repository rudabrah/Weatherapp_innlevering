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
    Q_PROPERTY(QVariantMap weatherData READ getWeatherData WRITE setWeatherData NOTIFY weatherDataChanged)

public:
    explicit ModelController(QObject *parent = nullptr);
    Q_INVOKABLE void requestWeatherData(const QString &cityName, const QString &apiKey);

    QVariantMap getWeatherData() const {
        return m_weatherData;
    }

    void setWeatherData(const QVariantMap &newData) {
        if (m_weatherData != newData) {
            m_weatherData = newData;
            emit weatherDataChanged();
        }
    }



signals:
    void requestError(const QString &error);
    void gotData(QString);
    //This is to give the QML a heads up to start
    void modelReady();
    void weatherDataChanged();


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

    QVariantMap m_weatherData;
};

#endif // MODELCOMPONENT_H
