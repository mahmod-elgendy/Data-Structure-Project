#include <iostream>
#include <string>
using namespace std;


class passenger {
private:
	string passStart;
	string passEnd;
	string passType;

public:
    struct Passenger {
        int id;
        int startStation;
        int endStation;
    };
	string arrivalTime;
	int passengerID;
	int passGetOn;
	int passGetOff;

	passenger(string arrivalTime, string passStart, string passEnd, int passengerID, int passGetOn, int passGetOff, string passType) {
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

	void modifyArrivalTime(int time) {
		arrivalTime = time;
	}

	void modifyPassengerID(int id) {
		passengerID = id;
	}

	void modifyPassGetOn(int getOn) {
		passGetOn = getOn;
	}

	void modifyPassGetOff(int getOff) {
		passGetOff = getOff;
	}

	void modifyPassType(string type) {
		passType = type;
	}
};
