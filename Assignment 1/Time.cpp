#include "Time.h"

Time::Time() : m_hours(0), m_minutes(0) {}

Time::Time(unsigned hours, unsigned minutes)
    : m_hours(hours), m_minutes(minutes) {}

bool Time::SetHours(unsigned hours)
{
    if (hours < 24)
    {
        m_hours = hours;
        return true;
    }
    else
    {
        m_hours = 0;
        return false;
    }
}

unsigned Time::GetHours() const
{
    return m_hours;
}

bool Time::SetMinutes(unsigned minutes)
{
    if (minutes < 60)
    {
        m_minutes = minutes;
        return true;
    }
    else
    {
        m_minutes = 0;
        return false;
    }
}

unsigned Time::GetMinutes() const
{
    return m_minutes;
}

std::string Time::TimeToString() const
{
    std::string timeStr = "";
    if (m_hours < 10)
        timeStr += "0";
    timeStr += std::to_string(m_hours) + ":";

    if (m_minutes < 10)
        timeStr += "0";
    timeStr += std::to_string(m_minutes);

    return timeStr;
}
