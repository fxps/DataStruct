#ifndef _STACK_H

#define _STACK_H

#include <iostream>
using namespace std;

template <class T>
class StackNode
{
public:
	StackNode() :next(nullptr){};
	T data;
	StackNode* next;
};

template <class T>
class Stack
{
public:
	Stack() : nStackSize(0), _head(nullptr){}
	~Stack(){ clear(); }
	int Size(){ return this->nStackSize; }
	bool IsEmpty(){ return 0 == nStackSize; }
	StackNode<T>* Head(){ return this->_head; }
	void push(T data);
	void pop();
	StackNode<T>* top(){ return _head; }
	void clear();
	void printStack();

private:
	int nStackSize;
	StackNode<T>* _head;
};

template <class T>
void Stack<T>::printStack()
{
	StackNode<T>* node = _head;
	while (node)
	{
		cout << node->data << endl;
		node = node->next;
	}
}

template <class T>
void Stack<T>::clear()
{
	while (_head != nullptr)
	{
		StackNode<T>* node = _head;
		_head = _head->next;
		delete node;
		--nStackSize;
	}
	_head = nullptr;
	--nStackSize = 0;
}

template <class T>
void Stack<T>::pop()
{
	if (IsEmpty())
		return;

	StackNode<T>* temp = _head;
	_head = _head->next;
	delete(temp);
	--nStackSize;
}

template <class T>
void Stack<T>::push(T data)
{
	StackNode<T>* node = new StackNode<T>();
	node->data = data;
	node->next = _head;
	_head = node;
	++nStackSize;
}

#endif // !_STACK_H
