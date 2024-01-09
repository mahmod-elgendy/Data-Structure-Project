#include<iostream>
#include "Company.cpp"
#include "Bus.cpp"
#include "Passenger.cpp"
#include"UI.cpp"
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    Company myCompany;
    UI myUI;

    
    int mode = myUI.GetModeType();
    std::ofstream outputFile("Output_file.txt");

    if (mode == 2)
    {
        string fileName = myCompany.getInputFile();
        myCompany.OutputData();
    }
    // if (mode == 1)
    // {
    //     myUI.printCurrentTime();
    //     myUI.passengers_at_station();
    //     myUI.In_Check_Up_Buses();
    //     myUI.finished_passengers();
    // }
    return 0;
};

