// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "SingleList.h"
//#include "HeaderList.h"

#include "Stack/LinearStack.h"

#include "Tree/BinaryTree.h"

#include "stdlib.h"
#include "Stack.h"
#include "Queue.h"

#include "SortUtil/SortUitl.h"


#include "assert.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
// 	SingleList<int>* list = new SingleList<int>;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		list->Insert(i, i);
// 	}
// 	list->Delete(9);
// 	list->Update(8, 99);
// 	list->Output();
// 	delete list;

// 	HeaderList<int>* list = new HeaderList<int>;
// 	for (int i = 0; i < 10; i++)
//  	{
//  		list->Insert(i, i);
//  	}
// 	list->Length();
// 	list->Output();
// 	int a = 0;
// 	list->Find(9, a);
// 	list->Search(0);
// 	list->Delete(9);
// 	list->Output();
// 	list->Length();
// 	list->Search(9);
// 	list->Update(8, 9);
// 	list->Output();
// 	delete list;

// 	LinearStack<int>* stack = new LinearStack<int>;
// 
// 	for (int i = 0; i < 10; i++)
// 	{
// 		stack->Push(i);
// 	}
// 	stack->Pop();
// 	stack->Push(99);
// 	stack->OutPut();
// 
// 	delete stack;

// 	BinaryTree<int> a, b, x, y, z;
// 	y.MakeTree(1, a, b);
// 	z.MakeTree(2, a, b);
// 	x.MakeTree(3, y, z);
// 	x.InOrder(Visit);

	int a[10] = { 8, 7, 5, 2, 3, 6, 9, 4,0, 1 };
	//SortUtil::BubbleSort0(a, 10);
	SortUtil::SelectSort(a, 10);
	return 0;
}

