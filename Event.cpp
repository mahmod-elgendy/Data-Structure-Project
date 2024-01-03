#include "Event.h"
#include"Passenger.h"
#include <tuple>
#include <iostream>
using namespace std;

Event::Event()
{
}

Event::Event(int start_station, int end_station, string pType, int pID, int timestep_hours, int timestep_minutes) 
	this->start_station = start_station;
	this->end_station = end_station;
	this->pType = pType;
	this->pID = pID;
	this->timestep_hour = timestep_hours;
	this->timestep_minute = timestep_minute;
}

int Event::getStartStaion()
{
	return start_station;
}

int Event::getEndStation()
{
	return end_station;
}

int Event::getPassengerID()
{
	return pID;
}

string Event::getPassengerType()
{
	return pType;
}

int Event::getTimeStepH()
{
	return timestep_hour;
}

int Event::getTimeStepM()
{
	return timestep_minute;
}




arrivalEvent::arrivalEvent(int start_station, int end_station, string pType, int pID, int timestep_hour, int timestep_minute, string speciality)
{
	this->start_station = start_station;
	this->end_station = end_station;
	this->pType = pType;
	this->pID = pID;
	this->timestep_hour = timestep_hour;
	this->timestep_minute = timestep_minute;
	this->speciality = speciality;
}

Passenger* arrivalEvent::execute()
{
	Passenger* newPassenger = new Passenger(start_station, end_station, pType, pID, timestep_hour, timestep_minute, speciality);
	return newPassenger;


}
char arrivalEvent::get_event_type()
{
	return event_type;
}


Passenger* leaveEvent::execute()
{
	return nullptr;
}

leaveEvent::leaveEvent(int timestep_hour, int timestep_minute, int start_station, int pID)
{
	this->start_station = start_station;
	this->pID = pID;
	this->timestep_hour = timestep_hour;
	this->timestep_minute = timestep_minute;
}

char leaveEvent::get_event_type()
{
	return event_type;
}
