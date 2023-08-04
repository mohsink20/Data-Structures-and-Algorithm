#include <iostream>

#include "Date.h"

void TestDefaultConstructor();
void TestNonDefaultConstructor();
void TestSetDay();
void TestSetMonth();
void TestSetYear();
void TestMonthToString();
void TestDateToString();

void TestDefaultConstructor()
{
    std::cout << "-- Testing Default Constructor --\n";
    Date date;
    std::cout << "Date: " << date.DateToString() << std::endl;
}

void TestNonDefaultConstructor()
{
    std::cout << "-- Testing Non-Default Constructor --\n";
    unsigned day = 20;
    unsigned month = 11;
    unsigned year = 2023;
    Date date(day, month, year);
    std::cout << "Date: " << date.DateToString() << std::endl;
}

void TestSetDay()
{
    std::cout << "-- Testing SetDay() --\n";
    Date date;
    unsigned day = 20;
    if (date.SetDay(day))
        std::cout << "Day set successfully: " << date.GetDay() << std::endl;
    else
        std::cout << "Invalid day. Day not set.\n";
}

void TestSetMonth()
{
    std::cout << "-- Testing SetMonth() --\n";
    Date date;
    unsigned month = 11;
    if (date.SetMonth(month))
        std::cout << "Month set successfully: " << date.GetMonth() << std::endl;
    else
        std::cout << "Invalid month. Month not set.\n";
}

void TestSetYear()
{
    std::cout << "-- Testing SetYear() --\n";
    Date date;
    unsigned year = 2023;
    if (date.SetYear(year))
        std::cout << "Year set successfully: " << date.GetYear() << std::endl;
    else
        std::cout << "Invalid year. Year not set.\n";
}

void TestMonthToString()
{
    std::cout << "-- Testing MonthToString() --\n";
    Date date;
    unsigned month = 11;
    std::string monthString = date.MonthToString(month);
    std::cout << "Month: " << monthString << std::endl;
}

void TestDateToString()
{
    std::cout << "-- Testing DateToString() --\n";
    unsigned day = 20;
    unsigned month = 11;
    unsigned year = 2023;
    Date date(day, month, year);
    std::string dateString = date.DateToString();
    std::cout << "Date: " << dateString << std::endl;
}

int main()
{
    TestDefaultConstructor();
    std::cout << std::endl;
    TestNonDefaultConstructor();
    std::cout << std::endl;
    TestSetDay();
    std::cout << std::endl;
    TestSetMonth();
    std::cout << std::endl;
    TestSetYear();
    std::cout << std::endl;
    TestMonthToString();
    std::cout << std::endl;
    TestDateToString();

    return 0;
}
