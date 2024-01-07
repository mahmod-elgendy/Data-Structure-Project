#include "Station.h"

Station::Station(int number) : stationNumber(number) {}

void Station::addForwardSpecialPassenger(passenger* p) {
    forwardSpecialPassengers.Enqueue(p, p->getPriority());
}

void Station::addBackwardSpecialPassenger(passenger* p) {
    backwardSpecialPassengers.Enqueue(p, p->getPriority());
}

void Station::addForwardWheelchairPassenger(passenger* p) {
    forwardWheelchairPassengers.enqueue(p);
}

void Station::addBackwardWheelchairPassenger(passenger* p) {
    backwardWheelchairPassengers.enqueue(p);
}

void Station::addForwardNormalPassenger(passenger* p) {
    forwardNormalPassengers.enqueue(p);
}

void Station::addBackwardNormalPassenger(passenger* p) {
    backwardNormalPassengers.enqueue(p);
}

void Station::addPassenger(passenger* p) {
    if (p->getPassGetOn() < p->getPassGetOff()) {
        if (p->getPassGetOn() == stationNumber) {
            forwardNormalPassengers.enqueue(p);
        }
        else {
            forwardWheelchairPassengers.enqueue(p);
        }
    }
    else {
        if (p->getPassGetOn() == stationNumber) {
            backwardNormalPassengers.enqueue(p);
        }
        else {
            backwardWheelchairPassengers.enqueue(p);
        }
    }

    string passType = p->getPassType();
    if (passType == "NP") {
        if (p->getPassGetOn() < p->getPassGetOff()) {
            forwardNormalPassengers.enqueue(p);
        }
        else {
            backwardNormalPassengers.enqueue(p);
        }
    }
    else if (passType == "WP") {
        if (p->getPassGetOn() < p->getPassGetOff()) {
            forwardWheelchairPassengers.enqueue(p);
        }
        else {
            backwardWheelchairPassengers.enqueue(p);
        }
    }
    else if (passType == "SP") {
        if (p->getPassGetOn() < p->getPassGetOff()) {
            forwardSpecialPassengers.Enqueue(p, p->getPriority());
        }
        else {
            backwardSpecialPassengers.Enqueue(p, p->getPriority());
        }
    }
}

void Station::BusFWDlist(passenger* p) {
    int x;
    int WB = 17;
    string passType = p->getPassType();
    while (x <= WB) {
        if (passType == "WP") {
            if (p->getPassGetOn() < p->getPassGetOff()) {
                forwardWheelchairPassengers.enqueue(p);
            }
            else {
                backwardWheelchairPassengers.enqueue(p);
            }
        }
        else if (passType == "SP") {
            if (p->getPassGetOn() < p->getPassGetOff()) {
                forwardSpecialPassengers.Enqueue(p, p->getPriority());
            }
            else {
                backwardSpecialPassengers.Enqueue(p, p->getPriority());
            }
        }
    }
    void addPassengerWB() {
	bool f = true;
	do {
		int stationNo = 10;
		int seatsWB = 17;
		// Create a new Passenger object
		string passType;
		int passGetOn;
		int passGetOff;
		int priority;
		cout << "Enter passenger type (WP/SP): ";
		cin >> passType;
		cout << "Enter passenger get on value: ";
		cin >> passGetOn;
		cout << "Enter passenger get off value: ";
		cin >> passGetOff;
		passenger* newPassenger = new passenger(passType, passGetOn, passGetOff, priority);
		BusFWDlist(newPassenger);
		End();
		f = false; // Set f to false to exit the loop
	} while (f);
}

void insideStation(passenger* p) {
	int stationNumber;
	PriorityQueue<passenger*> forwardSpecialPassengers;
	PriorityQueue<passenger*> backwardSpecialPassengers;
	LinkedQueue<passenger*> forwardWheelchairPassengers;
	LinkedQueue<passenger*> backwardWheelchairPassengers;
	LinkedQueue<passenger*> forwardNormalPassengers;
	LinkedQueue<passenger*> backwardNormalPassengers;
	PriorityQueue<bus*> FWDwaitingBuses;
	PriorityQueue<bus*> BCKwaitingBuses;
	int passengerNo;
	cout << "What is the number of passengers you want to assign: ";
	cin >> passengerNo;
	int x = 0;
	int passengerID;
	int passGetOn;
	int passGetOff;
	string passType;
	int priority;
	while (x != passengerNo) {
		cout << "passenger " << x + 1 << endl;
		cout << "Enter passenger type (WP/SP/NP): ";
		cin >> passType;
		cout << "Enter passenger get on: ";
		cin >> passGetOn;
		cout << "Enter passenger get off: ";
		cin >> passGetOff;
		x++;
		passengerID = x;
		if (passType == "wp" || passType == "WP") {
			priority = 2;
		}
		else if (passType == "sp" || passType == "SP") {
			priority = 3;
		}
		else {
			priority = 1;
		}
		string passType = p->getPassType();
		if (passType == "NP") {
			if (p->getPassGetOn() < p->getPassGetOff()) {
				forwardNormalPassengers.enqueue(p);
			}
			else {
				backwardNormalPassengers.enqueue(p);
			}
		}
		else if (passType == "WP") {
			if (p->getPassGetOn() < p->getPassGetOff()) {
				forwardWheelchairPassengers.enqueue(p);
			}
			else {
				backwardWheelchairPassengers.enqueue(p);
			}
		}
		else if (passType == "SP") {
			if (p->getPassGetOn() < p->getPassGetOff()) {
				forwardSpecialPassengers.Enqueue(p, p->getPriority());
			}
			else {
				backwardSpecialPassengers.Enqueue(p, p->getPriority());
			}
		}
	}
}
void displayPassengers() {
	PriorityQueue<passenger*> forwardSpecialPassengers;
	PriorityQueue<passenger*> backwardSpecialPassengers;
	LinkedQueue<passenger*> forwardWheelchairPassengers;
	LinkedQueue<passenger*> backwardWheelchairPassengers;
	LinkedQueue<passenger*> forwardNormalPassengers;
	LinkedQueue<passenger*> backwardNormalPassengers;
	PriorityQueue<bus*> FWDwaitingBuses;
	PriorityQueue<bus*> BCKwaitingBuses;

	cout << "Forward Wheelchair Passengers:" << endl;
	forwardWheelchairPassengers.display();

	cout << "Backward Wheelchair Passengers:" << endl;
	backwardWheelchairPassengers.display();

	cout << "Forward Special Passengers:" << endl;
	while (!forwardSpecialPassengers.IsEmpty()) {
		forwardSpecialPassengers.dequeue();
	}

	cout << "Backward Special Passengers:" << endl;
	while (!backwardSpecialPassengers.IsEmpty()) {
		backwardSpecialPassengers.dequeue();
	}
	cout << "Forward Normal Passengers:" << endl;
	forwardNormalPassengers.display();
	cout << "Backwrd Normal Passengers:" << endl;
	backwardNormalPassengers.display();
}
}
