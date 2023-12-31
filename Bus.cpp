#include <iostream>
using namespace std;
#include <string>
#include <queue>



class passenger {
private:
    string passStart;
    string passEnd;
    string passType;

public:
    string arrivalTime;
    int passGetOn;
    int passGetOff;
    int passId;
    int passDestination;
    int NPs;
    int SPs;
    int WPs;
    passenger(string arrivalTime, string passStart, string passEnd, int passGetOn, int passGetOff, string passType , int passId, int passDestination) {
        arrivalTime = arrivalTime;
        passStart = passStart;
        passEnd = passEnd;
        passGetOn = passGetOn;
        passGetOff = passGetOff;
        passType = passType;
        passId = passId;
        passDestination = passDestination;
    }
    passenger(int id, int dest) : passId(id), passDestination(dest) {}

    int getNP() {
        return NPs;
    }

    int getSP() {
        return SPs;
    }

    int getWP() {
        return WPs;
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

    void setpassDestination(int passDestination) {
        passDestination = passDestination;
    }

    int getpassDestination() {
        return passDestination;
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

template <typename V>
struct Node {
    V data;
    Node<V>* next;
};
template <typename T>
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

    bool isEmpty() const {
        return rear == nullptr;
    }

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

    Node<T>* dequeue() {
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

    Node<T>* dequeueSpecificElement(T passenger) {
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

    bool isFull() const {
        return (MaxCapacity > 0) && (size() >= MaxCapacity);
    }

    int size() const {
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

    T peek() const {
        if (isEmpty()) {
            return T();
        }
        else {
            Node<T>* front = rear->next;
            return front->data;
        }
    }
};

template <typename T>
struct PriNode {
    T data;
    int priority;
    PriNode<T>* next;

    PriNode(const T& value, int prio) : data(value), priority(prio), next(nullptr) {}
};

template <typename T>
class PriorityQueue {
private:
    PriNode<T>* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(const T& value, int priority) {
        PriNode<T>* newPriNode = new PriNode<T>(value, priority);

        if (isEmpty() || priority < front->priority) {
            newPriNode->next = front;
            front = newPriNode;
        }
        else {
            PriNode<T>* current = front;
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }

            newPriNode->next = current->next;
            current->next = newPriNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            PriNode<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    const T& peek() const {
        if (!isEmpty()) {
            return front->data;
        }
        throw out_of_range("PriorityQueue is empty");
    }
};

struct ComparePassenger {
    bool operator()(const passenger* p1, const passenger* p2) {
        int stationDest = 10; // Example station destination

        int p1DestDiff = std::abs(p1->passDestination - stationDest);
        int p2DestDiff = std::abs(p2->passDestination - stationDest);

        if (p1DestDiff != p2DestDiff) {
            return p1DestDiff > p2DestDiff;
        }
        else {
            return p1->passId > p2->passId;
        }
    }
};


class Bus {
private:
    char bustype;
    int capacity;
    int maintenancetrips;
    int maintenance_duration;
    int JourneyCount;
    //int AvailableSeats; //if or while
    int currentPassengerCount;
    int currentStation;
    int moveTime;
    int getOffTime;
    PriorityQueue<passenger*> backwardMovingPaasList;
    PriorityQueue<passenger*> forwardMovingPassList;



public:
    Bus(char bustype ,int capacity, int maintenancetrips, int maintenance_duration, int JourneyCount, int currentPassengerCount, int currentStation, int moveTime, int getOffTime) {
        bustype = bustype;
        capacity = capacity;
        maintenancetrips = maintenancetrips;
        maintenance_duration = maintenance_duration;
        JourneyCount = JourneyCount;
        currentPassengerCount = currentPassengerCount;
        currentStation = currentStation;
        moveTime = moveTime;
        getOffTime = getOffTime;
    }

    char getbustype(){
        return bustype;
    }

    int getcapacity(){
        return capacity;
    }

    int getmaintenancetrips(){
        return maintenancetrips;
    }

    int getmaintenance_duration() {
        return maintenance_duration;
    }
    int getJourneyCount() {
        return JourneyCount;
    }


    int getcurrentPassengerCount() {
        return currentPassengerCount;
    }

    int getcurrentStation() {
        return currentStation;
    }
    int getmoveTime() {
        return moveTime;
    }
    
    int getgetOffTime() {
        return getOffTime;
    }

    void setbustype(char BT) {
        BT = bustype;
    }

    void setcapacity(int cap) {
        cap = capacity;
    }

    void setmaintenancetrips(int mainT) {
        mainT = maintenancetrips;
    }
    void setmaintenance_duration(int mainD) {
        mainD = maintenance_duration;
    }

    void setJourneyCount(int journey) {
        journey = JourneyCount;
    }

    void setcurrentPassengerCount(int currPass) {
        currPass = currentPassengerCount;
    }


    void setcurrentStation(int currS) {
        currS = currentStation;
    }

    void setmoveTime(char moveTime) {
        moveTime= moveTime;
    }
    
    void setgetOffTime(char getoffTime) {
        getoffTime = getoffTime;
    }
    /*
    bool Bus::hasAvailableSeats() const {
        return passengers.size() < capacity;
    }*/


};


class Bus1 {
private:
    priority_queue<passenger*, vector<passenger*>, ComparePassenger> passengerList;

public:
    void addPassenger(passenger* passenger) {
        passengerList.push(passenger);
    }

    void printPassengers() {
        while (!passengerList.empty()) {
            passenger* p = passengerList.top();
            cout << "Passenger ID: " << p->passId << ", Destination: " << p->passDestination << endl;
            passengerList.pop();
            delete p;
        }
    }
};

int main() {
    Bus1 bus;
    bus.addPassenger(new passenger(1, 5));
    bus.addPassenger(new passenger(2, 3));
    bus.addPassenger(new passenger(3, 7));
    bus.addPassenger(new passenger(4, 6));
    bus.addPassenger(new passenger(5, 4));

    cout << "Passengers in the bus:" << endl;
    bus.printPassengers();

    return 0;
}
