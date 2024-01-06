#include <iostream>
#include <string>
namespace std {

    class passenger {
    private:
        string arrivalTime;
        string passStart;
        string passEnd;
        int passengerID;
        int passGetOn;
        int passGetOff;
        string passType;
        int priority;

    public:
        passenger(string arrivalTime, string passStart, string passEnd, int passengerID, int passGetOn, int passGetOff, string passType, int priority);

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

        void setPriority();

        int getPriority();

        bool operator==(const passenger& Passenger2) const;
    };

} 
