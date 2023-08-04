/**
 * @class Time
 * @brief Represents a time value in hours, minutes, and seconds.
 *
 * This class represents a time value with hours, minutes, and seconds. It provides functions
 * to set and retrieve these values, as well as convert the time to a string representation.
 *
 * @author Mohsin Ali Khan
 * @version 2
 * @date 11/06/2023
 *
 * @bug No known bugs to the best of my knowledge
 */


#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
private:
    unsigned m_hours;   /**< The hours of the time. */
    unsigned m_minutes; /**< The minutes of the time. */

public:
    /**
     * @brief Default constructor for the Time class.
     */
    Time();

    /**
     * @brief Non-default constructor for the Time class.
     * @param hours The hours of the time.
     * @param minutes The minutes of the time.
     */
    Time(unsigned hours, unsigned minutes);

    /**
     * @brief Sets the hours of the time.
     * @param hours The hours to set.
     * @return True if the hours are valid and set successfully, false otherwise.
     */
    bool SetHours(unsigned hours);

    /**
     * @brief Gets the hours of the time.
     * @return The hours of the time.
     */
    unsigned GetHours() const;

    /**
     * @brief Sets the minutes of the time.
     * @param minutes The minutes to set.
     * @return True if the minutes are valid and set successfully, false otherwise.
     */
    bool SetMinutes(unsigned minutes);

    /**
     * @brief Gets the minutes of the time.
     * @return The minutes of the time.
     */
    unsigned GetMinutes() const;

    /**
     * @brief Converts the time to a string representation.
     * @return The string representation of the time (in HH:MM format).
     */
    std::string TimeToString() const;
};

#endif // TIME_H

