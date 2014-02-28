#pragma once

typedef struct Node
{
	int data;
	Node* _pNext;
}Node;

class SingleList
{
public:
	SingleList(void);
	virtual ~SingleList(void);

	int count()
	{
		return this->m_nCount;
	}

	void insertAtTail(Node* newNode);
	Node* dataAtIndex(int index);
	bool insertAtIndex(Node* data, int index);
	bool deleteNodeAtIndex(int index);
	void printList();

private:
	Node* m_pHead;
	int m_nCount;
};

