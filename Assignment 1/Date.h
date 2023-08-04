// Date.h

/**
 * @class Date
 * @brief Represents a date with day, month, and year.
 *
 * This class provides functions to set and get the day, month, and year of a date,
 * as well as a ToString() function to convert the date to a string representation.
 *
 * @author Mohsin Ali Khan
 * @version 02
 * @date 11/06/2023
 *
 * @bug No known bugs to the best of my knowledge
 */

#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    unsigned m_day; /**< The day of the date. */
    unsigned m_month; /**< The month of the date. */
    unsigned m_year; /**< The year of the date. */

public:
    /**
     * @brief Default constructor for the Date class.
     */
    Date();

    /**
     * @brief Non-default constructor for the Date class.
     * @param day The day of the date.
     * @param month The month of the date.
     * @param year The year of the date.
     */
    Date(unsigned day, unsigned month, unsigned year);

    /**
     * @brief Sets the day of the date.
     * @param day The day to set.
     * @return True if the day is valid and set successfully, false otherwise.
     */
    bool SetDay(unsigned day);

    /**
     * @brief Gets the day of the date.
     * @return The day of the date.
     */
    unsigned GetDay() const;

    /**
     * @brief Sets the month of the date.
     * @param month The month to set.
     * @return True if the month is valid and set successfully, false otherwise.
     */
    bool SetMonth(unsigned month);

    /**
     * @brief Gets the month of the date.
     * @return The month of the date.
     */
    unsigned int GetMonth() const;

    /**
     * @brief Sets the year of the date.
     * @param year The year to set.
     * @return True if the year is valid and set successfully, false otherwise.
     */
    bool SetYear(unsigned year);

    /**
     * @brief Gets the year of the date.
     * @return The year of the date.
     */
    unsigned int GetYear() const;

    /**
     * @brief Converts the integer month to the corresponding string representation.
     * @param month The month to convert.
     * @return The string representation of the month.
     */
    static std::string MonthToString(unsigned month);

    /**
     * @brief Converts the date to a string representation.
     * @return The string representation of the date.
     */
    std::string DateToString() const;
};

#endif // DATE_H


