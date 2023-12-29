class UI {
public:
    void displayInteractiveMode(const string& currentTime,
                                const vector<string>& stationDetails,
                                const vector<string>& busDetails,
                                const vector<string>& inCheckupBuses,
                                const vector<string>& finishedPassengers) 
    {
        cout << "Current Time (Hour:Min)==> " << currentTime << "\n";
        cout << "============== STATION #1 =================\n";

        displayStationDetails(stationDetails);
        displayBusDetails(busDetails);
        displayInCheckupBuses(inCheckupBuses);
        displayFinishedPassengers(finishedPassengers);

        cout << "Press any key to display next station\n";
        cout << "-------------------------------------------------------\n";
    }

    
    void displaySilentModeStart() {
        cout << "-----------------------------------------------\n";
        cout << "Silent Mode\n";
        cout << "Simulation Starts...\n";
    }

    void displaySilentModeEnd() {
        cout << "Simulation ends, Output file created\n";
        cout << "-----------------------------------------------\n";
    }

private:
    void displayStationDetails(const vector<string>& stationDetails) {
        for (const auto& detail : stationDetails) {
            cout << detail << "\n";
        }
    }

    void displayBusDetails(const vector<string>& busDetails) {
        for (const auto& detail : busDetails) {
            cout << detail << "\n";
        }
    }

    void displayInCheckupBuses(const vector<tring>& inCheckupBuses) {
        cout << inCheckupBuses.size() << " In-Checkup buses: ";
        for (const auto& bus : inCheckupBuses) {
            cout << bus << ", ";
        }
        cout << "\n";
    }

    void displayFinishedPassengers(const vector<string>& finishedPassengers) {
        cout << finishedPassengers.size() << " finished passengers: ";
        for (const auto& passenger : finishedPassengers) {
            cout << passenger << ", ";
        }
        cout << "\n";
    }
};

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//(updated under going proccess)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UI {
public:
    int GetModeType(){
        cout << "Press 1 for Interactive mode, 2 for Silent Mode:";
        int mode;
        cin>> mode;
        return mode;
    }

    void displayInteractiveMode(const string& currentTime,
                                const vector<string>& stationDetails, // missing what type of details
                                const vector<string>& busDetails,     // missing what type of details
                                const vector<string>& inCheckupBuses, 
                                const vector<string>& finishedPassengers) 
    {
        cout << "Current Time (Hour:Min)==> " << currentTime << "\n";
        cout << "============== STATION #1 =================\n";

        // displayStationDetails(stationDetails);
        // displayBusDetails(busDetails); ------------------> will be added
        // displayInCheckupBuses(inCheckupBuses);
        // displayFinishedPassengers(finishedPassengers);

        cout << "Press enter to display next station";
        cout << "-------------------------------------------------------\n";
		if(cin.get()){
			// displayStationDetails(stationDetails);
			// displayBusDetails(busDetails);
			// displayInCheckupBuses(inCheckupBuses); ------------> will be added
			// displayFinishedPassengers(finishedPassengers);
		};
    } // remember to put that in a switch case in the main.cpp file
    };
