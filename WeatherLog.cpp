#include "WeatherLog.h"

WeatherLog::WeatherLog() : m_date(), m_time(), m_speed(0.0f), m_ambientTemperature(0.0f), m_solarRadiation(0.0f)
{
}

WeatherLog::WeatherLog(Date& date, Time& time, int& windSpeed, float& ambientTemperature, float& solarRadiation)
    : m_date(date), m_time(time), m_speed(windSpeed), m_ambientTemperature(ambientTemperature), m_solarRadiation(solarRadiation)
{
}

bool WeatherLog::SetSpeed(float speed)
{
    if (speed > 0.0f)
    {
        m_speed = speed;
        return true;
    }
    else
    {
        m_speed = 0.0f;
        return false;
    }
}

float WeatherLog::GetSpeed() const
{
    return m_speed;
}

bool WeatherLog::SetAmbientTemperature(float ambientTemperature)
{
    m_ambientTemperature = ambientTemperature;
    return true;
}

float WeatherLog::GetAmbientTemperature() const
{
    return m_ambientTemperature;
}

bool WeatherLog::SetSolarRadiation(float solarRadiation)
{
    if (solarRadiation > 0.0f)
    {
        m_solarRadiation = solarRadiation;
        return true;
    }
    else
    {
        m_solarRadiation = 0.0f;
        return false;
    }
}

float WeatherLog::GetSolarRadiation() const
{
    return m_solarRadiation;
}

const Date& WeatherLog::GetDate() const
{
    return m_date;
}

const Time& WeatherLog::GetTime() const
{
    return m_time;
}
