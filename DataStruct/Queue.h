#ifndef _QUEUE_H

#define _QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class QueueNode
{
public:
	QueueNode() : _next(nullptr){}
	T data;
	QueueNode* _next;
};

template <class T>
class Queue
{
public:
	Queue() :nQueueSize(0), _rear(nullptr), _front(nullptr){}
	~Queue(){ clean(); }

	void push(T data);
	void pop();
	QueueNode<T>* Front();
	bool IsEmpty(){ return 0 == nQueueSize; }
	void clean();
	void print();
	int Size(){ return nQueueSize; }

private:
	QueueNode<T>* _rear;
	QueueNode<T>* _front;
	int nQueueSize;
};

template <class T>
void Queue<T>::print()
{
	if (IsEmpty())
	{
		cout << "Queue is empty" << endl;
		return;
	}

	QueueNode<T>* node = _front;
	while (node)
	{
		cout << node->data << endl;
		node = node->_next;
	}
}

template <class T>
void Queue<T>::clean()
{
	while (_front)
	{
		QueueNode<T>* node = _front;
		_front = _front->_next;
		delete node;
	}
	_front = nullptr;
	_rear = nullptr;
	nQueueSize = 0;
}

template <class T>
QueueNode<T>* Queue<T>::Front()
{
	if (0 == nQueueSize)
		return nullptr;
	
	return _front;
}

template <class T>
void Queue<T>::pop()
{
	QueueNode<T>* node = _front;
	_front = _front->_next;
	delete node;
	--nQueueSize;
}

template <class T>
void Queue<T>::push(T data)
{
	QueueNode<T>* node = new QueueNode<T>();
	node->data = data;
	if (_rear == nullptr)
	{
		_front = node;
		_rear = node;
	}
	else
	{
		_rear->_next = node;
		_rear = node;
	}
	++nQueueSize;
}

#endif