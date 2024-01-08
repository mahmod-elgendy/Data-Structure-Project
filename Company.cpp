#include "Company.h"
#include"Passenger.h"
#include"Bus.h"
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



void Company::assign(double E, std::ofstream& outputFile, const passenger& MyPassenger, const Bus& MyBus) 
{
    AT = MyPassenger.getArrivalTime();
    E = getE();
    ID = MyPassenger.getPassengerID();
    FT = MyBus.getGetOffTime();
    MT = MyBus.getMoveTime();
    TT = std::stoi(FT) - std::stoi(MT);
    AvgWaitingTime = (std::stoi(MT) - std::stoi(AT)) / E;
    AvgTripTime = TT / E;
    WBusCount = getWBusCount();
    MBusCount = getMBusCount();
    totalBuses = MBusCount + WBusCount;
    // AvgUtilization = tDC/(BC*N) *(tBT / TSim)

}

void Company::OutputData() 
{
    std::ofstream outputFile("Output_file.txt");

    outputFile << "FT\tID\tAT\tWT\tTT\n";
    passenger MyPassenger();
    Bus MyBus();
    for (int i = 0; i <= E; ++i) {
        assign(E, outputFile, MyPassenger(), MyBus());
        outputFile << FT << "\t" << ID << "\t" << AT << "\t" << "\t" << TT;
    }

    outputFile << "\npassengers: (" << NPs + WPs + SPs << ")    [ NPs = " << NPs << " , SPs = " << SPs << " , WPs = " << WPs << "]\n";
    outputFile << "passenger Average Waiting Time = " << AvgWaitingTime << "\n";
    outputFile << "passenger Average Trip Time = " << AvgTripTime << "\n";
    outputFile << "buses = " << totalBuses << " [WBus = " << WBusCount << " , MBus = " << MBusCount << "]\n";
    outputFile << "Avg Busy time = ";
    outputFile << "Avg utilization = ";
}
