#include "passenger.h"

passenger::passenger(string arrivalTime, string passStart, string passEnd, int passengerID, int passGetOn, int passGetOff, string passType) {

	arrivalTime = arrivalTime;
	passStart = passStart;
	passEnd = passEnd;
	passengerID = passengerID;
	passGetOn = passGetOn;
	passGetOff = passGetOff;
	passType = passType;
}

void setArrivalTime(string time) {
	arrivalTime = time;
}

string getArrivalTime() {
	return arrivalTime;
}

void setPassStart(string start) {
	passStart = start;
}

string getPassStart() {
	return passStart;
}

void setPassEnd(string end) {
	passEnd = end;
}

string getPassEnd() {
	return passEnd;
}

void setPassengerID(int id) {
	passengerID = id;
}

int getPassengerID() {
	return passengerID;
}

void setPassGetOn(int getOn) {
	passGetOn = getOn;
}

int getPassGetOn() {
	return passGetOn;
}


void setPassGetOff(int getOff) {
	passGetOff = getOff;
}

int getPassGetOff() {
	return passGetOff;
}

void setPassType(string type) {
	passType = type;
}

string getPassType() {
	return passType;
}
bool operator==(const passenger& Passenger2) const {
	return (passengerID == Passenger2.passengerID);
}
