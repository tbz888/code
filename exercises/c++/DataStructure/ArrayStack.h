#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <cstring>
#define SUCCESS 1
#define FAILED 0
//验证来源，反馈结果
template <typename T>
class Stack
{
public:
	Stack(int);
	bool push(T);
	T pop();
	~Stack();
private:
	T* pArr;
	int top;	//contain the top elementary's position
	int capacity;
};

template <typename T>
Stack<T>::Stack(int capacity = 10)
{
	pArr = new T[capacity];
	top = -1;
	memset(pArr, 0, sizeof(T) * capacity);
	this->capacity = capacity;
}

template <typename T>
bool Stack<T>::push(T deliver)
{
	if ( (top + 1) > capacity)	return FAILED;
	++top;
	pArr[top] = deliver;
	return SUCCESS;
}

template <typename T>
T Stack<T>::pop()
{
	if (top < 0)	return FAILED;
	T temp = pArr[top];
	pArr[top] = 0;
	--top;
	return temp;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] pArr;
	top = -1;
}

#endif