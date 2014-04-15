#ifndef _HEADER_LIST_H

#define _HEAER_LIST_H

/*
*带表头结点的列表
*/

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
class HeaderList : public LinearList<T>
{
public:
	HeaderList();
	~HeaderList();
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
HeaderList<T>::HeaderList()
{
	first = new Node<T>;
	first->link = NULL;
	n = 0;
}

template <class T>
HeaderList<T>::~HeaderList()
{
	Clear();
}

template <class T>
bool HeaderList<T>::IsEmpty() const
{
	return n == 0;
}

template <class T>
int HeaderList<T>::Length() const
{
	cout << "Length: " << n << endl;
	return n;
}

template <class T>
bool HeaderList<T>::Find(int i, T& x) const
{
	if (i<0 || i>n-1)
	{
		cout << "out of index" << endl;
		return false;
	}

	Node<T>* p = first->link;
	for (int j = 0; j < i; j++)
		p = p->link;

	x = p->element;
	cout << "Find :" << x << endl;
	return true;
}

template <class T>
int HeaderList<T>::Search(T x) const
{
	Node<T>* p = first->link;
	for (int j = 0; j < n; j++)
	{
		if (p->element == x)
		{
			cout << "Find element:" << p->element <<" Index = :"<<j<< endl;
			return j;
		}
		p = p->link;
	}
	cout << "Not find element" << endl;
	return -1;
}

template <class T>
bool HeaderList<T>::Insert(int i, T x)
{
	if (i<0 || i>n )
	{
		cout << "Out of Index" << endl;
		return false;
	}

	
	Node<T>* p = first;
	Node<T>* newNode = new Node<T>;
	newNode->element = x;
	if (IsEmpty())
		first->link = newNode;
	else
	{
		for (int j = 0; j < i; j++)
			p = p->link;

		newNode->link = p->link;
		p->link = newNode;
	}
	++n;
	return true;

}

template <class T>
bool HeaderList<T>::Delete(int i)
{
	if (i<0 || i>n)
	{
		cout << "Out of Index" << endl;
		return false;
	}

	Node<T>* p = first->link;
	Node<T>* q = first->link;
	if (i == 0)
	{
		first->link = p->link;
		delete p;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			q = p;
			p = p->link;
		}
		q->link = p->link;
		delete p;
	}
	--n;
	return true;


	return true;
}

template <class T>
bool HeaderList<T>::Update(int i, T x)
{
	if (i<0 || i>n-1)
	{
		cout << "Out of Index" << endl;
		return false;
	}

	Node<T>* p = first->link;
	for (int j = 0; j < i; j++)
		p = p->link;

	p->element = x;
	return true;
}

template <class T>
void HeaderList<T>::Output()
{
	Node<T>* p = first->link;
	while (p)
	{
		cout << p->element << " ";
		p = p->link;
	}
	cout << endl;
}

template <class T>
void HeaderList<T>::Clear()
{
	while (first)
	{
		Node<T>* p = first;
		first = first->link;
		delete p;
	}
	n = 0;
	
}


#endif