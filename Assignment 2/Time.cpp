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

bool Time::operator<(const Time& other) const
{
    if (m_hours < other.m_hours)
        return true;
    if (m_hours > other.m_hours)
        return false;
    return m_minutes < other.m_minutes;
}

bool Time::operator>(const Time& other) const
{
    return other < *this;
}

bool Time::operator==(const Time& other) const
{
    return m_hours == other.m_hours && m_minutes == other.m_minutes;
}
