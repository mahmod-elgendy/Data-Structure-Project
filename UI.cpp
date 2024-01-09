#include "UI.h"
#include "Passenger.h"
#include "Bus.h"
#include <iostream>
#include <queue>

int UI::GetModeType() 
{
    std::cout << "Press 1 for Interactive mode, 2 for Silent Mode:";
    int mode;
    std::cin >> mode;
    return mode;
}

void UI::printCurrentTime(int hour, int minute) 
{
    std::cout << "Current Time (Hour:Min) ==> " << hour << ":" << minute << std::endl;
    minute++;
    if (minute == 60) {
        minute = 0;
        hour++;
    }
}

void UI::passengers_at_station(const std::queue<int>& WaitingPassengers) {
    std::cout << "============== STATION #1 =================" << std::endl;

    std::queue<int> tempQueue = WaitingPassengers;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
}

void UI::In_Check_Up_Buses(const std::queue<int>& InCheckUpbusses) {
    std::cout << "In-Checkup buses : ";
    std::queue<int> tempQueue = InCheckUpbusses;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
}

void UI::finished_passengers(const std::queue<int>& FinishedPassengers) {
    std::cout << "Finished passengers : ";
    std::queue<int> tempQueue = FinishedPassengers;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;
}
