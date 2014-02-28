// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SingleList.h"
#include "BinaryTree.h"
#include "stdlib.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "assert.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SingleList* pList = new SingleList();

	for (int i = 1; i <= 10; i++)
	{
		Node* newNode = new Node();
		newNode->data = i;
		pList->insertAtTail(newNode);
	}
	//pList->printList();

	//Node* node = pList->dataAtIndex(5);
	//cout<<node->data<<endl;

// delete test
// 	pList->deleteNodeAtIndex(3);
// 	pList->printList();

// 	Node* newNode = new Node();
// 	newNode->data = 99;
// 	pList->insertAtIndex(newNode,0);
// 	pList->printList();
	delete pList;

	Stack<int>* stack = new Stack<int>();
	for (int i = 1; i <= 10; i++)
	{
		stack->push(i);
	}
/*	stack->printStack();*/

// 	StackNode<int>* top = stack->top();
// 	cout << top->data << endl;

// 	stack->pop();
// 	stack->printStack();

	delete stack;


	Queue<int>* queue = new Queue<int>();
	for (int i = 1; i <= 10; i++)
	{
		queue->push(i);
	}
//	queue->print();
// 	queue->clean();
// 	queue->print();

//	cout << queue->Front()->data << endl;

// 	queue->pop();
// 	queue->print();
// 	queue->push(11);
// 	cout << queue->Front()->data << endl;
// 	cout << queue->Size() << endl;
// 	queue->print();
 	delete queue;

	BinaryTree<int>* tree = new BinaryTree<int>();
// 	tree->insertLeftChild(1);
// 	tree->insertLeftChild(2);
// 	tree->insertLeftChild(4);
// 	tree->insertRightChild(3);
// 	tree->inOrderTravers(tree->Root());
// 	tree->postOrderTraves(tree->Root());
	delete tree;
	

	BSTree<int>* bsTree = new BSTree<int>();
// 	bsTree->Insert(6);
// 	bsTree->Insert(7);
// 	bsTree->Insert(2);
// 	bsTree->Insert(1);
// 	bsTree->Insert(4);
// 	bsTree->Insert(3);
// 	bsTree->Delete(2);
// 	bsTree->Traversal();

	delete bsTree;


	AVLTree<int> avlTree;
	int a[9] = { 16, 3,7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < 9; i++)
		avlTree.Insert(a[i]);
	avlTree.InOut();
	cout << endl;

	avlTree.PostOut();
	cout << endl;
// 
// 	int e;
// 	avlTree.Delete(43, e);
// 	avlTree.InOut();
// 	cout << endl;
	return 0;
}

