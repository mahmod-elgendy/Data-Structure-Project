#ifndef UI_H
#define UI_H

#include <iostream>
#include <queue>

class UI {
public:
    int GetModeType();
    void printCurrentTime(int hour, int minute);
    void passengers_at_station(const std::queue<int>& WaitingPassengers);
    void In_Check_Up_Buses(const std::queue<int>& InCheckUpbusses);
    void finished_passengers(const std::queue<int>& FinishedPassengers);
};

#endif // UI_H
