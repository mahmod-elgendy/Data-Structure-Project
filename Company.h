#ifndef COMPANY_H
#define COMPANY_H
#include "Passenger.h"
#include "Bus.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Company {
public:
    double S;
    double ST;
    int WBusCount;
    int MBusCount;
    int WBusCapacity;
    int MBusCapacity;
    double CWBus;
    double CMBus;
    double J;
    double maxW;
    double getOnOffTime;
    int E;
    int NPs;
    int SPs;
    int WPs;
    int totalBuses;
    double AvgBusyTime;
    double AvgUtilization;
    std::string AT;
    int AT_seconds;
    int ID; // Passenger IDs
    std::string FT; // Finish time or get off time
    int FT_seconds;
    std::string MT; // Move Time when bus starts moving
    int MT_seconds;
    int TT; // FT - MT
    int AvgWaitingTime; // (MT - AT) / E
    int AvgTripTime; // TT / E

    int getE();

    int getWBusCount();

    int getMBusCount();

    std::string getInputFile();

    void readData(std::string fileName);

    int bus;

    void assign(const passenger& MyPassenger, const Bus& MyBus);

    void OutputData();
};

#endif
