#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdexcept>
#include <vector>
using namespace std;

template <typename E>
class MaxHeap
{
public:
	MaxHeap()
	{
		heapSize = 0;
	}
	
	void push(E element)
	{
		priority_queue.push_back(element);
		++heapSize;
		adjustUp(heapSize);
	}

	E top()
	{
		return at(1);
	}

	void pop()
	{
		swap(at(1), at(heapSize)); 
		priority_queue.pop_back();
		--heapSize;
		if (heapSize != 0)
			adjustDown(1);
	}

	void print()
	{
		for (int i = 1; i <= heapSize; ++i)
		{
			cout << priority_queue[i-1] << ".";
			if (!(i % 5))
				cout << endl;
		}
	}

private:
	
	vector<E> priority_queue;
	int heapSize;

	void adjustUp(int number)
	{
		while (!isRoot(number))
		{
			int parent_position = parent(number);
			if (at(parent_position) < at(number))			
			{
				swap(at(parent_position), at(number));
				number = parent_position;
			}
			else 
				break;
		}
	}

	void adjustDown(int number)
	{
		while (!isLeaf(number))
		{
			int son_position = leftChild(number);
			int rc = son_position+1;
			
			if (isValid(rc) && at(rc) > at(son_position))
				son_position = rc;
			if (at(son_position) > at(number))	
			{
				swap(at(son_position), at(number));
				number = son_position;
			}
			else 
				break;
		}
	}

	E& at(int number)
	{
		if (!isValid(number))
			throw out_of_range("sss");
		return priority_queue.at(number-1);
	}

	bool isRoot(int number)
	{
		if (!isValid(number))
			return 0;
		return (number == 1);
	}
	bool isLeaf(int number)
	{
		if (!isValid(number))
			return 0;
		return (number > heapSize/2);
	}
	bool isValid(int number)
	{
		return !(number < 1 || number > heapSize);
	}
	int leftChild(int number)
	{
		int lc = number*2;
		if (!isValid(number))
			return 0;
		return isValid(lc) ? lc : 0;
	}
	int rightChild(int number)
	{
		int rc = number*2+1;
		if (!isValid(number))
			return 0;
		return isValid(rc) ? rc : 0;
	}
	int parent(int number)
	{
		if (!isValid(number))
			return 0;
		return isRoot(number) ? 0 : number/2;
	}
};

#endif