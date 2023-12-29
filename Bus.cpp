/*
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
};*/


class Bus {
private:
    char bustype;
    int capacity;
    int maintenancetrips;
    int maintenance_duration;
    int JourneyCount;
    //int AvailableSeats; //if or while
    //Queue<Passenger*> passengers;
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



    //_________
    /*Bus::~Bus() {
    while (!passengers.isEmpty()) {
        delete passengers.dequeue()->data;
    }
}*/
//__________

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
    /*bool Bus::hasAvailableSeats() const {
        return passengers.size() < capacity;
    }*/


};
