#include <iostream>
#include "WeatherLog.h"

void TestWeatherLogDefaultConstructor();
void TestWeatherLogNonDefaultConstructor();
void TestWeatherLogSetSpeed();
void TestWeatherLogSetAmbientTemperature();
void TestWeatherLogSetSolarRadiation();

void TestWeatherLogDefaultConstructor()
{
    std::cout << "-- Testing WeatherLog Default Constructor --\n";
    WeatherLog weatherLog;
    std::cout << "Speed: " << weatherLog.GetSpeed() << std::endl;
    std::cout << "Ambient Temperature: " << weatherLog.GetAmbientTemperature() << std::endl;
    std::cout << "Solar Radiation: " << weatherLog.GetSolarRadiation() << std::endl;
}

void TestWeatherLogNonDefaultConstructor()
{
    std::cout << "-- Testing WeatherLog Non-Default Constructor --\n";
    Date date; // Create a Date object with default constructor
    Time time; // Create a Time object with default constructor
    int windSpeed = 15; // Update to int type
    float ambientTemperature = 25.0f;
    float solarRadiation = 1000.0f;
    WeatherLog weatherLog(date, time, windSpeed, ambientTemperature, solarRadiation); // Pass windSpeed by value
    std::cout << "Speed: " << weatherLog.GetSpeed() << std::endl;
    std::cout << "Ambient Temperature: " << weatherLog.GetAmbientTemperature() << std::endl;
    std::cout << "Solar Radiation: " << weatherLog.GetSolarRadiation() << std::endl;
}

void TestWeatherLogSetSpeed()
{
    std::cout << "-- Testing WeatherLog SetSpeed() --\n";
    WeatherLog weatherLog;
    float speed = 15.5f;
    if (weatherLog.SetSpeed(speed))
        std::cout << "Speed set successfully: " << weatherLog.GetSpeed() << std::endl;
    else
        std::cout << "Invalid speed. Speed not set.\n";
}

void TestWeatherLogSetAmbientTemperature()
{
    std::cout << "-- Testing WeatherLog SetAmbientTemperature() --\n";
    WeatherLog weatherLog;
    float ambientTemperature = 25.0f;
    if (weatherLog.SetAmbientTemperature(ambientTemperature))
        std::cout << "Ambient temperature set successfully: " << weatherLog.GetAmbientTemperature() << std::endl;
    else
        std::cout << "Invalid ambient temperature. Ambient temperature not set.\n";
}

void TestWeatherLogSetSolarRadiation()
{
    std::cout << "-- Testing WeatherLog SetSolarRadiation() --\n";
    WeatherLog weatherLog;
    float solarRadiation = 1000.0f;
    if (weatherLog.SetSolarRadiation(solarRadiation))
        std::cout << "Solar radiation set successfully: " << weatherLog.GetSolarRadiation() << std::endl;
    else
        std::cout << "Invalid solar radiation. Solar radiation not set.\n";
}

int main()
{
    TestWeatherLogDefaultConstructor();
    std::cout << std::endl;
    TestWeatherLogNonDefaultConstructor();
    std::cout << std::endl;
    TestWeatherLogSetSpeed();
    std::cout << std::endl;
    TestWeatherLogSetAmbientTemperature();
    std::cout << std::endl;
    TestWeatherLogSetSolarRadiation();

    return 0;
}
