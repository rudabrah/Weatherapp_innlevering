//dayinfo.cpp

#include "dayinfo.h"

DayInfo::DayInfo(QObject *parent)
    : QObject{parent}
{

}

QDate DayInfo::date() const
{
    return m_date;
}

void DayInfo::setDate(const QDate &newDate)
{
    m_date = newDate;
}

QMap<QTime, WeatherInfo *> DayInfo::forecast() const
{
    return m_forecast;
}

void DayInfo::setForecast(const QMap<QTime, WeatherInfo *> &newForecast)
{
    m_forecast = newForecast;
}
