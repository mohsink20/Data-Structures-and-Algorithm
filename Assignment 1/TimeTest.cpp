#include <iostream>
#include "Time.h"

void TestTimeDefaultConstructor();
void TestTimeNonDefaultConstructor();
void TestTimeSetHour();
void TestTimeSetMinute();

void TestTimeDefaultConstructor()
{
    std::cout << "-- Testing Default Constructor --\n";
    Time time;
    std::cout << "Hour: " << time.GetHours() << std::endl;
    std::cout << "Minute: " << time.GetMinutes() << std::endl;
}

void TestTimeNonDefaultConstructor()
{
    std::cout << "-- Testing Non-Default Constructor --\n";
    unsigned hours = 10;
    unsigned minutes = 30;

    Time time(hours, minutes);
    std::cout << "Hour: " << time.GetHours() << std::endl;
    std::cout << "Minute: " << time.GetMinutes() << std::endl;
}

void TestTimeSetHour()
{
    std::cout << "-- Testing SetHours() --\n";
    Time time;
    time.SetHours(8);
    std::cout << "Hour: " << time.GetHours() << std::endl;
}

void TestTimeSetMinute()
{
    std::cout << "-- Testing SetMinutes() --\n";
    Time time;
    time.SetMinutes(45);
    std::cout << "Minute: " << time.GetMinutes() << std::endl;
}

int main()
{
    TestTimeDefaultConstructor();
    std::cout << std::endl;
    TestTimeNonDefaultConstructor();
    std::cout << std::endl;
    TestTimeSetHour();
    std::cout << std::endl;
    TestTimeSetMinute();

    return 0;
}
