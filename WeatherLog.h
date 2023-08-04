/**
 * @class WeatherLog
 * @brief Represents a weather log entry with date, time, and weather data.
 *
 * This class represents a weather log entry, which includes information such as speed,
 * ambient temperature, solar radiation, date, and time. It provides functions to set and
 * retrieve these values.
 *
 * @author Mohsin Ali Khan
 * @version 02
 * @date 11/06/2023
 *
 * @bug No known bugs to the best of my knowledge
 */


#ifndef WEATHERLOG_H
#define WEATHERLOG_H

#include <string>

#include "Date.h"
#include "Time.h"

class WeatherLog
{
public:
    /**
     * @brief Default constructor for the WeatherLog class.
     */
    WeatherLog();

    WeatherLog(Date& date, Time& time, int& windSpeed, float& ambientTemperature, float& solarRadiation);

    /**
     * @brief Sets the speed value of the weather log entry.
     * @param speed The speed value to set.
     * @return True if the speed is valid and set successfully, false otherwise.
     */
    bool SetSpeed(float speed);

    /**
     * @brief Gets the speed value of the weather log entry.
     * @return The speed value.
     */
    float GetSpeed() const;

    /**
     * @brief Sets the ambient temperature value of the weather log entry.
     * @param ambientTemperature The ambient temperature value to set.
     * @return True if the ambient temperature is set successfully.
     */
    bool SetAmbientTemperature(float ambientTemperature);

    /**
     * @brief Gets the ambient temperature value of the weather log entry.
     * @return The ambient temperature value.
     */
    float GetAmbientTemperature() const;

    /**
     * @brief Sets the solar radiation value of the weather log entry.
     * @param solarRadiation The solar radiation value to set.
     * @return True if the solar radiation is valid and set successfully, false otherwise.
     */
    bool SetSolarRadiation(float solarRadiation);

    /**
     * @brief Gets the solar radiation value of the weather log entry.
     * @return The solar radiation value.
     */
    float GetSolarRadiation() const;

    /**
     * @brief Gets the date object associated with the weather log entry.
     * @return The date object.
     */
    const Date& GetDate() const;

    /**
     * @brief Gets the time object associated with the weather log entry.
     * @return The time object.
     */
    const Time& GetTime() const;

private:
    Date m_date;                    /**< The date of the weather log entry. */
    Time m_time;                    /**< The time of the weather log entry. */
    float m_speed;                  /**< The speed value of the weather log entry. */
    float m_ambientTemperature;     /**< The ambient temperature value of the weather log entry. */
    float m_solarRadiation;         /**< The solar radiation value of the weather log entry. */
};

#endif // WEATHERLOG_H
