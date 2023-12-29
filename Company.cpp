#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class compnay{
    public:                // Needs to fix datatypes with appropriate and efficient ones
        double S;
        double ST;
        double WBusCount;
        double MBusCount;
        double WBusCapacity;
        double MBusCapacity;
        double CWBus;
        double CMBus;
        double J;
        double maxW;
        double getOnOffTime;
        double E;
        double NPs;
        double SPs;
        double WPs;
        string AT;
        int ID; //------> Passengers IDs
        string FT; // -----> Finish time or get off time
        string MT; // -----> Move Time when bus start moving
        int TT; // -----> FT - MT
        int AvgWaitingTime; // -----> (MT - AT) / E
        int AvgTripTime; // -----> TT / E

    
    double getE() {
        return E;
    }
//_____
	double getWBusCount() {
        return WBusCount;
    }
//_____
	double getMBusCount() {
        return MBusCount;
    }
//_____
	double get() {
        return E;
    }
//_____
	double getE() {
        return E;
    }
//_____
	double getE() {
        return E;
    }
//__________________
    void readData() {
        cout << "Enter your file name: ";

        string fileName;
        cin >> fileName;

        ifstream inputFile(fileName);

		string passengerType;


        inputFile >> S >> ST;  // Line 1
        inputFile >> WBusCount >> MBusCount;  // Line 2
        inputFile >> WBusCapacity >> MBusCapacity;  // Line 3
        inputFile >> J >> CWBus >> CMBus;  // Line 4
        inputFile >> maxW >> getOnOffTime;  // Line 5
        inputFile >> E;  // Line 6

//_________________________________________________________________________________________-
        for (int i = 0; i < E; ++i) {
            char eventType;
            inputFile >> eventType;

            if (eventType == 'A') {
                string TYP, ET;
                int id, startStation;

                inputFile >> TYP >> ET >> id >> startStation;

            if (eventType == 'L') {
                string eventTimestep;
                int id, startStation;

                inputFile >> eventTimestep >> id >> startStation;

                cout << "Leave Event: " << eventTimestep << " " << id << " " << startStation << endl;
            }
			}

        inputFile.close();
    }
}
};
