#pragma once
#include <iostream>
#include "NodeLinkedList.h"
using namespace std;

template<class T>
class LinkedList {
public:
    NodeLinkedList<T>* Head;

    LinkedList(){ Head = nullptr; }

    bool isempty()      //checks if list is empty
    {
        if (Head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    T ReturnAndDeleteFirst()
    {
        T deletedValue = Head->Data;
        NodeLinkedList<T>* temp = Head;

        Head = Head->next;
        delete temp;
        return deletedValue;
    }

    void InsertFirst(T newvalue)        //inserts at the beginning of the list
    {
        NodeLinkedList<T>* newnode = new NodeLinkedList<T>;
        newnode->Data = newvalue;
        if (isempty()) {

            newnode->next = nullptr;
            Head = newnode;
        }
        else {

            newnode->next = Head;
            Head = newnode;
        }
    }

    void display()          //displays values in the linked list
    {
        NodeLinkedList<T>* temp;
        temp = Head;
        while (temp != nullptr) {
            cout << temp->Data << " ";
            temp = temp->next;
        }
    }

    int count()         //returns the number of elements in the linked list
    {
        int count = 0;
        NodeLinkedList<T>* temp;
        temp = Head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isfound(T key)         //returns true if item is in the list, and false otherwise
    {
        bool found = false;
        NodeLinkedList<T>* temp = Head;
        while (temp != nullptr) {

            if (temp->Data == key) {

                found = true;
            }
            temp = temp->next;
        }
        return found;
    }

    void InsertBefore(T item, T newvalue)       //inserts before a given item
    {
        if (isfound(item)) {
            NodeLinkedList<T>* newnode = new NodeLinkedList<T>;
            newnode->Data = newvalue;
            NodeLinkedList<T>* temp = Head;


            if (temp != nullptr && temp->Data == item) {
                newnode->next = temp;
                Head = newnode;
                return;
            }

            while (temp != nullptr && temp->next != nullptr && temp->next->Data != item)
            {
                temp = temp->next;
            }


            if (temp == nullptr || temp->next == nullptr) {
                cout << "The item not found in the list" << endl;
                delete newnode;
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
        else {
            cout << "The item not found in the list" << endl;
        }
    }

    void Append(T newvalue)         //??
    {
        if (isempty()) {
            InsertFirst(newvalue);
        }
        else {
            NodeLinkedList<T>* newnode = new NodeLinkedList<T>;
            newnode->Data = newvalue;
            NodeLinkedList<T>* temp = Head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
            //newnode->next = nullptr;

        }
    }

    void Delete(T item) //deletes a specific item
    {
        if (isempty())
            cout << "List is empty , no items to delete \n";
        NodeLinkedList<T>* delptr = Head;
        if (Head->Data == item)
        {
            Head = Head->next;
            delete delptr;
        }
        else
        {
            NodeLinkedList<T>* prev = nullptr;
            delptr = Head;
            while (delptr->Data != item)
            {
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete delptr;
        }
    }
};


