#pragma once
#include <iostream>
using namespace std;
template< class T>
class NodePriorityQueue
{
public:
	T Data;
	int priority;
	NodePriorityQueue* next;
	NodePriorityQueue()
	{
		Data = T();
		priority = 0;
	}
};

