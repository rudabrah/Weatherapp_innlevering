//currentweather.h

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
#include <cmath>


class currentWeather : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float curTemp READ getCurTemp NOTIFY curTempChanged)
    Q_PROPERTY(QString currentWeatherDescription READ getCurrentWeatherDescription NOTIFY currentWeatherDescriptionChanged)


public:
    explicit currentWeather(QObject *parent = nullptr);

    Q_INVOKABLE void getCurrentWeather(const QString &currentCity, const QString &apiKey);

    float getCurTemp() const
    {
        return roundToDecimalPlaces(curTemp, 2);
    }
    QString getCurrentWeatherDescription() const
    {
        return currentWeatherDescription;
    }

    Q_INVOKABLE QString currentCity;
    Q_INVOKABLE QString weatherDescription;

signals:
    void reqError(const QString &error);
    void currentResponse(QString);
    void curTempChanged();
    void currentWeatherDescriptionChanged();

public slots:
    void handleWeather(QString replyResponse);

private slots:
    void handleReply(QNetworkReply *reply);


private:
    QNetworkAccessManager *myNetworkManager;
    void requestError(QString);
    QJsonObject makeStringToJson(QString myString);

    Q_INVOKABLE float curTemp;
    QString currentWeatherDescription;
    QMap<QString, float> temp_and_desc_map;
    float roundToDecimalPlaces(float value, int decimalPlaces) const
    {
        const float multiplier = std::pow(10.0, decimalPlaces);
        float roundedValue = std::round(value * multiplier) / multiplier;

        // Ensure that the rounded value is within the representable range for a double
        if (std::isfinite(roundedValue))
            return roundedValue;
        else
            return value; // Return the original value if rounding causes overflow or underflow
    }


};

#endif // CURRENTWEATHER_H
