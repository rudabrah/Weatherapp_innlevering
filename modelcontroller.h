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


private slots:
    void onReplyFinished(QNetworkReply *reply);
    void handleForcast(QString responsData);

private:
    QNetworkAccessManager *networkManager;
    void ObjectFromString();
    QJsonObject converStringToJson(QString);

    //Denne er fra dayinfoklassen
    QList<DayInfo> m_day_info;

};

#endif // MODELCOMPONENT_H
