#ifndef _SINGLE_LIST_H

#define _SINGLE_LIST_H

#include "LinearList.h"

template <class T>
class Node
{
public:
	Node() :link(NULL){}
	T element;
	Node<T>* link;
};

template <class T>
class SingleList : public LinearList<T>
{
public:
	SingleList() :first(NULL){ n = 0; }
	~SingleList(){ Clear(); }
	virtual bool IsEmpty() const;
	virtual int Length() const;
	virtual bool Find(int i, T& x) const;
	virtual int Search(T x) const;
	virtual bool Insert(int i, T x);
	virtual bool Delete(int i);
	virtual bool Update(int i, T x);
	virtual void Output();
	void Clear();
private:
	Node<T>* first;
};

template <class T>
bool SingleList<T>::IsEmpty() const
{
	return n == 0;
}

template <class T>
int SingleList<T>::Length() const
{
	cout << "Length: " << n << endl;
	return n;
}

template <class T>
bool SingleList<T>::Find(int i, T& x) const
{
	if (i<0 || i>n - 1)
	{
		cout << "Out of index" << endl;
		return false;
	}

	Node<T>* p = first;
	for (int j = 0; j < i; j++)
		p = p->link;

	x = p->element;
	return true;

}

template <class T>
int SingleList<T>::Search(T x) const
{
	if (IsEmpty())
		return -1;


	Node<T>* p = first;
	for (int j = 0; j < n; j++)
	{
		if (p->element == x)
		{
			return j;
		}
		p = p->link;
	}
		
	return -1;
}

template <class T>
bool SingleList<T>::Insert(int i, T x)
{
	Node<T>* newElmt = new Node<T>;
	newElmt->element = x;

	if (IsEmpty())
	{
		newElmt->link = first;
		first = newElmt;
	}
	else if (n==1)
	{
		first->link = newElmt;
	}
	else
	{
		Node<T>* p = first;
		for (int j = 1; j < i; j++)
			p = p->link;

		newElmt->link = p->link;
		p->link = newElmt;
	}
	++n;
	return true;
}

template <class T>
bool SingleList<T>::Delete(int i)
{
	if (IsEmpty())
		return false;

	if (i < 0 || i>n - 1)
	{
		cout << "Out of Index" << endl;
		return false;
	}

	Node<T>* p = first;
	Node<T>* q = first;
	for (int j = 0; j < i - 1; j++)
		q= q->link;

	if (i == 0)
		first = first->link;
	else
	{
		p = q->link;
		q->link = p->link;
	}
	delete p;
	--n;

	return true;
}

template <class T>
bool SingleList<T>::Update(int i, T x)
{
	if (i < 0 || i>n - 1)
	{
		cout << "Out of Index" << endl;
		return false;
	}

	Node<T>* p = first;
	for (int j = 0; j < i; j++)
		p = p->link;

	p->element = x;
	return true;
}

template <class T>
void SingleList<T>::Output()
{
	Node<T>* p = first;
	while (p)
	{
		cout << p->element << " ";
		p = p->link;
	}
	cout << endl;
}

template <class T>
void SingleList<T>::Clear()
{
	Node<T>* p = first;
	while (first)
	{
		p = first->link;
		delete first;
		first = p;
	}
}

#endif

