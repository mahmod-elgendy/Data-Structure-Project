#include "Company.h"
#include"Passenger.h"
#include "Bus.h"

#include <cstdlib>


int Company::getE() 
{
    return E;
}

int Company::getWBusCount() 
{
    return WBusCount;
}

int Company::getMBusCount() 
{
    return MBusCount;
}

std::string Company::getInputFile() 
{
    std::cout << "Enter your file name: ";
    std::string fileName;
    std::cin >> fileName;
    return fileName;
}

void Company::readData(std::string fileName) 
{
    std::ifstream inputFile(fileName);

    std::string passengerType;

    inputFile >> S >> ST;  // Line 1
    inputFile >> WBusCount >> MBusCount;  // Line 2
    inputFile >> WBusCapacity >> MBusCapacity;  // Line 3
    inputFile >> J >> CWBus >> CMBus;  // Line 4
    inputFile >> maxW >> getOnOffTime;  // Line 5
    inputFile >> E;  // Line 6

    for (int i = 0; i < E; ++i) {
        char eventType;
        inputFile >> eventType;

        if (eventType == 'A') {
            std::string TYP, ET;
            int id, startStation;

            inputFile >> TYP >> ET >> id >> startStation;

        }
        else if (eventType == 'L') {
            std::string eventTimestep;
            int id, startStation;

            inputFile >> eventTimestep >> id >> startStation;

            std::cout << "Leave Event: " << eventTimestep << " " << id << " " << startStation << std::endl;
        }
    }

    inputFile.close();
}



void Company::assign(const passenger& MyPassenger, const Bus& MyBus)
{
    AT = MyPassenger.getArrivalTime();
    E = getE();
    ID = MyPassenger.getPassengerID();
    FT = MyBus.getGetOffTime();
    MT = MyBus.getMoveTime();
    TT = //FT - MT;
    AvgWaitingTime = //(MT - AT) / E;
    AvgTripTime = //TT / E;
    WBusCount = getWBusCount();
    MBusCount = getMBusCount();
    totalBuses = MBusCount + WBusCount;
    // AvgUtilization = tDC/(BC*N) *(tBT / TSim)
}

void Company::OutputData() 
{
    std::ofstream outputFile("Output_file.txt");

    outputFile << "FT\tID\tAT\tWT\tTT\n";
    passenger myPassenger("ArrivalTime", "Start", "End", 123, 4, 8, "Type", 1);
    Bus myBus('W', 12, 2/*maintanance trips*/, 7 /*maintanance duration*/, 1 /*journy count*/, 6 /*current passengers count*/, 
     1 /*current station*/, 4 /*move time*/, 10 /*get off time*/);
    for (int i = 0; i <= E; ++i) {
        assign(myPassenger, myBus);
        outputFile << FT << "\t" << ID << "\t" << AT << "\t" << "\t" << TT;
        outputFile << myBus.getGetOffTime() << "\t" << myPassenger.getPassengerID() << "\t" << myPassenger.getArrivalTime() << "\t" << "\t" << TT << "\n";
    }

    outputFile << "\npassengers: (" << NPs + WPs + SPs << ")    [ NPs = " << NPs << " , SPs = " << SPs << " , WPs = " << WPs << "]\n";
    outputFile << "passenger Average Waiting Time = " << AvgWaitingTime << "\n";
    outputFile << "passenger Average Trip Time = " << AvgTripTime << "\n";
    outputFile << "buses = " << totalBuses << " [WBus = " << WBusCount << " , MBus = " << MBusCount << "]\n";
    outputFile << "Avg Busy time = \n";
    outputFile << "Avg utilization = \n";
    std::cout <<  "Output file has been created successfully";
}
