#include <iostream>
#include <string>

using namespace std;

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
