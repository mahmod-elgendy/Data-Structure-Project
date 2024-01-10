#ifndef TIME_H
#define TIME_H

class Time 
{
private:
    int currentHour;
    int currentMinute;

public:
    Time(int hour, int minute);

    void addMinute(int minutes);

    void addHour(int hours);

    void update();

    void displayTime() const;
};

#endif 
