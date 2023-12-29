#include <iostream>
#include <string>
#ifndef _LINKEDLIST
#endif
#define _LINKEDLIST
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
class LinkedList
{
private:
	Node<T>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	void PrintList() const
	{
		cout << "\nPrinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}

	void DeleteAll()
	{
		Node<T>* P = Head;

		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	void InsertEnd(const T& data)
	{
		Node<T>* I = new Node<T>(data);

		if (Head == nullptr) {
			Head = I;
		}
		else {
			Node<T>* current = Head;
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}

			current->setNext(I);
		}
	}

	bool Find(const T& value)
	{
		Node<T>* F = Head;

		while (F != nullptr) {
			if (F->getItem() == value) {
				return true;
			}
			F = F->getNext();
		}

		return false;
	}

	void DeleteFirst()
	{
		if (Head == nullptr)
		{
			return;
		}
		else
		{
			Node<T>* P = Head;
			Head = Head->getNext();
			delete P;
		}
	}

	void DeleteLast()
	{
		if (Head == nullptr)
		{
			return;
		}
		else if (Head->getNext() == nullptr)
		{
			delete Head;
			Head = nullptr;
		}
		else
		{
			Node<T>* current = Head;
			while (current->getNext()->getNext() != nullptr)
			{
				current = current->getNext();
			}

			delete current->getNext();
			current->setNext(nullptr);
		}
	}

	bool DeleteNode(const T& value)
	{
		if (Head == nullptr)
		{
			return false;
		}
		else if (Head->getItem() == value)
		{
			DeleteFirst();
			return true;
		}
		else
		{
			Node<T>* current = Head;
			while (current->getNext() != nullptr)
			{
				if (current->getNext()->getItem() == value)
				{
					Node<T>* temp = current->getNext();
					current->setNext(temp->getNext());
					delete temp;
					return true;
				}
				current = current->getNext();
			}
		}

		return false;
	}
};
