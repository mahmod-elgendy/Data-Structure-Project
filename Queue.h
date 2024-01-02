#pragma once
#include <iostream>
#include "NodeLinkedList.h"
using namespace std;

template <class T>
class Queue {
public:
    NodeLinkedList<T>* front;
    NodeLinkedList<T>* rear;
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isempty()
    {
        if (front == nullptr) {   
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(T item)
    {
        NodeLinkedList<T>* newnode = new  NodeLinkedList<T>;
        newnode->Data = item;
        if (isempty()) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }


    void display()
    {
        if (isempty()) {
            cout << "the queue is empty\n";
        }
        else {
            NodeLinkedList<T>* temp = front;
            cout << "the queue contains\n";
            while (temp != nullptr) {
                cout << temp->Data;
                cout << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    T  dequeue()
    {
        //we used int as we will return the deleted value 
        T value;
        if (isempty()) {
            //cout << "the query is empty \n";
        }
        else if (front == rear) {
            delete front;           
            front = rear = nullptr;     
        }
        else {
            NodeLinkedList<T>* delptr = front;
            front = front->next;
            value = delptr->Data;
            delete delptr;
            return value;
        }
    }

    T peek()
    {
        return front->Data;
    }

    T getrear()
    {
        return rear->Data;     
    }



    int count()
    {
        int counter = 0;
        NodeLinkedList<T>* temp = front;
        while (temp != nullptr) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isfound(T item)
    {
        bool found = false;
        NodeLinkedList<T>* temp = front;
        while (temp != nullptr) {
            if (temp->Data == item) {
                found = true;
                temp = temp->next;
            }
        }
        return found;
    }

    void clear()
    {
       
        while (!isempty()) {
            dequeue();
        }

    }
};
