#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <string>
#include "priority_queue.h"
#include "linked_queue.h"
#include "passenger.h"
#include "bus.h"

using namespace std;

class Station {
private:
    int stationNumber;
    PriorityQueue<passenger*> forwardSpecialPassengers;
    PriorityQueue<passenger*> backwardSpecialPassengers;
    LinkedQueue<passenger*> forwardWheelchairPassengers;
    LinkedQueue<passenger*> backwardWheelchairPassengers;
    LinkedQueue<passenger*> forwardNormalPassengers;
    LinkedQueue<passenger*> backwardNormalPassengers;
    PriorityQueue<bus*> FWDwaitingBuses;
    PriorityQueue<bus*> BCKwaitingBuses;

public:
    Station(int number);

    void addForwardSpecialPassenger(passenger* p);
    void addBackwardSpecialPassenger(passenger* p);
    void addForwardWheelchairPassenger(passenger* p);
    void addBackwardWheelchairPassenger(passenger* p);
    void addForwardNormalPassenger(passenger* p);
    void addBackwardNormalPassenger(passenger* p);
    void addPassenger(passenger* p);
    void BusFWDlist(passenger* p);
    void End();
    void addPassengerWB();
    void insideStation(passenger* p);
    void displayPassengers();
    void print();
    void removeNormalPassenger(int id);
};

#endif  // STATION_H
