#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <queue>
#include "Passenger.h"
#include "PriorityQueue.h"

class Bus {
private:
    char bustype;
    int capacity;
    int maintenancetrips;
    int maintenance_duration;
    int JourneyCount;
    int currentPassengerCount;
    int currentStation;
    int moveTime;
    int getOffTime;
    std::priority_queue<passenger*, std::vector<passenger*>/*, ComparePassenger*/> backwardMovingPassList;
    std::priority_queue<passenger*, std::vector<passenger*>/*, ComparePassenger*/> forwardMovingPassList;


public:
    Bus(char bustype, int capacity, int maintenancetrips, int maintenance_duration, int JourneyCount,
        int currentPassengerCount, int currentStation, int moveTime, int getOffTime);

    char getBustype()const;

    int getCapacity() const;

    int getMaintenancetrips();

    int getMaintenanceDuration() const;

    int getJourneyCount();

    int getCurrentPassengerCount();

    int getCurrentStation();

    int getMoveTime() const;

    int getGetOffTime() const;

    void setBustype(char BT);

    void setCapacity(int cap);

    void setMaintenancetrips(int mainT);

    void setMaintenanceDuration(int mainD);

    void setJourneyCount(int journey);

    void setCurrentPassengerCount(int currPass);

    void setCurrentStation(int currS);

    void setMoveTime(int moveTime);

    void setGetOffTime(int getOffTime);
};

#endif
