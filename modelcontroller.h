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

class ModelController : public QObject
{
    Q_OBJECT
public:
    explicit ModelController(QObject *parent = nullptr);
    void requestWeatherData(const QString &cityName, const QString &apiKey);

signals:
    void requestError(const QString &error);
    void gotData(QString);


private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    void ObjectFromString();
    void handleForcast(QString responsData);
    QJsonObject converStringToJson(QString);
};

#endif // MODELCOMPONENT_H
