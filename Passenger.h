#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class passenger {
private:
    std::string arrivalTime;
    std::string passStart;
    std::string passEnd;
    int passengerID;
    int passGetOn;
    int passGetOff;
    std::string passType;
    int priority;

public:
    passenger(std::string arrivalTime, std::string passStart, std::string passEnd, int passengerID, int passGetOn, int passGetOff, std::string passType, int priority);

    void setArrivalTime(std::string time);

    std::string getArrivalTime() const;

    void setPassStart(std::string start);

    std::string getPassStart();

    void setPassEnd(std::string end);

    std::string getPassEnd();

    void setPassengerID(int id);

    int getPassengerID() const;

    void setPassGetOn(int getOn);

    int getPassGetOn();

    void setPassGetOff(int getOff);

    int getPassGetOff();

    void setPassType(std::string type);

    std::string getPassType();

    void setPriority();

    int getPriority();

    bool operator==(const passenger& Passenger2) const;
};

#endif
