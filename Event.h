using namespace std;
#include <iostream>
#include "Passenger.h"
#pragma once

class Event {
protected:
	int start_station;
	int end_station;
	string pType;
	int pID;
	int timestep_minute;
	int timestep_hour;
	string speciality;
	char event_type = 'X';

public:
	Event(); 
	virtual Passenger* execute() = 0;
	Event(int start_station, int end_station, string pType, int pID, int Event_time, int timestep);
	int getStartStaion();
	int getEndStation();
	int getPassengerID();
	char get_event_type();
	string getPassengerType();
	int getTimeStepH();
	int getTimeStepM();
};

class arrivalEvent : public Event {
	char event_type='A';			
public:
	using Event::Event; 
	arrivalEvent(int start_station, int end_station, string pType, int pID, int timestep_hour, int timestep_minute, string speciality);

	Passenger* execute() override;
	char get_event_type();

};

class leaveEvent : public Event {

	char event_type = 'L';			
public:

	using Event::Event;
	Passenger* execute() override;
	leaveEvent(int imestep_hour, int timestep_minute, int start_station, int pID);
	char get_event_type();

};
