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
	SingleList<int>* list = new SingleList<int>;
	for (int i = 0; i < 10; i++)
	{
		list->Insert(i, i);
	}
	list->Delete(9);
	list->Update(8, 99);
	list->Output();
	delete list;
	return 0;
}

