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
