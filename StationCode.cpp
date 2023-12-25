
#include <iostream>
#include <string>
#include <queue>
#ifndef _LINKEDLIST
#endif
#define _LINKEDLIST
#ifndef _NODE
#endif
#define _NODE
using namespace std;

class passenger {
private:
	string arrivalTime;
	string passStart;
	string passEnd;
	int passengerID;
	int passGetOn;
	int passGetOff;
	string passType;

public:

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


class ArrivalTime {
private:
	int time;

	int convertToMinutes(const string& timeStr) {
		int hours = 0;
		int minutes = 0;
		int i = 0;

		while (i < timeStr.size() && timeStr[i] != ':') {
			if (timeStr[i] < '0' || timeStr[i] > '9') {

				throw invalid_argument("Invalid time format: " + timeStr);
			}
			hours = hours * 10 + (timeStr[i] - '0');
			i++;
		}
		i++; 

		while (i < timeStr.size()) {
			if (timeStr[i] < '0' || timeStr[i] > '9') {

				throw invalid_argument("Invalid time format: " + timeStr);
			}
			minutes = minutes * 10 + (timeStr[i] - '0');
			i++;
		}

		return hours * 60 + minutes;
	}

public:
	ArrivalTime(const string& timeStr) {
		time = convertToMinutes(timeStr);
	}

	string getTime() const {
		int hours = time / 60;
		int minutes = time % 60;

		string formattedTime;


		if (hours < 10) {
			formattedTime += '0';
		}
		formattedTime += (hours);
		formattedTime += ':';


		if (minutes < 10) {
			formattedTime += '0';
		}
		formattedTime += (minutes);

		return formattedTime;
	}
};

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

	void enqueue(const T& value) {
		Node<T>* newNode = new Node<T>(value);

		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			newNode = rear->getNext();
			rear = newNode;
		}

		cout << "Enqueued: " << value << endl;
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty. Cannot dequeue." << endl;
			return;
		}

		Node<T>* temp = front;
		front = front->next;

		cout << "Dequeued: " << temp->data << endl;
		delete temp;
	}

	void display() const {
		if (isEmpty()) {
			cout << "Queue is empty." << endl;
			return;
		}

		Node<T>* current = front;
		cout << "Queue: ";
		while (current != nullptr) {
			cout << current->getItem();
			current = current->getNext();
		}
		cout << endl;
	}
};


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

class bus
{
	int ID, capacity;
	//priority_queue<passenger*> ridingPass;
};

class Station {
private:
    int stationNumber;
    priority_queue<passenger*> forwardSpecialPassengers;
    priority_queue<passenger*> backwardSpecialPassengers;
    LinkedQueue<passenger*> forwardWheelchairPassengers;
    LinkedQueue<passenger*> backwardWheelchairPassengers;
    LinkedList<passenger*> forwardNormalPassengers;
    LinkedList<passenger*> backwardNormalPassengers;
    priority_queue<bus*> FWDwaitingBuses;
    priority_queue<bus*> BCKwaitingBuses;

public:
    Station(int number) : stationNumber(number) {}

    void addForwardSpecialPassenger(passenger* p) {
        forwardSpecialPassengers.push(p);
    }

    void addBackwardSpecialPassenger(passenger* p) {
        backwardSpecialPassengers.push(p);
    }

    void addPassenger(passenger* p) {
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

        string passType = p->getPassType();
        if (passType == "NP") {
            if (p->getPassGetOn() < p->getPassGetOff()) {
                forwardNormalPassengers.InsertEnd(p);
            }
            else {
                backwardNormalPassengers.InsertEnd(p);
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
                forwardSpecialPassengers.push(p);
            }
            else {
                backwardSpecialPassengers.push(p);
            }
        }
    }

    void print() {
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

	void removeNormalPassenger(int id)
	{
		//leave event
	}

};

/*

// Comparison functor for the priority queue
struct CompareClass {
	bool operator()(const passenger* lhs, const passenger* rhs) const {
		// Compare based on the data member of MyClass
		return lhs->data < rhs->data;
	}
};


int main() {
	// Priority queue using the comparison functor
	priority_queue<passenger*, vector<passenger*>, CompareClass> pq;

	// Create objects of MyClass

	// Insert objects into the priority queue
	pq.push(&obj1);
	pq.push(&obj2);
	pq.push(&obj3);

	// Access and print the elements in priority order
	while (!pq.empty()) {
		passenger* top = pq.top();
		cout << top->data << " ";
		pq.pop();
	}

	return 0;
}


*/


/*

void print24(string str)
{
	// Get hours
	int h1 = (int)str[1] - '0';
	int h2 = (int)str[0] - '0';
	int hh = (h2 * 10 + h1 % 10);

	// If time is in "AM"
	if (str[8] == 'A')
	{
		if (hh == 12)
		{
			cout << "00";
			for (int i = 2; i <= 7; i++)
				cout << str[i];
		}
		else
		{
			for (int i = 0; i <= 7; i++)
				cout << str[i];
		}
	}

	// If time is in "PM"
	else
	{
		if (hh == 12)
		{
			cout << "12";
			for (int i = 2; i <= 7; i++)
				cout << str[i];
		}
		else
		{
			hh = hh + 12;
			cout << hh;
			for (int i = 2; i <= 7; i++)
				cout << str[i];
		}
	}
}
*/
