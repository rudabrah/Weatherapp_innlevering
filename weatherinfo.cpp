//weatherinfo.cpp

#include "weatherinfo.h"

WeatherInfo::WeatherInfo(QObject *parent)
    : QObject{parent}
{

}

double WeatherInfo::temp_cel() const
{
    return m_temp_cel;
}

void WeatherInfo::setTemp_cel(double newTemp_cel)
{
    m_temp_cel = newTemp_cel;
}

int WeatherInfo::getTemp()
{
    return m_temp_cel;
}

QString WeatherInfo::url() const
{
    return m_url;
}

void WeatherInfo::setUrl(const QString &newUrl)
{
    m_url = newUrl;
}

QString WeatherInfo::description() const
{
    return m_description;
}

void WeatherInfo::setDescription(const QString &newDescription)
{
    m_description = newDescription;
}
//Ikke vær helt sikker på denne..
QString WeatherInfo::getDescription()
{
    return m_description;
}

QString WeatherInfo::iconUrl() const
{
    return m_iconUrl;
}

void WeatherInfo::setIconUrl(const QString &newIconUrl)
{
    m_iconUrl = newIconUrl;
}
