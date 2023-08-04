#include "Date.h"

Date::Date() : m_day(0), m_month(0), m_year(0) {}

Date::Date(unsigned day, unsigned month, unsigned year)
    : m_day(day), m_month(month), m_year(year) {}

bool Date::SetDay(unsigned day)
{
    if (day > 0 && day <= 31)
    {
        m_day = day;
        return true;
    }
    else
    {
        m_day = 0;
        return false;
    }
}

unsigned Date::GetDay() const
{
    return m_day;
}

bool Date::SetMonth(unsigned month)
{
    if (month > 0 && month <= 12)
    {
        m_month = month;
        return true;
    }
    else
    {
        m_month = 0;
        return false;
    }
}

unsigned int Date::GetMonth() const
{
    return m_month;
}

bool Date::SetYear(unsigned year)
{
    if (year > 0)
    {
        m_year = year;
        return true;
    }
    else
    {
        m_year = 0;
        return false;
    }
}

unsigned int Date::GetYear() const
{
    return m_year;
}

std::string Date::MonthToString(unsigned month)
{
    std::string mon;
    switch (month)
    {
    case 1:
        mon = "January";
        break;
    case 2:
        mon = "February";
        break;
    case 3:
        mon = "March";
        break;
    case 4:
        mon = "April";
        break;
    case 5:
        mon = "May";
        break;
    case 6:
        mon = "June";
        break;
    case 7:
        mon = "July";
        break;
    case 8:
        mon = "August";
        break;
    case 9:
        mon = "September";
        break;
    case 10:
        mon = "October";
        break;
    case 11:
        mon = "November";
        break;
    case 12:
        mon = "December";
        break;
    default:
        mon = "Null";
    }
    return mon;
}

std::string Date::DateToString() const
{
    return std::to_string(m_day) + " " + std::to_string(m_month) + " " + std::to_string(m_year);
}

bool Date::operator<(const Date& other) const
{
    if (m_year < other.m_year)
        return true;
    if (m_year > other.m_year)
        return false;
    if (m_month < other.m_month)
        return true;
    if (m_month > other.m_month)
        return false;
    return m_day < other.m_day;
}

bool Date::operator>(const Date& other) const
{
    return other < *this;
}

bool Date::operator==(const Date& other) const
{
    return m_day == other.m_day && m_month == other.m_month && m_year == other.m_year;
}
