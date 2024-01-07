#include "Station.h"

Station::Station(int number) : stationNumber(number) {}

void Station::addForwardSpecialPassenger(passenger* p) {
    forwardSpecialPassengers.Enqueue(p, p->getPriority());
}

void Station::addBackwardSpecialPassenger(passenger* p) {
    backwardSpecialPassengers.Enqueue(p, p->getPriority());
}

void Station::addForwardWheelchairPassenger(passenger* p) {
    forwardWheelchairPassengers.enqueue(p);
}

void Station::addBackwardWheelchairPassenger(passenger* p) {
    backwardWheelchairPassengers.enqueue(p);
}

void Station::addForwardNormalPassenger(passenger* p) {
    forwardNormalPassengers.enqueue(p);
}

void Station::addBackwardNormalPassenger(passenger* p) {
    backwardNormalPassengers.enqueue(p);
}

void Station::addPassenger(passenger* p) {
    if (p->getPassGetOn() < p->getPassGetOff()) {
        if (p->getPassGetOn() == stationNumber) {
            forwardNormalPassengers.enqueue(p);
        }
        else {
            forwardWheelchairPassengers.enqueue(p);
        }
    }
    else {
        if (p->getPassGetOn() == stationNumber) {
            backwardNormalPassengers.enqueue(p);
        }
        else {
            backwardWheelchairPassengers.enqueue(p);
        }
    }

    string passType = p->getPassType();
    if (passType == "NP") {
        if (p->getPassGetOn() < p->getPassGetOff()) {
            forwardNormalPassengers.enqueue(p);
        }
        else {
            backwardNormalPassengers.enqueue(p);
        }
    }
    else if (passType == "WP") {
        if (p->getPassGetOn() < p->getPassGetOff()) {
            forwardWheelchairPassengers.enqueue(p);
        }
        else {
            backwardWheelchairPassengers.enqueue(p);
        }
    }
    else if (passType == "SP") {
        if (p->getPassGetOn() < p->getPassGetOff()) {
            forwardSpecialPassengers.Enqueue(p, p->getPriority());
        }
        else {
            backwardSpecialPassengers.Enqueue(p, p->getPriority());
        }
    }
}

void Station::BusFWDlist(passenger* p) {
    int x;
    int WB = 17;
    string passType = p->getPassType();
    while (x <= WB) {
        if (passType == "WP") {
            if (p->getPassGetOn() < p->getPassGetOff()) {
                forwardWheelchairPassengers.enqueue(p);
            }
            else {
                backwardWheelchairPassengers.enqueue(p);
            }
        }
        else if (passType == "SP") {
            if (p->getPassGetOn() < p->getPassGetOff()) {
                forwardSpecialPassengers.Enqueue(p, p->getPriority());
            }
            else {
                backwardSpecialPassengers.Enqueue(p, p->getPriority());
            }
        }
    }
}
