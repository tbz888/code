#ifndef LIST_QUEUE
#define LIST_QUEUE

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class ListQueue
{
public:
	ListQueue();
	bool push(T);
	T front()const;
	T back()const;
	bool pop();
	int length();
	bool clear();
	~ListQueue()
	{
		clear();
	}
private:
	Node<T> head;
	Node<T>* rear;
};

template <typename T>
ListQueue<T>::ListQueue()
{
	head.next = NULL;
	head.data = 0;	//length
	rear = &head;
}

template <typename T>
T ListQueue<T>::front()const
{
	if (head.next == NULL)
		return 0;
	return (head.next)->data;
}

template <typename T>
bool ListQueue<T>::push(T deliver)
{
	Node<T> *p = new Node<T>;
	if (NULL == p)	return 0;
	p->data = deliver;
	p->next = NULL;
	rear->next = p;
	rear = p;
	++head.data;
	return 1;
}

template <typename T>
bool ListQueue<T>::pop()
{
	if (head.next == NULL)
		return 0;
	Node<T>* temp = head.next;
	if (temp == rear)
		rear = &head;
	head.next = head.next->next;
	delete temp;
	--head.data;
	return 1;
}

template <typename T>
T ListQueue<T>::back()const
{
	if (rear != &head)
	return rear->data;
}

template <typename T>
int ListQueue<T>::length()
{
	return head.data;
}

template <typename T>
bool ListQueue<T>::clear()
{
	while (pop());
	return 1;
}

#endif
