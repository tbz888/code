#ifndef CIRCLE_QUEUE
#define CIRCLE_QUEUE

template <typename T>
class CircleQueue
{
public:
	CircleQueue();
	bool push(T);
	T first();
	T back();
	bool pop();
	int length();
private:
	T data[28];
	int front;
	int rear;
};

template <typename T>
CircleQueue<T>::CircleQueue()
{
	for (int j = 0; j < 28; ++j)
		data[j] = 0;
	front = 0;
	rear = 0;
}

template <typename T>
T CircleQueue<T>::first()
{
	return data[front];
}

template <typename T>
bool CircleQueue<T>::push(T deliver)
{
	if ( (rear + 1) % 28 == front)
		return 0;
	data[rear] = deliver;
	if (rear == 27)
	{
		rear = 0;
		return 1;
	}
	++rear;
	return 1;
}

template <typename T>
bool CircleQueue<T>::pop()
{
	if (front == rear)
		return 0;
	data[front] = 0;
	if (front == 27)
	{
		front = 0;
		return 1;
	}
	++front;
	return 1;
}

template <typename T>
T CircleQueue<T>::back()
{
	if (rear == 0)	return data[27];
	return data[rear - 1];
}

template <typename T>
int CircleQueue<T>::length()
{
	//留一个空位来判断 满队列
	return (rear - front + 28) % 28;
}

#endif
