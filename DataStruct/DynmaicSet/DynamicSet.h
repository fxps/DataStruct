#ifndef _DYNMAIC_SET

#define _DYNMIC_SET

#include <iostrem>
using namespace std;

enum ResultCode
{
	UnderFlow,
	OverFlow,
	Success,
	Duplicate,
	NotPresent
};

template <class T>
class DynamicSet
{
public:
	virtual ResultCode Search(T& x) const = 0;
	virtual ResultCode Insert(T& x) = 0;
	virtual ResultCode Remove(T& x) = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
};
#endif