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

    QString url() const;
    void setUrl(const QString &newUrl);

    QString description() const;
    void setDescription(const QString &newDescription);

signals:

private:
    double m_temp_cel;
    QString m_url;
    QString m_description;

};

#endif // WEATHERINFO_H
