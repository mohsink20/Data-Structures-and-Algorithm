#include "Parse.h"

Parse::Parse() : day(0), month(0), year(0), hour(0), minutes(0), windS(0), solarR(0), ambientT(0)
{
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    minutes = 0;
    windS = 0;
    solarR = 0;
    ambientT = 0;
}

Parse::~Parse()
{
}

void Parse::ParseLog(std::string line)
{
    std::stringstream ss(line);
    std::string d, t, skip, wS, sR, aT;
    getline(ss, d, ' ');
    ParseDate(d);
    getline(ss, t, ',');
    ParseTime(t);
    for (int i = 0; i < 9; i++)
    {
        getline(ss, skip, ',');
    }
    getline(ss, wS, ',');
    windS = StringToInt(wS);
    getline(ss, sR, ',');
    solarR = StringToFloat(sR);
    for (int i = 0; i < 5; i++)
    {
        getline(ss, skip, ',');
    }
    getline(ss, aT, '\n');
    ambientT = StringToFloat(aT);
}

void Parse::ParseDate(std::string date)
{
    std::string d, m, y;
    std::stringstream ssdate(date);
    getline(ssdate, d, '/');
    day = StringToInt(d);
    getline(ssdate, m, '/');
    month = StringToInt(m);
    getline(ssdate, y, ' ');
    year = StringToInt(y);
}

void Parse::ParseTime(std::string time)
{
    std::string h, m;
    std::stringstream sstime(time);
    getline(sstime, h, ':');
    hour = StringToInt(h);
    getline(sstime, m, ',');
    minutes = StringToInt(m);
}

int Parse::StringToInt(std::string line)
{
    int i;
    std::stringstream ss(line);
    ss >> i;

    return i;
}

float Parse::StringToFloat(std::string line)
{
    float f;
    std::stringstream ss(line);
    ss >> f;

    return f;
}

unsigned int Parse::GetParseDay()
{
    return day;
}

unsigned int Parse::GetParseMonth()
{
    return month;
}

unsigned int Parse::GetParseYear()
{
    return year;
}

unsigned int Parse::GetParseHour()
{
    return hour;
}

unsigned int Parse::GetParseMinutes()
{
    return minutes;
}

int Parse::GetParseWS()
{
    return windS;
}

float Parse::GetParseSR()
{
    return solarR;
}

float Parse::GetParseAT()
{
    return ambientT;
}
