#pragma once
template <class T>
class NodeLinkedList
{
public:
    T Data;
    NodeLinkedList* next;

    NodeLinkedList()
    {
        //Data = T();
        next = nullptr;
    }
};
