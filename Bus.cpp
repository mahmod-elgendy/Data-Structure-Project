#include "Bus.h"

// Bus::Bus(char bustype, int capacity, int maintenancetrips, int maintenance_duration, int JourneyCount,
//          int currentPassengerCount, int currentStation, int moveTime, int getOffTime)
//     : bustype(bustype), capacity(capacity), maintenancetrips(maintenancetrips),
//       maintenance_duration(maintenance_duration), JourneyCount(JourneyCount),
//       currentPassengerCount(currentPassengerCount), currentStation(currentStation),
//       moveTime(moveTime), getOffTime(getOffTime) {}


Bus::Bus(char bustype, int capacity, int maintenancetrips, int maintenance_duration, int JourneyCount,
         int currentPassengerCount, int currentStation, int moveTime, int getOffTime)
    : bustype(bustype), capacity(capacity), maintenancetrips(maintenancetrips),
      maintenance_duration(maintenance_duration), JourneyCount(JourneyCount),
      currentPassengerCount(currentPassengerCount), currentStation(currentStation),
      moveTime(moveTime), getOffTime(getOffTime) {}

char Bus::getBustype() const {
    return bustype;
}

int Bus::getCapacity() const {
    return capacity;
}

int Bus::getMaintenancetrips() {
    return maintenancetrips;
}

int Bus::getMaintenanceDuration() const {
    return maintenance_duration;
}

int Bus::getJourneyCount() {
    return JourneyCount;
}

int Bus::getCurrentPassengerCount() {
    return currentPassengerCount;
}

int Bus::getCurrentStation() {
    return currentStation;
}

int Bus::getMoveTime() const {
    return moveTime;
}

int Bus::getGetOffTime() const {
    return getOffTime;
}

void Bus::setBustype(char BT) {
    bustype = BT;
}

void Bus::setCapacity(int cap) {
    capacity = cap;
}

void Bus::setMaintenancetrips(int mainT) {
    maintenancetrips = mainT;
}

void Bus::setMaintenanceDuration(int mainD) {
    maintenance_duration = mainD;
}

void Bus::setJourneyCount(int journey) {
    JourneyCount = journey;
}

void Bus::setCurrentPassengerCount(int currPass) {
    currentPassengerCount = currPass;
}

void Bus::setCurrentStation(int currS) {
    currentStation = currS;
}

void Bus::setMoveTime(int mTime) {
    moveTime = mTime;
}

void Bus::setGetOffTime(int goTime) {
    getOffTime = goTime;
}
