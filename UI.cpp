class UI {
public:
    void displayInteractiveMode(const string& currentTime,
                                const vector<std::string>& stationDetails,
                                const vector<std::string>& busDetails,
                                const vector<std::string>& inCheckupBuses,
                                const vector<std::string>& finishedPassengers) 
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

