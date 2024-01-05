#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

class passenger {
private:
	string arrivalTime;
	string passStart;
	string passEnd;
	int passengerID;
	int passGetOn;
	int passGetOff;
	string passType;

public:
	passenger(string arrivalTime, string passStart, string passEnd, int passengerID, int passGetOn, int passGetOff, string passType);

	void setArrivalTime(string time);
	     string getArrivalTime();

	void setPassStart(string start);
	     string getPassStart();

	void setPassEnd(string end);
	     string getPassEnd();

	void setPassengerID(int id);
	     int getPassengerID();

	void setPassGetOn(int getOn);
	     int getPassGetOn();

	void setPassGetOff(int getOff);
     	int getPassGetOff();

	void setPassType(string type);
	    string getPassType();

	bool operator==(const passenger& Passenger2) const;
};

#endif
