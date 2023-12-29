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
