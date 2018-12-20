#ifndef LINKEDLIST
#define LINKEDLIST

//非循环单链表
template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class LinkedList
{
public:
	LinkedList(int);
	T read(int);
	void write(int, T&);
	bool insert(int, T&);
	bool del(int);
	void clear();
	~LinkedList();
private:
	Node<T>* ensureLocation(int);
	Node<T> head;
};

template <typename T>
bool LinkedList<T>::del(int index)
{
	Node<T>* p = ensureLocation(index - 1);
	if (NULL == p)	return 1;
	Node<T>* temp = p->next;
	p->next = p->next->next;
	delete (temp);
	--this->head.data;
	return 0;
}

template <typename T>
Node<T>* LinkedList<T>::ensureLocation(int index)
{
	if (index < 0 || index > head.data)
		return NULL;
	Node<T>* p = head.next;
	for (int i = 1; p && i < index; ++i)
	{
		p = p->next;
	}
	return p;
}

template <typename T>
bool LinkedList<T>::insert(int index, T& input)
{
	Node<T>* p = ensureLocation(index);
	if (NULL == p)	return 1;
	Node<T>* temp = new Node<T>;
	temp->next = p->next;
	p->next = temp;
	temp->data = input;
	++this->head.data;
	return 0;
}

template <typename T>
void LinkedList<T>::write(int index, T& input)
{
	Node<T>* p = ensureLocation(index);
	if (NULL == p)	return;
	p->data = input;
}

//工作指针后移
template <typename T>
T LinkedList<T>::read(int index) 
{
	Node<T>* p = ensureLocation(index);
	if (NULL == p)	return NULL;
	return p->data;
}

//头插法
template <typename T>
LinkedList<T>::LinkedList(int len = 0)
{
	if (len < 0) return;
	head.data = len;
	head.next = NULL;

	Node<T>* temp = NULL;
	for (int i = 1; i <= len; ++i)
	{
		temp = new Node<T>;		
		if (NULL == temp)	return;//分配不一定成功
		temp->next = head.next;
		head.next = temp;
		temp->data = 0;
	}	
}

/*尾插法
template <typename T>
LinkedList<T>::LinkedList(int len = 0)
{
	if (len < 0) return;
	head.data = len;
	head.next = NULL;

	Node<T>* p = &head;
	for (int i = 1; i <= len; ++i)
	{
		p->next = new Node<T>;
		if (NULL == p->next)	return;
		p->next->next = NULL;
		p->next->data = 0;
		p = p->next;
	}
}*/

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = &head, *record = NULL;
	while(temp->next)
	{
		record = temp->next->next;
		delete temp->next;
		temp->next = record; 
	}
	head.next = NULL;
}

template <typename T>
void LinkedList<T>::clear()
{
	Node<T>* temp = &head, *record = NULL;
	while(temp->next)
	{
		record = temp->next->next;
		delete temp->next;
		temp->next = record; 
	}
	head.next = NULL;
	head.data = 0;
}

#endif
