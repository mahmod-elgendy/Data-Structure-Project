#include "Time.h"
#include <iostream>


Time::Time(int hour, int minute) : currentHour(hour), currentMinute(minute) {}


void Time::addMinute(int minutes) 
{
    currentMinute += minutes;
    update();  
}


void Time::addHour(int hours) 
{
    currentHour += hours;
    update();  
}


void Time::update() 
{
    if (currentMinute >= 60) {
        currentHour += currentMinute / 60;
        currentMinute %= 60;
    }
}


void Time::displayTime() const 
{
    std::cout << "Current Time (Hour:Min): " << currentHour << ":" << currentMinute << std::endl;
}
