#pragma once
#include <iostream>
#include "NodePriorityQueue.h"
using namespace std;
template<class T>

class PriorityQueue
{
public:
    NodePriorityQueue<T>* head;
    PriorityQueue() { head = nullptr; }

    bool IsEmpty()
    {
        if (head == nullptr)
            return true;
        return false;
    }

    void Enqueue(T newValue, int priority)
    {
        NodePriorityQueue<T>* newNode = new NodePriorityQueue<T>();
        newNode->Data = newValue;
        newNode->priority = priority;

        if (IsEmpty() || newNode->priority < head->priority)
        {
            newNode->next = head; //if newnode priority is greater than the head then the head will be the next of the new node 
            head = newNode; // now the head ( highest priority) is equal to the new node 
        }
        else
        {
            NodePriorityQueue<T>* temp = head;
            while (temp->next != NULL && temp->priority > newNode->priority)
            {
                temp = temp->next;  // searching untill we find a priority that is less than our priority   
            }
            newNode->next = temp->next; //now the new node points at the next of the temp 
            temp->next = newNode; // we inserted the new node before the temp so it's next is the new node 
        }
    }

   /* void delete_passenger_with_passenger_id(int id)
    {
        NodePriorityQueue<T>* temp = head;
        NodePriorityQueue<T>* temp_delete = head;
        while (!IsEmpty())
        {
            if (temp->next->Data.get_ID() == id)
            {
                temp_delete = temp;
                break;
            }
            temp = temp->next;
        }
        temp = temp_delete;
        temp_delete->next = temp_delete->next->next;
        delete temp;
        delete temp_delete;
    }*/

    T peak()
    {
        if (IsEmpty())
            return nullptr;
        else
            return head->Data;
    }

    T dequeue()
    {
        if (IsEmpty())
            return; //cout << "there are no elements to dequeue";
        else
        {
            int priority = 0;
            NodePriorityQueue<T>* temp = head;
            T data = head->Data;
            int count = 0;
            int temp_location=0;
            while (!temp->Data==nullptr)
            {
                if (temp->priority > priority)
                {
                    data = temp->Data;
                    priority = temp->priority;
                    temp_location = count;
                }
                temp = temp->next;
                count++;
            }
            temp = head;
            for (int i = 0; i < temp_location; i++)
            {
                temp = temp->next;
            }
            NodePriorityQueue<T>* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            delete temp;
            return data;
        }
    }

    void traverse()
    {
        NodePriorityQueue<T>* traverse = head;
        while (traverse != NULL)
        {
            cout << traverse->Data << endl;
            traverse = traverse->next;
        }
    }
    void ChangePriority(int NewPriority,T Value) //value is the value you want to change its priority in the queue 
    {
        NodePriorityQueue<T>* temp = head; //made a temp pointer points to the head 
        while (temp != NULL) //this loop searches for the value you want to change its priority 'traverse'
        {
            if (temp->Data == Value) //checks if the value we are pointing at is equal to the value we want to change its priority
            {
                temp->priority = NewPriority;//changes the priorty to the new priority
            }
            else
            {
                temp = temp->next;// moves to the next node continue traversing
            }
        }
    }
};
