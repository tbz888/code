#ifndef STACK_LIST
#define STACK_LIST

#define SUCCESS 1
#define FAILED 0
//验证来源，反馈结果

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class Stack
{
public:
	Stack();
	bool push(T);
	T pop();
	void display();
	~Stack();
private:
	Node<T>* head;
};

template <typename T>
Stack<T>::Stack()
{
	head = NULL;
}

template <typename T>
bool Stack<T>::push(T deliver)
{
	Node<T>* temp;
	temp = new Node<T>;
	if (NULL == temp)	return FAILED;
	temp->data = deliver;
	temp->next = head;
	head = temp;
	return SUCCESS;
}

template <typename T>
T Stack<T>::pop()
{
	if (!head)	return FAILED;
	T temp = head->data;
	Node<T>* pDel = head;
	Node<T>* pNext = head->next;
	delete head;
	head = pNext;
	return temp;
}

template <typename T>
void Stack<T>::display()
{
	Node<T>* iterator = head;
	while(iterator)
	{
		cout << iterator->data << " ";
		iterator = iterator->next;
	}
	cout << endl;
}

template <typename T>
Stack<T>::~Stack()
{
	while(head)
	{
		Node<T>* pDel = head->next;
		delete head;
		head = pDel;
	}
}

#endif