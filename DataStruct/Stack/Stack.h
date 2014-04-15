#ifndef _STACK_H

#define _STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Top(T& x) const = 0;
	virtual bool Push(T x) = 0;
	virtual bool Pop() = 0;
	virtual void OutPut() = 0;
	virtual void Clear() = 0;
};
#endif