//dayinfo.h

#ifndef DAYINFO_H
#define DAYINFO_H

#include <QObject>
#include <QDate>
#include "weatherinfo.h"

class DayInfo : public QObject
{
    Q_OBJECT
public:
    explicit DayInfo(QObject *parent = nullptr);
    explicit DayInfo(QDate date): m_date{date}
    {}//Alternativ konstruktør

    QDate date() const;
    void setDate(const QDate &newDate);

    QMap<QTime, WeatherInfo *> forecast() const;
    void setForecast(const QMap<QTime, WeatherInfo *> &newForecast);

signals:


private:
    QDate m_date; //Dette er for å hente en dag


    //Klokkeslett, weather_obj_adresse
    QMap<QTime, WeatherInfo*> m_forecast;

    /*
     * m_forecast{ "09:00": f09304803834}
     * */




};

#endif // DAYINFO_H
