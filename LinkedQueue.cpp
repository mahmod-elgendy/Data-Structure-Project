#include <iostream>
#include <string>
#ifndef _LinkedQueue
#endif
#define _LinkedQueue
#ifndef _NODE
#endif
#define _NODE
using namespace std;

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

