// Date.h

/**
 * @class Date
 * @brief Represents a date with day, month, and year.
 *
 * This class provides functions to set and get the day, month, and year of a date,
 * as well as a ToString() function to convert the date to a string representation.
 *
 * @details The Date class allows the representation of a date in the format of day, month, and year. It offers
 * functions to set and retrieve individual components of the date, such as day, month, and year. Additionally, it
 * provides a static function to convert a numerical month value to its corresponding string representation.
 * The class also contains an operator overloading for comparison, which allows comparing two Date objects for
 * greater than, less than, or equal to relationships.
 *
 * @note All date values should be in the valid range; otherwise, the behavior is undefined.
 *
 * @author Mohsin Ali Khan
 * @version 04
 * @date 26/07/2023
 *
 * @bug All known bugs have been fixed to the best of my knowledge.
 */

#ifndef DATE_H
#define DATE_H

#include <string>
#include <map>

class Date
{
private:
    unsigned m_day; ///< Day of the date.
    unsigned m_month; ///< Month of the date.
    unsigned m_year; ///< Year of the date.

public:
    /**
     * @brief Default constructor for the Date class.
     * @details Initializes the date to January 1, 1970.
     */
    Date();

    /**
     * @brief Parameterized constructor for the Date class.
     * @param day The day of the date.
     * @param month The month of the date.
     * @param year The year of the date.
     */
    Date(unsigned day, unsigned month, unsigned year);

    /**
     * @brief Set the day of the date.
     * @param day The day of the date to be set.
     * @return True if the day is valid and set successfully, false otherwise.
     */
    bool SetDay(unsigned day);

    /**
     * @brief Get the day of the date.
     * @return The day of the date.
     */
    unsigned GetDay() const;

    /**
     * @brief Set the month of the date.
     * @param month The month of the date to be set.
     * @return True if the month is valid and set successfully, false otherwise.
     */
    bool SetMonth(unsigned month);

    /**
     * @brief Get the month of the date.
     * @return The month of the date.
     */
    unsigned int GetMonth() const;

    /**
     * @brief Set the year of the date.
     * @param year The year of the date to be set.
     * @return True if the year is valid and set successfully, false otherwise.
     */
    bool SetYear(unsigned year);

    /**
     * @brief Get the year of the date.
     * @return The year of the date.
     */
    unsigned int GetYear() const;

    /**
     * @brief Convert a numerical month value to its corresponding string representation.
     * @param month The numerical month value to be converted.
     * @return The string representation of the month.
     */
    static std::string MonthToString(unsigned month);

    /**
     * @brief Convert the date to a string representation.
     * @return The string representation of the date in the format "dd/mm/yyyy".
     */
    std::string DateToString() const;

    /**
     * @brief Overloaded less-than operator to compare two Date objects.
     * @param other The other Date object to compare with.
     * @return True if this date is earlier than the other date, false otherwise.
     */
    bool operator<(const Date& other) const;

    /**
     * @brief Overloaded greater-than operator to compare two Date objects.
     * @param other The other Date object to compare with.
     * @return True if this date is later than the other date, false otherwise.
     */
    bool operator>(const Date& other) const;

    /**
     * @brief Overloaded equality operator to compare two Date objects for equality.
     * @param other The other Date object to compare with.
     * @return True if both dates are equal, false otherwise.
     */
    bool operator==(const Date& other) const;
};

#endif // DATE_H
