#ifndef _LINEAR_STACK_H

#define _LINEAR_STACK_H

#include "Stack.h"

template <class T>
class Node
{
public:
	Node() :link(NULL){}
	T element;
	Node<T>* link;
};

template <class T>
class LinearStack : public Stack<T>
{
public:
	LinearStack();
	~LinearStack();
	virtual bool IsEmpty() const;
	virtual bool IsFull() const;
	virtual bool Top(T& x) const;
	virtual bool Push(T x);
	virtual bool Pop();
	virtual void Clear();
	virtual void OutPut();

private:
	Node<T>* top;
	int nSize;
};

template <class T>
LinearStack<T>::LinearStack()
{
	nSize = 0;
	top = new Node<T>;
}

template <class T>
LinearStack<T>::~LinearStack()
{
	Clear();
}

template <class T>
bool LinearStack<T>::IsEmpty() const
{
	return nSize == 0;
}

template <class T>
bool LinearStack<T>::IsFull() const
{
	return false;
}

template <class T>
bool LinearStack<T>::Top(T& x) const
{
	if (IsEmpty())
	{
		cout << "Empty" << endl;
		return false;
	}
	Node<T>* p = top->link;
	x = p->element;
	return true;
}

template <class T>
bool LinearStack<T>::Push(T x)
{
	Node<T>* newNode = new Node<T>;
	newNode->element = x;
	
	newNode->link = top->link;
	top->link = newNode;

	++nSize;

	return true;
}

template <class T>
bool LinearStack<T>::Pop()
{
	if (IsEmpty())
	{
		cout << "Empty" << endl;
		return false;
	}

	Node<T>* p = top->link;
	top->link = p->link;
	delete p;
	--nSize;
	return true;
}

template <class T>
void LinearStack<T>::Clear()
{
	while (top)
	{
		Node<T>* p = top;
		top = p->link;
		delete p;
	}
	nSize = 0;
}

template <class T>
void LinearStack<T>::OutPut()
{
	Node<T>* p = top->link;
	while (p)
	{
		cout << p->element << " ";
		p = p->link;
	}
	cout << endl;
}

#endif