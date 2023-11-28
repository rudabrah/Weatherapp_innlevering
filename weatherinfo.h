#ifndef WEATHERINFO_H
#define WEATHERINFO_H


#include <QObject>


class WeatherInfo : public QObject
{
    Q_OBJECT
public:
    explicit WeatherInfo(QObject *parent = nullptr);


    Q_INVOKABLE double temp_cel() const;
    Q_INVOKABLE void setTemp_cel(double newTemp_cel);
    Q_INVOKABLE int getTemp();

    Q_INVOKABLE QString url() const;
    Q_INVOKABLE void setUrl(const QString &newUrl);

    Q_INVOKABLE QString description() const;
    Q_INVOKABLE void setDescription(const QString &newDescription);
    Q_INVOKABLE QString getDescription();

    Q_INVOKABLE QString iconUrl() const;
    Q_INVOKABLE void setIconUrl(const QString &newIconUrl);

    Q_INVOKABLE double m_temp_cel;
    Q_INVOKABLE QString m_url;
    Q_INVOKABLE QString m_description;
    Q_INVOKABLE QString m_iconUrl;



signals:

private:

};

#endif // WEATHERINFO_H
