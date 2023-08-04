// Parse.h

/**
 * @class Parse
 * @brief Parses weather log data and extracts relevant information.
 *
 * The Parse class is responsible for parsing weather log data and extracting
 * relevant information such as date, time, wind speed, solar radiation, and ambient temperature.
 * It provides functions to convert strings to integer and floating-point numbers.
 *
 * @note The class assumes that the input data follows a specific format, and deviations from the format may lead to undefined behavior.
 *
 * @details The Parse class reads and interprets weather log data, which contains information about various weather measurements.
 * It extracts date, time, wind speed, solar radiation, and ambient temperature from the log data and stores them for further processing.
 * The class offers functions to parse the date and time strings, converting them into separate day, month, year, hour, and minute components.
 * It also provides functions to convert strings to integer and floating-point numbers for the wind speed, solar radiation, and ambient temperature.
 *
 * @author Mohsin Ali Khan
 * @version 04
 * @date 26/07/2023
 *
 * @bug No known bugs to the best of my knowledge.
 */

#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include "Date.h"
#include "Time.h"
#include "BST.h"
#include "WeatherLog.h"

class Parse
{
public:
    /**
     * @brief Default constructor for the Parse class.
     */
    Parse();

    /**
     * @brief Destructor for the Parse class.
     */
    ~Parse();

    /**
     * @brief Parses a single line of weather log data.
     * @param line The line of weather log data to parse.
     */
    void ParseLog(std::string line);

    /**
     * @brief Parses a date string and sets the date components.
     * @param date The date string to be parsed.
     */
    void ParseDate(const std::string& date);

    /**
     * @brief Parses a time string and sets the time components.
     * @param time The time string to be parsed.
     */
    void ParseTime(std::string time);

    /**
     * @brief Converts a string to an integer.
     * @param line The string to be converted.
     * @return The integer value of the string.
     */
    int StringToInt(std::string line);

    /**
     * @brief Converts a string to a floating-point number.
     * @param line The string to be converted.
     * @return The floating-point value of the string.
     */
    float StringToFloat(std::string line);

    /**
     * @brief Gets the parsed day value.
     * @return The parsed day value.
     */
    unsigned int GetParseDay();

    /**
     * @brief Gets the parsed month value.
     * @return The parsed month value.
     */
    unsigned int GetParseMonth();

    /**
     * @brief Gets the parsed year value.
     * @return The parsed year value.
     */
    unsigned int GetParseYear();

    /**
     * @brief Gets the parsed hour value.
     * @return The parsed hour value.
     */
    unsigned int GetParseHour();

    /**
     * @brief Gets the parsed minutes value.
     * @return The parsed minutes value.
     */
    unsigned int GetParseMinutes();

    /**
     * @brief Gets the parsed wind speed value.
     * @return The parsed wind speed value.
     */
    int GetParseWS();

    /**
     * @brief Gets the parsed solar radiation value.
     * @return The parsed solar radiation value.
     */
    float GetParseSR();

    /**
     * @brief Gets the parsed ambient temperature value.
     * @return The parsed ambient temperature value.
     */
    float GetParseAT();

private:
    unsigned int day; ///< Parsed day value.
    unsigned int month; ///< Parsed month value.
    unsigned int year; ///< Parsed year value.
    unsigned int hour; ///< Parsed hour value.
    unsigned int minutes; ///< Parsed minutes value.
    int windS; ///< Parsed wind speed value.
    float solarR; ///< Parsed solar radiation value.
    float ambientT; ///< Parsed ambient temperature value.

    std::map<std::string, WeatherLog> logMap; ///< Map to store weather log data.
    std::vector<WeatherLog> logVector; ///< Vector to store weather log data.
};

#endif // PARSE_H
