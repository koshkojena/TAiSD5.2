#include "Time.h"
#include <iostream>
using namespace std;
int Time::count = 0;
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) 
{
    while (seconds >= 60)
    {
        seconds -= 60;
        minutes++;
    }
    while (minutes >= 60) 
    {
        minutes -= 60;
        hours++;
    }
    while (hours >= 24) 
    {
        hours -= 24;
    }
    count++;
}
Time::~Time() 
{
    count--;
}
Time Time::operator++() 
{
    minutes++;
    if (minutes >= 60)
    {
        minutes = 0;
        ++* this;  // вызов рекурсивно операции инкремента часов
    }
    return *this;
}
Time Time::operator--() 
{
    if (minutes == 0)
    {
        minutes = 59;
        if (hours == 0)
        {
            hours = 23;
        }
        else {
            --hours;   // вызов рекурсивно операции декремента часов
        }
    }
    else 
    {
        --minutes;
    }
    return *this;
}
Time::operator int() const 
{
    return hours * 60 + minutes;
}
Time::operator bool() const
{
    return (hours != 0 || minutes != 0 || seconds != 0);
}
Time Time::operator+(int additionalMinutes) const
{
    return Time(hours, minutes + additionalMinutes, seconds);
}
Time Time::operator-(int subtractMinutes) const
{
    int totalMinutes = hours * 60 + minutes - subtractMinutes;
    int newHours = totalMinutes / 60;
    int newMinutes = totalMinutes % 60;
    if (newHours < 0) 
    {
        newHours = 0;
        newMinutes = 0;
    }
    return Time(newHours, newMinutes, seconds);
}
int Time::getCount() 
{
    return count;
}

void Time::display() const
{
    cout << "Время: " << hours << " часов, " << minutes << " минут, " << seconds << " секунд." << endl;
}