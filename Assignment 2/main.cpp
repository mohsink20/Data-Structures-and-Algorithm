#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <chrono>
#include <thread>

#include "WeatherLog.h"
#include "Parse.h"
#include "BST.h"

float CalculateAverage(BST<float>& bst);
float CalculateTotal(BST<float>& bst);
float CalculateStandardDeviation(BST<float>& values);
void PrintAverageWindSpeedAndStandardDeviation(const std::map<std::string, WeatherLog>& logs, unsigned int month, unsigned int year);
void PrintAverageTemperatureAndStandardDeviation(const std::map<std::string, WeatherLog>& logs, unsigned int year);
void PrintTotalSolarRadiationByYear(const std::map<std::string, WeatherLog>& logs, unsigned int year);
void WriteDataToFile(const std::map<std::string, WeatherLog>& logs, unsigned int year);
bool ValidateInput(const std::string& input, int& value);
void ReadDataFiles(std::map<std::string, WeatherLog>& weatherLogs);
float CalculateSPearsonCorrelationCoefficient(BST<float>& x, BST<float>& y);
void CalculatePearsonCorrelationCoefficient(const std::map<std::string, WeatherLog>& logs, unsigned int month) ;


int main()
{
    std::map<std::string, WeatherLog> weatherLogs;
    std::vector<WeatherLog> logVector;

    ReadDataFiles(weatherLogs);

    for (auto& logEntry : weatherLogs)
    {
        logVector.push_back(logEntry.second);
    }
    const int ExitOption = 6;
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
        std::cout << "3. Sample Pearson Correlation Coefficient for user specified month (print on screen only)" << std::endl;
        std::cout << "4. Average wind speed (km/h), average ambient air temperature, and total solar radiation in kWh/m2 for each month of a specified year. The standard deviation is printed in () next to the average (write to a file called 'WindTempSolar.csv')" << std::endl;
        std::cout << "5. Total solar radiation in kWh/m2 for each month of a specified year (print on screen only)" << std::endl;
        std::cout << "6. Exit the program." << std::endl;
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
            std::cout << "Enter month (1-12): ";
            std::cin >> input;
            if(!ValidateInput(input, selectedMonth) || selectedMonth < 1 || selectedMonth > 12)
            {
                std::cout << "Invalid month, please try again." << std::endl;
                break;
            }

            CalculatePearsonCorrelationCoefficient(weatherLogs, selectedMonth);
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

        case 5:
            std::cout << "Enter year: ";
            std::cin >> input;
            if (!ValidateInput(input, selectedYear) || selectedYear < 0)
            {
                std::cout << "Invalid year. Please try again." << std::endl;
                break;
            }
            PrintTotalSolarRadiationByYear(weatherLogs, selectedYear);
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

void ReadDataFiles(std::map<std::string, WeatherLog>& weatherLogs)
{
    std::ifstream sourceFile("data/data_source.txt");
    if (!sourceFile)
    {
        std::cout << "Failed to open data_source.txt." << std::endl;
        return;
    }

    std::string csvFileName;
    int fileCount = 0;
    int totalFiles = 0;

    std::string line;
    while (std::getline(sourceFile, csvFileName))
    {
        totalFiles++;
    }
    sourceFile.close();

    sourceFile.open("data/data_source.txt");

    while (std::getline(sourceFile, csvFileName))
    {
        std::ifstream csvFile("data/" + csvFileName);
        if (!csvFile)
        {
            std::cout << "Failed to open data/" << csvFileName << std::endl;
            continue;
        }

        std::cout << "Loading data from " << csvFileName << " (" << (++fileCount) << "/" << totalFiles << ")" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::string line2;
        while (std::getline(csvFile, line))
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

            std::string timestamp = std::to_string(year) + std::to_string(month) + std::to_string(day) + std::to_string(hour) + std::to_string(minute);
            Date date(day, month, year);
            Time time(hour, minute);

            WeatherLog log(date, time, windSpeed, ambientTemperature, solarRadiation);
            weatherLogs[timestamp] = log;
        }

        csvFile.close();
    }

    std::cout << "Data loading completed!" << std::endl;
    sourceFile.close();
}

bool ValidateInput(const std::string& input, int& value)
{
    try
    {
        value = std::stoi(input);
        return true;
    }
    catch (const std::exception& e)
    {
        return false;
    }
}
float CalculateAverage(BST<float>& bst)
{
    if (bst.size() == 0)
        return 0.0f;

    float sum = 0.0f;
    bst.InOrder([&sum](float& value)
    {
        sum += value;
    });

    return sum / static_cast<float>(bst.size());
}

float CalculateTotal(BST<float>& bst)
{
    float total = 0.0f;
    bst.InOrder([&total](float& value)
    {
        total += value;
    });

    return total;
}

float CalculateStandardDeviation(BST<float>& bst)
{
    if (bst.size() == 0)
        return 0.0f;

    float mean = CalculateAverage(bst);
    float variance = 0.0f;
    bst.InOrder([&mean, &variance](float& value)
    {
        float diff = value - mean;
        variance += diff * diff;
    });

    variance /= static_cast<float>(bst.size());
    return std::sqrt(variance);
}

void PrintAverageWindSpeedAndStandardDeviation(const std::map<std::string, WeatherLog>& logs, unsigned int month, unsigned int year)
{
    BST<float> windSpeeds;

    for (const auto& logEntry : logs)
    {
        const WeatherLog& log = logEntry.second;
        if (log.GetDate().GetMonth() == month && log.GetDate().GetYear() == year)
        {
            float speed = log.GetSpeed();
            windSpeeds.Insert(speed);
        }
    }

    if (windSpeeds.size() != 0)
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

void PrintAverageTemperatureAndStandardDeviation(const std::map<std::string, WeatherLog>& logs, unsigned int year)
{
    for (unsigned int month = 1; month <= 12; month++)
    {
        BST<float> temperatures;
        bool hasData = false;

        for (const auto& logEntry : logs)
        {
            const WeatherLog& log = logEntry.second;
            if (log.GetDate().GetYear() == year && log.GetDate().GetMonth() == month)
            {
                float temp = log.GetAmbientTemperature();
                temperatures.Insert(temp);
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

void PrintTotalSolarRadiationByYear(const std::map<std::string, WeatherLog>& logs, unsigned int year)
{
    float solarRadiations[12] = {0.0f};

    for (const auto& logEntry : logs)
    {
        const WeatherLog& log = logEntry.second;
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

void WriteDataToFile(const std::map<std::string, WeatherLog>& logs, unsigned int year)
{
    std::ofstream outputFile("WindTempSolar.csv");

    if (outputFile.is_open())
    {
        outputFile << "Year\n";

        bool hasData = false;

        for (unsigned int month = 1; month <= 12; ++month)
        {
            BST<float> windSpeeds;
            BST<float> temperatures;
            BST<float> solarRadiations;

            for (const auto& logEntry : logs)
            {
                const WeatherLog& log = logEntry.second;
                if (log.GetDate().GetYear() == year && log.GetDate().GetMonth() == month)
                {
                    float speed = log.GetSpeed();
                    windSpeeds.Insert(speed);

                    float temp = log.GetAmbientTemperature();
                    temperatures.Insert(temp);

                    float solar = log.GetSolarRadiation();
                    solarRadiations.Insert(solar);
                }
            }

            if (windSpeeds.size() != 0 && temperatures.size() != 0 && solarRadiations.size() != 0)
            {
                hasData = true;
                float averageWindSpeed = CalculateAverage(windSpeeds);
                float averageTemperature = CalculateAverage(temperatures);
                float totalSolarRadiation = CalculateTotal(solarRadiations);
                float windSpeedStdDev = CalculateStandardDeviation(windSpeeds);
                float temperatureStdDev = CalculateStandardDeviation(temperatures);

                outputFile << Date::MonthToString(month) << "," << averageWindSpeed << "(" << windSpeedStdDev << ")," << averageTemperature << "(" << temperatureStdDev << ")," << totalSolarRadiation << "\n";
            }
            else
            {
                outputFile << Date::MonthToString(month) << ",No Data\n";
            }
        }

        if (!hasData)
        {
            std::cout << "No data available for the specified year." << std::endl;
        }

        outputFile.close();
    }
    else
    {
        std::cout << "Unable to open the file 'WindTempSolar.csv' for writing." << std::endl;
    }
}
void CalculatePearsonCorrelationCoefficient(const std::map<std::string, WeatherLog>& logs, unsigned int month)
{
    BST<float> windSpeeds;
    BST<float> temperatures;
    BST<float> solarRadiations;

    for(const auto& log : logs)
    {
        if(log.second.GetDate().GetMonth() == month)
        {

            float speed = log.second.GetSpeed();
            windSpeeds.Insert(speed);

            float temp = log.second.GetAmbientTemperature();
            temperatures.Insert(temp);

            float solar = log.second.GetSolarRadiation();
            solarRadiations.Insert(solar);
        }
    }


    float S_T = CalculateSPearsonCorrelationCoefficient(windSpeeds, temperatures);
    float S_R = CalculateSPearsonCorrelationCoefficient(windSpeeds, solarRadiations);
    float T_R = CalculateSPearsonCorrelationCoefficient(temperatures, solarRadiations);

    std::cout << "Sample Pearson Correlation Coefficient for " << Date::MonthToString(month) << ":" << std::endl;
    std::cout << "S_T: " << S_T << std::endl;
    std::cout << "S_R: " << S_R << std::endl;
    std::cout << "T_R: " << T_R << std::endl;
}

float CalculateSPearsonCorrelationCoefficient(BST<float>& x, BST<float>& y)
{

    float xMean = CalculateAverage(x);
    float yMean = CalculateAverage(y);

    float sumNumerator = 0.0;
    float sumXDenominator = 0.0;
    float sumYDenominator = 0.0;

    x.InOrder([&](float xVal)
    {
        float xDiff = xVal - xMean;
        sumXDenominator += xDiff * xDiff;
    });

    y.InOrder([&](float yVal)
    {
        float yDiff = yVal - yMean;
        sumYDenominator += yDiff * yDiff;
    });

    x.InOrder([&](float xVal)
    {
        float xDiff = xVal - xMean;

        y.InOrder([&](float yVal)
        {
            float yDiff = yVal - yMean;
            sumNumerator += xDiff * yDiff;
        });
    });

    float denominator = sqrt(sumXDenominator) * sqrt(sumYDenominator);
    if(denominator == 0)
        return 0;

    return sumNumerator / denominator;
}
