#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "WeatherLog.h"
#include "Vector.h"
#include "Parse.h"

float CalculateAverage(const Vector<float>& vec);
float CalculateTotal(const Vector<float>& vec);
float CalculateStandardDeviation(const Vector<float>& values);
void PrintAverageWindSpeedAndStandardDeviation(const Vector<WeatherLog>& logs, unsigned int month, unsigned int year);
void PrintAverageTemperatureAndStandardDeviation(const Vector<WeatherLog>& logs, unsigned int year);
void PrintTotalSolarRadiationByYear(const Vector<WeatherLog>& logs, unsigned int year);
void WriteDataToFile(const Vector<WeatherLog>& logs, unsigned int year);
bool ValidateInput(const std::string& input, int& value);


int main()
{
    Vector<WeatherLog> weatherLogs;
    std::ifstream inputFile("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    if (!inputFile)
    {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        Parse parser;
        parser.ParseLog(line);

        unsigned int day = parser.GetParseDay();
        unsigned int month = parser.GetParseMonth();
        unsigned int year = parser.GetParseYear();
        unsigned int hour = parser.GetParseHour();
        unsigned int minute = parser.GetParseMinutes();
        int windSpeed = parser.GetParseWS();
        float solarRadiation = parser.GetParseSR();
        float ambientTemperature = parser.GetParseAT();

        Date date(day, month, year);
        Time time(hour, minute);

        WeatherLog log(date, time, windSpeed, ambientTemperature, solarRadiation);
        weatherLogs.PushBack(log);
    }
    inputFile.close();

    const int ExitOption = 5;
    int selectedOption;
    int selectedYear;
    int selectedMonth;

    do
    {
        std::cout << "======================================================================================================================" << std::endl;
        std::cout << "                                                   MENU        " << std::endl;
        std::cout << "======================================================================================================================" << std::endl;
        std::cout << "Menu options:" << std::endl;
        std::cout << "1. The average wind speed and sample standard deviation for a specified month and year (print on screen only)" << std::endl;
        std::cout << "2. Average ambient air temperature and sample standard deviation for each month of a specified year (print on screen only)" << std::endl;
        std::cout << "3. Total solar radiation in kWh/m2 for each month of a specified year (print on screen only)" << std::endl;
        std::cout << "4. Average wind speed (km/h), average ambient air temperature, and total solar radiation in kWh/m2 for each month of a specified year. The standard deviation is printed in () next to the average (write to a file called 'WindTempSolar.csv')" << std::endl;
        std::cout << "5. Exit the program." << std::endl;
        std::cout << "======================================================================================================================" << std::endl;
        std::cout << "Enter option: ";
        std::string input;
        std::cin >> input;

        if (!ValidateInput(input, selectedOption))
        {
            std::cout << "Invalid option. Please try again." << std::endl;
            continue;
        }

        switch (selectedOption)
        {
        case 1:
            std::cout << "Enter month (1-12): ";
            std::cin >> input;
            if (!ValidateInput(input, selectedMonth) || selectedMonth < 1 || selectedMonth > 12)
            {
                std::cout << "Invalid month. Please try again." << std::endl;
                break;
            }
            std::cout << "Enter year: ";
            std::cin >> input;
            if (!ValidateInput(input, selectedYear) || selectedYear < 0)
            {
                std::cout << "Invalid year. Please try again." << std::endl;
                break;
            }
            PrintAverageWindSpeedAndStandardDeviation(weatherLogs, selectedMonth, selectedYear);
            break;

        case 2:
            std::cout << "Enter year: ";
            std::cin >> input;
            if (!ValidateInput(input, selectedYear) || selectedYear < 0)
            {
                std::cout << "Invalid year. Please try again." << std::endl;
                break;
            }
            PrintAverageTemperatureAndStandardDeviation(weatherLogs, selectedYear);
            break;

        case 3:
            std::cout << "Enter year: ";
            std::cin >> input;
            if (!ValidateInput(input, selectedYear) || selectedYear < 0)
            {
                std::cout << "Invalid year. Please try again." << std::endl;
                break;
            }
            PrintTotalSolarRadiationByYear(weatherLogs, selectedYear);
            break;

        case 4:
            std::cout << "Enter year: ";
            std::cin >> input;
            if (!ValidateInput(input, selectedYear) || selectedYear < 0)
            {
                std::cout << "Invalid year. Please try again." << std::endl;
                break;
            }
            WriteDataToFile(weatherLogs, selectedYear);
            std::cout << "Data written to file 'WindTempSolar.csv'." << std::endl;
            break;

        case ExitOption:
            std::cout << "Exiting the program....." << std::endl;
            break;

        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }
    while (selectedOption != ExitOption);
    return 0;
}

bool ValidateInput(const std::string& input, int& value)
{
    try
    {
        size_t pos;
        value = std::stoi(input, &pos);

        if (pos != input.length())
            return false;

        if (value < 0)
            return false;

        return true;
    }
    catch (...)
    {
        return false;
    }
}

float CalculateAverage(const Vector<float>& vec)
{
    float sum = 0.0f;
    for (size_t i = 0; i < vec.Size(); i++)
    {
        sum += vec[i];
    }
    return sum / static_cast<float>(vec.Size());
}

float CalculateTotal(const Vector<float>& vec)
{
    float total = 0.0f;
    for (size_t i = 0; i < vec.Size(); i++)
    {
        total += vec[i];
    }
    return total;
}

float CalculateStandardDeviation(const Vector<float>& values)
{
    float mean = CalculateAverage(values);
    float variance = 0.0f;
    for (size_t i = 0; i < values.Size(); i++)
    {
        float diff = values[i] - mean;
        variance += diff * diff;
    }
    variance /= static_cast<float>(values.Size());
    return std::sqrt(variance);
}


void PrintAverageWindSpeedAndStandardDeviation(const Vector<WeatherLog>& logs, unsigned int month, unsigned int year)
{
    Vector<float> windSpeeds;

    for (size_t i = 0; i < logs.Size(); i++)
    {
        WeatherLog log = logs[i];
        if (log.GetDate().GetMonth() == month && log.GetDate().GetYear() == year)
        {
            windSpeeds.PushBack(log.GetSpeed());
        }
    }

    if (windSpeeds.Size() > 0)
    {
        float averageWindSpeed = CalculateAverage(windSpeeds);
        float standardDeviation = CalculateStandardDeviation(windSpeeds);

        std::cout << Date::MonthToString(month) << " " << year << ":" << std::endl;
        std::cout << "Average Wind Speed: " << averageWindSpeed << " km/h" << std::endl;
        std::cout << "Sample Standard Deviation: " << standardDeviation << std::endl;
    }
    else
    {
        std::cout << Date::MonthToString(month) << " " << year << ": No Data" << std::endl;
    }
}


void PrintAverageTemperatureAndStandardDeviation(const Vector<WeatherLog>& logs, unsigned int year)
{
    for (unsigned int month = 1; month <= 12; month++)
    {
        Vector<float> temperatures;
        bool hasData = false;

        for (size_t i = 0; i < logs.Size(); i++)
        {
            WeatherLog log = logs[i];
            if (log.GetDate().GetYear() == year && log.GetDate().GetMonth() == month)
            {
                temperatures.PushBack(log.GetAmbientTemperature());
                hasData = true;
            }
        }

        std::cout << Date::MonthToString(month) << " " << year << ":" << std::endl;

        if (hasData)
        {
            float averageTemperature = CalculateAverage(temperatures);
            float standardDeviation = CalculateStandardDeviation(temperatures);

            std::cout << "Average temperature: " << averageTemperature << " degrees Celsius" << std::endl;
            std::cout << "Standard deviation of temperature: " << standardDeviation << std::endl;
        }
        else
        {
            std::cout << "No Data" << std::endl;
        }

        std::cout << std::endl;
    }
}


void PrintTotalSolarRadiationByYear(const Vector<WeatherLog>& logs, unsigned int year)
{

    float solarRadiations[12] = {0.0f};

    for (size_t i = 0; i < logs.Size(); i++)
    {
        WeatherLog log = logs[i];
        if (log.GetDate().GetYear() == year)
        {
            unsigned int month = log.GetDate().GetMonth();
            solarRadiations[month - 1] += log.GetSolarRadiation();
        }
    }


    for (unsigned int month = 1; month <= 12; month++)
    {
        std::cout << Date::MonthToString(month) << ": ";
        if (solarRadiations[month - 1] > 0.0f)
        {
            float solarRadiationInKWh = solarRadiations[month - 1] / 3.6f;
            std::cout << solarRadiationInKWh << " kWh/m2" << std::endl;
        }
        else
        {
            std::cout << "No Data" << std::endl;
        }
    }
}

void WriteDataToFile(const Vector<WeatherLog>& logs, unsigned int year)
{
    std::ofstream outputFile("WindTempSolar.csv");

    if (outputFile.is_open())
    {
        outputFile << "Year\n";


        bool hasData = false;

        for (unsigned int month = 1; month <= 12; ++month)
        {
            Vector<float> windSpeeds;
            Vector<float> temperatures;
            Vector<float> solarRadiations;

            for (size_t i = 0; i < logs.Size(); ++i)
            {
                WeatherLog log = logs[i];
                if (log.GetDate().GetYear() == year && log.GetDate().GetMonth() == month)
                {
                    windSpeeds.PushBack(log.GetSpeed());
                    temperatures.PushBack(log.GetAmbientTemperature());
                    solarRadiations.PushBack(log.GetSolarRadiation());
                }
            }

            if (windSpeeds.Size() > 0 && temperatures.Size() > 0 && solarRadiations.Size() > 0)
            {
                hasData = true;
                float averageWindSpeed = CalculateAverage(windSpeeds);
                float averageTemperature = CalculateAverage(temperatures);
                float totalSolarRadiation = CalculateTotal(solarRadiations);
                float windSpeedStdDev = CalculateStandardDeviation(windSpeeds);
                float temperatureStdDev = CalculateStandardDeviation(temperatures);

                outputFile << Date::MonthToString(month) << "," << averageWindSpeed << "(" << windSpeedStdDev << "),"
                           << averageTemperature << "(" << temperatureStdDev << ")," << totalSolarRadiation << "\n";
            }
        }

        if (!hasData)
        {
            outputFile << year << "\nNo Data\n";
        }

        outputFile.close();
    }
    else
    {
        std::cout << "Unable to open the output file." << std::endl;
    }
}

