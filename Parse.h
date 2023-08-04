/**
 * @class Parse
 * @brief
 *
 *
 *
 *
 * @author Mohsin Ali Khan
 * @version 02
 * @date 11/06/2023
 *
 * @bug No known bugs to the best of my knowledge
 */

#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <iostream>
#include <sstream>

/**
 * @class Parse
 * @brief A class for parsing log data.
 */
class Parse
{
public:
    /**
     * @brief Default constructor for Parse.
     */
    Parse();

    /**
     * @brief Destructor for Parse.
     */
    ~Parse();

    /**
     * @brief Parses a log line.
     * @param line The log line to parse.
     */
    void ParseLog(std::string line);

    /**
     * @brief Parses a date string.
     * @param date The date string to parse.
     */
    void ParseDate(std::string date);

    /**
     * @brief Parses a time string.
     * @param time The time string to parse.
     */
    void ParseTime(std::string time);

    /**
     * @brief Converts a string to an integer.
     * @param line The string to convert.
     * @return The converted integer value.
     */
    int StringToInt(std::string line);

    /**
     * @brief Converts a string to a float.
     * @param line The string to convert.
     * @return The converted float value.
     */
    float StringToFloat(std::string line);

    /**
     * @brief Gets the parsed day.
     * @return The parsed day.
     */
    unsigned int GetParseDay();

    /**
     * @brief Gets the parsed month.
     * @return The parsed month.
     */
    unsigned int GetParseMonth();

    /**
     * @brief Gets the parsed year.
     * @return The parsed year.
     */
    unsigned int GetParseYear();

    /**
     * @brief Gets the parsed hour.
     * @return The parsed hour.
     */
    unsigned int GetParseHour();

    /**
     * @brief Gets the parsed minutes.
     * @return The parsed minutes.
     */
    unsigned int GetParseMinutes();

    /**
     * @brief Gets the parsed wind speed.
     * @return The parsed wind speed.
     */
    int GetParseWS();

    /**
     * @brief Gets the parsed solar radiation.
     * @return The parsed solar radiation.
     */
    float GetParseSR();

    /**
     * @brief Gets the parsed ambient temperature.
     * @return The parsed ambient temperature.
     */
    float GetParseAT();

private:
    unsigned int day;     ///< Parsed day.
    unsigned int month;   ///< Parsed month.
    unsigned int year;    ///< Parsed year.
    unsigned int hour;    ///< Parsed hour.
    unsigned int minutes; ///< Parsed minutes.
    int windS;            ///< Parsed wind speed.
    float solarR;         ///< Parsed solar radiation.
    float ambientT;       ///< Parsed ambient temperature.
};

#endif // PARSE_H
