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
    Q_PROPERTY(QString currentWeatherIcon READ getCurrentWeatherIcon NOTIFY currentWeatherIconChanged)



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
    QString getCurrentWeatherIcon() const
    {
        return currentWeatherIcon;
    }

    //Making variables that will be used in QML public.
    Q_INVOKABLE QString currentCity;
    Q_INVOKABLE QString weatherDescription;
    Q_INVOKABLE QString currentWeatherIcon;
    Q_INVOKABLE float curTemp = 0.0;

    // Declaration of the isValid() method
    bool isValid() const;

signals:
    void reqError(const QString &error);
    void currentResponse(QString);
    void curTempChanged();
    void currentWeatherDescriptionChanged();
    void dataReady();
    void currentWeatherIconChanged();

public slots:
    void handleWeather(QString replyResponse);

private slots:
    void handleReply(QNetworkReply *reply);


private:
    QNetworkAccessManager *myNetworkManager;
    void requestError(QString);
    QJsonObject makeStringToJson(QString myString);


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

    bool valid;



};

#endif // CURRENTWEATHER_H
