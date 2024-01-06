#include "Passenger.h"

using namespace std;

passenger::passenger(string arrivalTime, string passStart, string passEnd, int passengerID, int passGetOn, int passGetOff, string passType, int priority) {

    arrivalTime = arrivalTime;
    passStart = passStart;
    passEnd = passEnd;
    passengerID = passengerID;
    passGetOn = passGetOn;
    passGetOff = passGetOff;
    passType = passType;
    priority = priority;
}

void passenger::setArrivalTime(string time) {
    arrivalTime = time;
}

string passenger::getArrivalTime() {
    return arrivalTime;
}

void passenger::setPassStart(string start) {
    passStart = start;
}

string passenger::getPassStart() {
    return passStart;
}

void passenger::setPassEnd(string end) {
    passEnd = end;
}

string passenger::getPassEnd() {
    return passEnd;
}

void passenger::setPassengerID(int id) {
    passengerID = id;
}

int passenger::getPassengerID() {
    return passengerID;
}

void passenger::setPassGetOn(int getOn) {
    passGetOn = getOn;
}

int passenger::getPassGetOn() {
    return passGetOn;
}

void passenger::setPassGetOff(int getOff) {
    passGetOff = getOff;
}

int passenger::getPassGetOff() {
    return passGetOff;
}

void passenger::setPassType(string type) {
    passType = type;
}

string passenger::getPassType() {
    return passType;
}

void passenger::setPriority() {
    if (passType == "SP") {
        priority = 3;
    }
    else if (passType == "WP") {
        priority = 2;
    }
    else if (passType == "NP") {
        priority = 1;
    }
    else {
        priority = -1;
    }
}

int passenger::getPriority() {
    return priority;
}

bool passenger::operator==(const passenger& Passenger2) const {
    return (passengerID == Passenger2.passengerID);
}
