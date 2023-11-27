#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QObject>


class WeatherInfo : public QObject
{
    Q_OBJECT
public:
    explicit WeatherInfo(QObject *parent = nullptr);


    double temp_cel() const;
    void setTemp_cel(double newTemp_cel);
    int getTemp();

    QString url() const;
    void setUrl(const QString &newUrl);

    QString description() const;
    void setDescription(const QString &newDescription);
    QString getDescription();

    QString iconUrl() const;
    void setIconUrl(const QString &newIconUrl);


signals:

private:
    double m_temp_cel;
    QString m_url;
    QString m_description;
    QString m_iconUrl;

};

#endif // WEATHERINFO_H
