#ifndef _SORT_H_
#define _SORT_H_

//以int类型为主, 默认为升序
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapSort(int array[], int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (array[i] > array[j])
				swap(array[i], array[j]);
		}
	}
}

void bubbleSort(int array[], int size)
{
	for (int i = size-1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (array[j] > array[j+1])
				swap(array[j+1], array[j]);
		}
	}
}

void selectionSort(int array[], int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		int min = i;
		for (int j = i+1; j < size; ++j)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
			swap(array[min], array[i]);
	}
}

void merge(int arr1[], int n1, int arr2[], int n2)
{
	int total = n1 + n2;
	int * saved = new int[total];

	int i = 0, j = 0;
	for (int k = 0; k < total; ++k)
	{
		/* 当另一个工作指针到底时、
		 * 比较后，符合顺序要求的，
		 * 1 进临时表
		 * 2 工作指针后移
		 */
		if ((j >= n2) || (arr1[i] < arr2[j]))
		{
			saved[k] = arr1[i];
			++i;
		}
		else if ((i >= n1) || (arr1[i] >=arr2[j]))
		{
			saved[k] = arr2[j];
			++j;
		}
	}

	for (int m = 0; m < total; ++m)
	{
		arr1[m] = saved[m];
	}

	delete[] saved;
	saved = NULL;
}

void mergeSort(int value[], int n)
{
	if (value == NULL)	return;
	if (n <= 1)	return;
	mergeSort(value, n/2);
	mergeSort(value + n/2, n-n/2);
	merge(value, n/2, value + n/2, n-n/2);
}

int random(int from, int end)
{
	if (from > end)	return 0xFFFFFFFF;
	return rand()%(end-from+1) + from;
}

int partition(int array[], int begin, int end)
{
	swap(array[begin], array[random(begin, end)]);

	int pivot = array[begin];
	int pSmall = begin, pLarge = end;
	while (pSmall < pLarge)
	{
		//找到比基准小的数
		while (pSmall < pLarge && array[pLarge] >= pivot)
		{
			--pLarge;
		}
		//找到比基准大的数
		while (pSmall < pLarge && array[pSmall] <= pivot)
		{
			++pSmall;
		}
		if (pSmall < pLarge)
			swap(array[pSmall], array[pLarge]);
	}
	swap(array[begin], array[pSmall]);
	return pSmall;
}

int partition2(int array[], int begin, int end)
{
	int pForward = begin;
	int pReplace = begin;
	int pivot = array[end];
	while (pForward < end)
	{
		if (array[pForward] <= pivot)
		{
			swap(array[pReplace], array[pForward]);
			++pReplace;
		}
		++pForward;
	}
	swap(array[end], array[pReplace]);
	return pReplace;
}

void quickSortHelper(int array[], int begin, int end)
{
	if (begin >= end)
		return;
	int pivotPosition = partition(array, begin, end);
	quickSortHelper(array, begin, pivotPosition - 1);
	quickSortHelper(array, pivotPosition + 1, end);
}

void quickSort(int array[], int size)
{
	srand(time(0));
	quickSortHelper(array, 0, size-1);
}

#endif