// WeatherLog.h

/**
 * @class WeatherLog
 * @brief Represents a weather log entry with date, time, and weather data.
 *
 * The WeatherLog class represents a weather log entry that includes information such as wind speed,
 * ambient temperature, solar radiation, date, and time. It provides functions to set and retrieve these values.
 *
 * @details The class allows setting and getting wind speed, ambient temperature, and solar radiation values,
 * as well as retrieving the date and time of the weather log entry. The class provides overloads for comparison
 * operators to compare weather log entries based on their date and time.
 *
 * @note The class assumes that the input values for wind speed, ambient temperature, and solar radiation are valid.
 *
 * @author Mohsin Ali Khan
 * @version 04
 * @date 26/07/2023
 *
 * @bug No known bugs to the best of my knowledge.
 */

#ifndef WEATHERLOG_H
#define WEATHERLOG_H

#include <string>
#include <map>
#include "Date.h"
#include "Time.h"

class WeatherLog
{
public:
    /**
     * @brief Default constructor for the WeatherLog class.
     */
    WeatherLog();

    /**
     * @brief Parameterized constructor for the WeatherLog class.
     * @param date The date of the weather log entry.
     * @param time The time of the weather log entry.
     * @param windSpeed The wind speed value of the weather log entry.
     * @param ambientTemperature The ambient temperature value of the weather log entry.
     * @param solarRadiation The solar radiation value of the weather log entry.
     */
    WeatherLog(const Date& date, const Time& time, int windSpeed, float ambientTemperature, float solarRadiation);

    /**
     * @brief Sets the wind speed value of the weather log entry.
     * @param speed The wind speed to set.
     * @return True if the wind speed is valid and set successfully, false otherwise.
     */
    bool SetSpeed(float speed);

    /**
     * @brief Gets the wind speed value of the weather log entry.
     * @return The wind speed value of the weather log entry.
     */
    float GetSpeed() const;

    /**
     * @brief Sets the ambient temperature value of the weather log entry.
     * @param ambientTemperature The ambient temperature to set.
     * @return True if the ambient temperature is valid and set successfully, false otherwise.
     */
    bool SetAmbientTemperature(float ambientTemperature);

    /**
     * @brief Gets the ambient temperature value of the weather log entry.
     * @return The ambient temperature value of the weather log entry.
     */
    float GetAmbientTemperature() const;

    /**
     * @brief Sets the solar radiation value of the weather log entry.
     * @param solarRadiation The solar radiation to set.
     * @return True if the solar radiation is valid and set successfully, false otherwise.
     */
    bool SetSolarRadiation(float solarRadiation);

    /**
     * @brief Gets the solar radiation value of the weather log entry.
     * @return The solar radiation value of the weather log entry.
     */
    float GetSolarRadiation() const;

    /**
     * @brief Gets the date of the weather log entry.
     * @return The date of the weather log entry.
     */
    const Date& GetDate() const;

    /**
     * @brief Gets the time of the weather log entry.
     * @return The time of the weather log entry.
     */
    const Time& GetTime() const;

    /**
     * @brief Overloaded less-than operator for comparing WeatherLog objects.
     * @param other The WeatherLog object to compare with.
     * @return True if this WeatherLog object is less than the other, false otherwise.
     */
    bool operator<(const WeatherLog& other) const;

    /**
     * @brief Overloaded greater-than operator for comparing WeatherLog objects.
     * @param other The WeatherLog object to compare with.
     * @return True if this WeatherLog object is greater than the other, false otherwise.
     */
    bool operator>(const WeatherLog& other) const;

private:
    Date m_date; ///< The date of the weather log entry.
    Time m_time; ///< The time of the weather log entry.
    float m_speed; ///< The wind speed value of the weather log entry.
    float m_ambientTemperature; ///< The ambient temperature value of the weather log entry.
    float m_solarRadiation; ///< The solar radiation value of the weather log entry.
};

#endif // WEATHERLOG_H
