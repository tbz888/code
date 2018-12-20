#ifndef ARRAY_TREE
#define ARRAY_TREE

int two[12] = {-1, 0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
 
template <typename T>
class Tree
{
public:
	Tree(int);
	~Tree();
	void clear();
	int depth();
	T root();
	//insert
	//del
	T parent(int);
	T left_child(int);
	T right_child(int);
	//sibling	even/odd,forward/backward
private:
	int capacity;
	T *array;	
};

template <typename T>
T Tree<T>::parent(int pos)
{
	if (pos <= 1 || pos > capacity)
		return 0;
	return array[pos/2];
}

template <typename T>
T Tree<T>::left_child(int pos)
{
	if ( pos <= 1 || pos > capacity )
		return 0;
	if (2 * pos > capacity)
		return 0;
	return array[pos * 2];
}

template <typename T>
T Tree<T>::right_child(int pos)
{
	if ( pos <= 1 || pos > capacity )
		return 0;
	if ( (2 * pos + 1) > capacity)
		return 0;
	return array[pos * 2+1];
}

template <typename T>
int Tree<T>::depth()
{
	for (int i = 0; i < 11; ++i)
	{
		if (capacity > two[i] && capacity <= two[i + 1])
			return i;
	}
	return -1;
}

template <typename T>
T Tree<T>::root()
{
	if (!array[1])
		return 0;
	return array[1];
}

template <typename T>
Tree<T>::Tree(int n)
{
	if (n < 0)
		n = 0;
	capacity = n;
	if (!n)
	{
		array = NULL;
		return;
	}
	array = new T[n + 1];
	if (!array)
		capacity = 0;
	for (int i = 1; i <= capacity; ++i)
	{
		array[i] = 258;//debug
	}
}

template <typename T>
void Tree<T>::clear()
{
	capacity = 0;
	if (array)
		return;
	delete[]array;
	array = NULL;
}

template <typename T>
Tree<T>::~Tree()
{
	clear();
}

#endif