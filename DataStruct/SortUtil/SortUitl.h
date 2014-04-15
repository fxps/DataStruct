#ifndef _SORT_UTIL_H

#define _SORT_UTIL_H

#include <iostream>
using namespace std;


class SortUtil
{
public:
	//ºÚµ•—°‘Ò≈≈–Ú
	static void SelectSort(int x[], int size);
	//√∞≈›≈≈–Úµƒ”≈ªØ
	static void BubbleSort2(int x[], int size);
	//√∞≈›≈≈–Ú
	static void BubbleSort(int x[], int size);
	static void BubbleSort0(int x[], int size);
	static void Swap(int &a, int &b);
	static void OutPut(int x[], int size);
};

void SortUtil::OutPut(int x[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}


void SortUtil::BubbleSort0(int x[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = i + 1; j < Size; j++)
		{
			if (x[i]>x[j])
			{
				Swap(x[i], x[j]);
			}
		}
	}
	OutPut(x, Size);
}


void SortUtil::Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SortUtil::BubbleSort(int x[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j >= i; j--)
		{
			if (x[j] < x[j - 1])
			{
				Swap(x[j], x[j-1]);
			}
		}
	}
	OutPut(x, size);
}

void SortUtil::BubbleSort2(int x[], int size)
{
	bool flag = true;
	for (int i = 0; i < size&&flag; i++)
	{
		flag = false;
		for (int j = size - 1; j >= i; j--)
		{
			if (x[j] < x[j - 1])
			{
				Swap(x[j], x[j - 1]);
				flag = true;
			}
		}
	}
	OutPut(x, size);
}

void SortUtil::SelectSort(int x[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (x[j] < x[min])
				min = j;
		}
		if (i != min)
			Swap(x[i], x[min]);
	}
	OutPut(x, size);
}

#endif