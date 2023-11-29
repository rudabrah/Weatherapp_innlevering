#ifndef CURRENTWEATHER_H
#define CURRENTWEATHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qqml.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>


class currentWeather : public QObject
{
    Q_OBJECT
public:
    explicit currentWeather(QObject *parent = nullptr);

    void getCurrentWeather(const QString &currentCity, const QString &apiKey);

signals:
    void reqError(const QString &error);
    void currentResponse(QString);

private slots:
    void handleReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *myNetworkManager;
    void requestError(QString);

};

#endif // CURRENTWEATHER_H
