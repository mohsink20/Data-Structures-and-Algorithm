// Time.h

/**
 * @class Time
 * @brief Represents a time value in hours and minutes.
 *
 * The Time class represents a time value with hours and minutes. It provides functions
 * to set and retrieve these values, as well as convert the time to a string representation.
 *
 * @details The class provides functionality to set and get the hours and minutes of the time value.
 * It also offers a function to convert the time value into a string representation in the format "hh:mm".
 *
 * @note The class assumes that the input values for hours and minutes are valid within their respective ranges.
 *
 * @author Mohsin Ali Khan
 * @version 4
 * @date 26/07/2023
 *
 * @bug No known bugs to the best of my knowledge.
 */

#ifndef TIME_H
#define TIME_H

#include <string>
#include <map>

class Time
{
private:
    unsigned m_hours; ///< The hours component of the time value.
    unsigned m_minutes; ///< The minutes component of the time value.

public:
    /**
     * @brief Default constructor for the Time class.
     */
    Time();

    /**
     * @brief Parameterized constructor for the Time class.
     * @param hours The hours component of the time value.
     * @param minutes The minutes component of the time value.
     */
    Time(unsigned hours, unsigned minutes);

    /**
     * @brief Sets the hours component of the time value.
     * @param hours The hours to set.
     * @return True if the hours are valid and set successfully, false otherwise.
     */
    bool SetHours(unsigned hours);

    /**
     * @brief Gets the hours component of the time value.
     * @return The hours component of the time value.
     */
    unsigned GetHours() const;

    /**
     * @brief Sets the minutes component of the time value.
     * @param minutes The minutes to set.
     * @return True if the minutes are valid and set successfully, false otherwise.
     */
    bool SetMinutes(unsigned minutes);

    /**
     * @brief Gets the minutes component of the time value.
     * @return The minutes component of the time value.
     */
    unsigned GetMinutes() const;

    /**
     * @brief Converts the time value to a string representation in the format "hh:mm".
     * @return The string representation of the time value.
     */
    std::string TimeToString() const;

    /**
     * @brief Overloaded less-than operator for comparing Time objects.
     * @param other The Time object to compare with.
     * @return True if this Time object is less than the other, false otherwise.
     */
    bool operator<(const Time& other) const;

    /**
     * @brief Overloaded greater-than operator for comparing Time objects.
     * @param other The Time object to compare with.
     * @return True if this Time object is greater than the other, false otherwise.
     */
    bool operator>(const Time& other) const;

    /**
     * @brief Overloaded equality operator for comparing Time objects.
     * @param other The Time object to compare with.
     * @return True if this Time object is equal to the other, false otherwise.
     */
    bool operator==(const Time& other) const;
};

#endif // TIME_H
