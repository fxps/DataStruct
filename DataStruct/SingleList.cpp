#include "stdafx.h"
#include "SingleList.h"
#include <iostream>
using namespace std;


SingleList::SingleList(void)
{
	m_pHead = new Node;
	m_pHead->data = -1;
	m_pHead->_pNext = nullptr;
	m_nCount = 0;
}


SingleList::~SingleList(void)
{
	while(m_pHead->_pNext)
	{
		Node* first = m_pHead->_pNext;
		m_pHead->_pNext = first->_pNext;
		delete first;
	}
	delete m_pHead;
	m_nCount = 0;
}

void SingleList::insertAtTail( Node* newNode )
{
	if(m_pHead->_pNext)
	{
		Node* first = m_pHead->_pNext;
		while(first->_pNext)
		{
			first = first->_pNext;
		}
		first->_pNext = newNode;
	}
	else
	{
		m_pHead->_pNext = newNode;
	}
	++m_nCount;
}

bool SingleList::deleteNodeAtIndex( int index )
{
	if(!(index>0))
	{
		cout<<"ignore index"<<endl;
		return nullptr;
	}

	if(index>m_nCount)
	{
		cout<<"out of the index range"<<endl;
		return nullptr;
	}

	if(!(m_nCount>0))
	{
		cout<<"the List is empty"<<endl;
		return nullptr;
	}

	int count = 0;
	Node* first = m_pHead->_pNext;
	++count;
	if(count==index)
	{
		m_pHead->_pNext = first->_pNext;
		delete first;
		--m_nCount;
		return true;
	}
	else
	{
		while(first->_pNext)
		{
			first = first->_pNext;
			++count;
			if(count==index)
			{
				Node* preNode = dataAtIndex(count-1);
				preNode->_pNext = first->_pNext;
				delete first;
				--m_nCount;
				return true;
			}
		}
	}
	return false;
}

void SingleList::printList()
{
	Node* first = m_pHead->_pNext;
	if(first)
	{
		cout<<first->data<<endl;
		while(first->_pNext)
		{
			first = first->_pNext;
			cout<<first->data<<endl;
		}
	}
}

Node* SingleList::dataAtIndex( int index )
{
	if(!(index>0))
	{
		cout<<"ignore index"<<endl;
		return nullptr;
	}

	if(index>m_nCount)
	{
		cout<<"out of the index range"<<endl;
		return nullptr;
	}

	if(!(m_nCount>0))
	{
		cout<<"the List is empty"<<endl;
		return nullptr;
	}

	int count = 0;
	Node* first = m_pHead->_pNext;
	++count;
	if(count==index)
	{
		return first;
	}
	else
	{
		while(first->_pNext)
		{
			first = first->_pNext;
			++count;
			if(count==index)
			{
				return first;
			}
		}
	}
	return nullptr;
}

bool SingleList::insertAtIndex(Node* data, int index )
{
	if(!(index>0))
	{
		cout<<"ignore index"<<endl;
		return nullptr;
	}

	if(index>m_nCount)
	{
		cout<<"out of the index range"<<endl;
		return nullptr;
	}

	if(!(m_nCount>0))
	{
		cout<<"the List is empty"<<endl;
		return nullptr;
	}

	int count = 0;
	Node* first = m_pHead->_pNext;
	++count;
	if(count==index)
	{
		data->_pNext = first->_pNext;
		first->_pNext = data;
		++m_nCount;
		return true;
	}
	else
	{
		while(first->_pNext)
		{
			first = first->_pNext;
			++count;
			if(count==index)
			{
				data->_pNext = first->_pNext;
				first->_pNext = data;
				++m_nCount;
				return true;
			}
		}
	}
	return false;
}


