#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

class GetInput {
public:
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
//______________________________
	double getE() {
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
//_____
	double getE() {
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
		int NPs;
		int SPs;
		int WPs;

        inputFile >> S >> ST;  // Line 1
        inputFile >> WBusCount >> MBusCount;  // Line 2
        inputFile >> WBusCapacity >> MBusCapacity;  // Line 3
        inputFile >> J >> CWBus >> CMBus;  // Line 4
        inputFile >> maxW >> getOnOffTime;  // Line 5
        inputFile >> E;  // Line 6
		
		for (int k = 0; k< E; ++k){
			inputFile >> passengerType;
			if (passengerType == "NP"){
				NPs = NPs + 1;
			}
			if (passengerType == "SP"){
				SPs = SPs + 1;
			}
			if (passengerType == "WP"){
				WPs = WPs + 1;
			}
		}

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
};

//_____________Project Structure_____________
template <typename V>
struct Node {
    V data;
    Node<V>* next;
};
template <typename T>
//___________________________________________________________________Queue
class Queue {
private:
    Node<T>* rear;
    int MaxCapacity;

public:
    Queue(int capacity) : MaxCapacity(capacity), rear(nullptr) {}
	~Queue() {
    	while (!isEmpty()) {
        	delete dequeue();
    	}
	}
//__________
    bool isEmpty() const {
        return rear == nullptr;
    }
//__________
    void enqueue(T passenger) {
        Node<T>* newNode = new Node<T>(passenger);
    if (isEmpty()) {
        return nullptr;
    }
    else {
        Node<T>* front = rear->next;
        if (front == rear) {
            rear = nullptr;
        }
        else {
            rear->next = front->next;
        }
        front->next = nullptr;
        return front;
    }
}
//__________
    Node<T>* dequeue(){    
		if (isEmpty()) {
        return nullptr;
    }
    else {
        Node<T>* front = rear->next;
        if (front == rear) {
            rear = nullptr;
        }
        else {
            rear->next = front->next;
        }
        front->next = nullptr;
        return front;
    }
}
//__________
    Node<T>* dequeueSpecificElement(T passenger){    
		if (isEmpty()) {
        return nullptr;
    }
    else {
        Node<T>* current = rear->next;
        Node<T>* previous = nullptr;

        while (current != nullptr) {
            if (current->data == passenger) {
                if (current == rear->next) {
                    rear->next = current->next;
                    if (current == rear) {
                        rear = nullptr;
                    }
                }
                else {
                    previous->next = current->next;
                    if (current == rear) {
                        rear = previous;
                    }
                }
                current->next = nullptr;
                return current;
            }
            previous = current;
            current = current->next;
        }

        return nullptr;
    }
}
//__________
    bool isFull() const{
		return (MaxCapacity > 0) && (size() >= MaxCapacity);
}
//__________
    int size() const{
		if (isEmpty()) {
        return 0;
    }

    int count = 1;
    Node<T>* temp = rear->next;
    while (temp != rear) {
        count++;
        temp = temp->next;
    }

    return count;
}
//__________
    T peek() const{
		if (isEmpty()) {
        return T();
    }
    else {
        Node<T>* front = rear->next;
        return front->data;
    }
}
};


//__________________________________________

struct Passenger {
    int id;
    int startStation;
    int endStation;
};
class passenger {
private:
	string passStart;
	string passEnd;
	string passType;

public:
	string arrivalTime;
	int passengerID;
	int passGetOn;
	int passGetOff;
	passenger(string arrivalTime, string passStart, string passEnd, int passengerID, int passGetOn, int passGetOff, string passType) {
		arrivalTime = arrivalTime;
		passStart = passStart;
		passEnd = passEnd;
		passengerID = passengerID;
		passGetOn = passGetOn;
		passGetOff = passGetOff;
		passType = passType;
	}

	void setArrivalTime(string time) {
		arrivalTime = time;
	}

	string getArrivalTime() {
		return arrivalTime;
	}

	void setPassStart(string start) {
		passStart = start;
	}

	string getPassStart() {
		return passStart;
	}

	void setPassEnd(string end) {
		passEnd = end;
	}

	string getPassEnd() {
		return passEnd;
	}

	void setPassengerID(int id) {
		passengerID = id;
	}

	int getPassengerID() {
		return passengerID;
	}

	void setPassGetOn(int getOn) {
		passGetOn = getOn;
	}

	int getPassGetOn() {
		return passGetOn;
	}


	void setPassGetOff(int getOff) {
		passGetOff = getOff;
	}

	int getPassGetOff() {
		return passGetOff;
	}

	void setPassType(string type) {
		passType = type;
	}

	string getPassType() {
		return passType;
	}

	void modifyArrivalTime(int time) {
		arrivalTime = time;
	}

	void modifyPassengerID(int id) {
		passengerID = id;
	}

	void modifyPassGetOn(int getOn) {
		passGetOn = getOn;
	}

	void modifyPassGetOff(int getOff) {
		passGetOff = getOff;
	}

	void modifyPassType(string type) {
		passType = type;
	}
};
template<typename T>
class Node
{
private:
	T item;
	Node<T>* next;

public:
	Node()
	{
		next = nullptr;
	}

	Node(T newItem)
	{
		item = newItem;
		next = nullptr;
	}

	void setItem(T newItem)
	{
		item = newItem;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	Node<T>* getNext() const
	{
		return next;
	}
};
//__________________________________________

template <typename T>
class LinkedQueue {
private:
	Node<T>* front;
	Node<T>* rear;

public:
	LinkedQueue() {
		front = nullptr;
		rear = nullptr;
	}

	bool isEmpty() const {
		return front == nullptr;
	}

	void enqueue(int value) {
		Node* newNode = new Node(value);

		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}

		cout << "Enqueued: " << value <<endl;
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty. Cannot dequeue." << endl;
			return;
		}

		Node* temp = front;
		front = front->next;

		cout << "Dequeued: " << temp->data << endl;
		delete temp;
	}

	void display() const {
		if (isEmpty()) {
			cout << "Queue is empty." << endl;
			return;
		}

		Node* current = front;
		cout << "Queue: ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

//_______________________________________________
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	void PrintList() const
	{
		cout << "\nPrinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}

	void DeleteAll()
	{
		Node<T>* P = Head;

		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	void InsertEnd(const T& data)
	{
		Node<T>* I = new Node<T>(data);

		if (Head == nullptr) {
			Head = I;
		}
		else {
			Node<T>* current = Head;
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}

			current->setNext(I);
		}
	}

	bool Find(const T& value)
	{
		Node<T>* F = Head;

		while (F != nullptr) {
			if (F->getItem() == value) {
				return true;
			}
			F = F->getNext();
		}

		return false;
	}

	void DeleteFirst()
	{
		if (Head == nullptr)
		{
			return;
		}
		else
		{
			Node<T>* P = Head;
			Head = Head->getNext();
			delete P;
		}
	}

	void DeleteLast()
	{
		if (Head == nullptr)
		{
			return;
		}
		else if (Head->getNext() == nullptr)
		{
			delete Head;
			Head = nullptr;
		}
		else
		{
			Node<T>* current = Head;
			while (current->getNext()->getNext() != nullptr)
			{
				current = current->getNext();
			}

			delete current->getNext();
			current->setNext(nullptr);
		}
	}

	bool DeleteNode(const T& value)
	{
		if (Head == nullptr)
		{
			return false;
		}
		else if (Head->getItem() == value)
		{
			DeleteFirst();
			return true;
		}
		else
		{
			Node<T>* current = Head;
			while (current->getNext() != nullptr)
			{
				if (current->getNext()->getItem() == value)
				{
					Node<T>* temp = current->getNext();
					current->setNext(temp->getNext());
					delete temp;
					return true;
				}
				current = current->getNext();
			}
		}

		return false;
	}
};


//___________________________________________________________________Bus
class Bus {
private:
    char bustype;
    int capacity;
    int maintenancetrips;
    int maintenance_duration;
    Queue<Passenger*> passengers;
    int currentPassengerCount;
    int currentStation;
    int moveTime;
    int getOffTime;

public:
    Bus(char busType, int capacity, int maintenanceTrips, int maintenanceDuration)
    : bustype(busType), capacity(capacity), maintenancetrips(maintenanceTrips),
    maintenance_duration(maintenanceDuration), currentPassengerCount(0), currentStation(0)
//_________
	Bus::~Bus() {
		while (!passengers.isEmpty()) {
			delete passengers.dequeue()->data;
		}
	}
//__________
    char Bus::get_bustype() {
    return bustype;
	}
//__________
	int Bus::get_capacity() {
		return capacity;
	}
//__________
	int Bus::get_maintenanceduration() {
		return maintenance_duration;
	}
//___________
	int Bus::get_maintenanceTrips() {
		return maintenancetrips;
	}
//___________
	bool Bus::isWorkingHours(int currentHour, int currentMinute) {
		return true;
	}
//___________
	void Bus::addPassenger(Passenger* passenger) {
		passengers.enqueue(passenger);
	}
//___________
	bool Bus::hasAvailableSeats() const {
		return passengers.size() < capacity;
	}
//___________
	int Bus::getMoveTime() {
		return moveTime;
	}
//___________
	int Bus::getGetOffTime() {
		return getOffTime;
	}
};

//___________________________________________

class Station {
private: int stationNumber;
	   priority_queue <passenger*> forwardSpecialPassengers;
	   priority_queue <passenger*> backwardSpecialPassengers;
	   LinkedQueue <passenger*> forwardWheelchairPassengers;
	   LinkedQueue <passenger*> backwardWheelchairPassengers;
	   LinkedList <passenger*> forwardNormalPassengers;
	   LinkedList <passenger*> backwardNormalPassengers;
	   LinkedQueue<Bus*> FWDwaitingBuses;
	   LinkedQueue<Bus*> BCKwaitingBuses;
public: Station(int number) : stationNumber(number)

	  void addForwardSpecialPassenger(passenger*) {
		  forwardSpecialPassengers .push(destination);
	  }
	  void addBackwardSpecialPassenger(int destination) {
		  backwardSpecialPassengers .push(destination);
	  }
	  void addPassenger(passenger* p)
	  {
		  p->getPassType();
		  if (p->getPassGetOn() < p->getPassGetOff()) {
			  if (p->getPassGetOn() == stationNumber) {
				  forwardNormalPassengers.InsertEnd(p);
			  }
			  else {
				  forwardWheelchairPassengers.enqueue(p);
			  }
		  }
		  else {
			  if (p->getPassGetOn() == stationNumber) {
				  backwardNormalPassengers.InsertEnd(p);
			  }
			  else {
				  backwardWheelchairPassengers.enqueue(p);
			  }
		  }
		  if (p->getPassType == "NP") {  // Normal passenger
			  if (p->getPassGetOn < p->getPassGetOff) {
				  forwardNormalPassengers.getInsert(p);
			  }
			  else {
				  backwardNormalPassengers.getInsert(p);
			  }
		  }
		  else if (p->getPassType == "WP") {  // Wheelchair passenger
			  if (src < dst) {
				  forwardWheelchairPassengers.enqueue(p);
			  }
			  else {
				  backwardWheelchairPassengers.enqueue(p);
			  }
		  }
		  else if (p->getPassType == "SP") {  // Special passenger

			  if (src < dst) {
				  forwardSpecialPassengers.push(p);
			  }
			  else {
				  backwardSpecialPassengers.push(p);
			  }
		  }
	  }

    void print()
    {
		forwardNormalPassengers.PrintList();
		forwardWheelchairPassengers.display();
	}	

	void addForwardWheelchairPassenger(passenger* p) {
		forwardWheelchairPassengers.enqueue(p);
	}

	void addBackwardWheelchairPassenger(passenger* p) {
		backwardWheelchairPassengers.enqueue(p);
	}

	void addForwardNormalPassenger(passenger* p) {
		forwardNormalPassengers.InsertEnd(p);
	}

	void addBackwardNormalPassenger(passenger* p) {
		backwardNormalPassengers.InsertEnd(p);
	}
};
//_________________________________
class Event {
public:
    int arrivaltime;
    int passengerId;
    string type;
    string direction;
    int station;
    int time;
    queue<Passenger> passengersQueue;

    virtual void execute() = 0;
};

class ArrivalEvent : public Event {
public:
    void execute() override;
};

void ArrivalEvent::execute() {
    Passenger passenger;
    passenger.id = passengerId;
    passenger.startStation = station;  
    passenger.endStation = -1;  
    passengersQueue.push(passenger);
}


class LeaveEvent : public Event {
public:
    void execute() override;
};


void LeaveEvent::execute() {
    if (!passengersQueue.empty()) {
        passengersQueue.pop();
    }
}
//____________UI______________
class UI {
public:
    void displayInteractiveMode(const std::string& currentTime,
                                const std::vector<std::string>& stationDetails,
                                const std::vector<std::string>& busDetails,
                                const std::vector<std::string>& inCheckupBuses,
                                const std::vector<std::string>& finishedPassengers) 
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
    void displayStationDetails(const std::vector<std::string>& stationDetails) {
        for (const auto& detail : stationDetails) {
            cout << detail << "\n";
        }
    }

    void displayBusDetails(const std::vector<std::string>& busDetails) {
        for (const auto& detail : busDetails) {
            cout << detail << "\n";
        }
    }

    void displayInCheckupBuses(const std::vector<std::string>& inCheckupBuses) {
        cout << inCheckupBuses.size() << " In-Checkup buses: ";
        for (const auto& bus : inCheckupBuses) {
            cout << bus << ", ";
        }
        cout << "\n";
    }

    void displayFinishedPassengers(const std::vector<std::string>& finishedPassengers) {
        cout << finishedPassengers.size() << " finished passengers: ";
        for (const auto& passenger : finishedPassengers) {
            cout << passenger << ", ";
        }
        cout << "\n";
    }
};

//____________________________________________________________________

int main() {
	void assign(const Passenger& passenger, const Bus& bus, double E, std::ofstream& outputFile) {
    string AT = passenger.arrivalTime;
    int ID = passenger.passengerID;
    string FT = to_string(bus.getOffTime);
    string MT = to_string(bus.moveTime);
    int TT = std::stoi(FT) - std::stoi(MT);
    int AvgWaitingTime = (std::stoi(MT) - std::stoi(AT)) / E;
    int AvgTripTime = TT / E;
    }

    std::ofstream outputFile("output.txt");

    // should be the header
    outputFile << "FT\tID\tAT\tWT\tTT\n";
    for (int i = 0; i < E; ++i) {
        assign(passenger, bus, E, outputFile);
		outputFile << FT << "\t" << ID << "\t" << AT << "\t" << WT << "\t" << TT;
    }
    outputFile.close();

    int totalPassengers = NPs + SPs + WPs;
    int totalBuses = WBusCount + MBusCount;

    outputFile << "\npassengers: (" << NPs + WPs + SPs << ")    [ NPs = " << NPs << " , SPs = " << SPs << " , WPs = " << WPs << "]\n";
    outputFile << "passenger Average Waiting Time = " << AvgWaitingTime << "\n";
    outputFile << "passenger Average Trip Time = " << AvgTripTime << "\n";
    outputFile << "buses = " << totalBuses << " [WBus = " << WBusCount << " , MBus = " << MBusCount << "]\n";

    return 0;
}
};
