#ifndef LIST
#define LIST
//ERROR 即 -1

//dynamic array 
template <typename T>
class List
{
public:
	List(int);
	void initialize(T);
	void clear();
	bool empty() const;
	T at(int index)const;
	int length() const;	//ok
	void assign(int, const T);	//ok
	int find(const T data) const;
	int Capacity() const;
	bool del(int index);
	bool insert(int index, const T data);
	~List();			//基本操作：read write insert delete
private:	
	T* p;
	int len;
	bool epy;
	int capacity;
	void ensureSize(int);
};

/*判断：
 *·空表？
 *·越界？
 *·输入合法？
 */

template <typename T>
int List<T>::length() const
{
	return this->len;
}

template <typename T>
bool List<T>::empty() const
{
	return this->epy;
}

template <typename T>
bool List<T>::insert(int index, const T data)
{
	if (index < 0 || index > this->len)
		return -1;
	ensureSize(this->len + 1);
	for (int i = len - 1; i >= index + 1; --i)
	{
		this->p[i] = this->p[i - 1];
	}
	this->p[index] = data;
	this->epy = 0;
	++this->len;
	return 0;
}

template <typename T>
void List<T>::assign(int index, const T b)
{
	if (index < 0 || index >= this->capacity)
		return;
	this->p[index] = b;
	this->epy = 0;
	return;
}

template <typename T>
bool List<T>::del(int index)
{
	if (index < 0 || index >= this->len)
		return -1;
	for (int i = index; i < this->len - 1; ++i)
	{
		p[i] = p[i + 1];
	}
	--this->len;
	return 0;	
}

template <typename T>
void List<T>::ensureSize(int new_size)
{
	if (this->capacity >= new_size)
		return;
	T* temp = new T[this->capacity];
	if (temp == NULL)	return;
	for (int i = 0; i < this->capacity; ++i)
	{
		temp[i] = this->p[i];
	}
	delete[] p;
	p = new T[new_size * 2];
	if (p == NULL)	return;
	for (int i = 0; i < this->capacity; ++i)
	{
		p[i] = temp[i];
	}
	delete[] temp;
	temp = NULL;
	for (int k = 0; k < new_size * 2 - (this->capacity); ++k)
		*(p + this->capacity + k) = 0;
	this->capacity = new_size * 2;
	this->epy = 0;
}

template <typename T>
List<T>::List(int size = 1)
{
	if (size > 0)	//容错性
	{
		this->p = new T[size];
		if (p == NULL)	goto nul;
		this->len = 0;
		this->epy = 0;
		this->capacity = size;
		for (int k = 0; k < size; ++k)
			*(p + k) = 0;
		return;
	}
	nul:
	this->epy = 1;
	this->capacity = 0;
	this->len = 0;
	p = NULL;
}

template <typename T>
void List<T>::initialize(T data)
{
	for (int k = 0; k < this->capacity; ++k)
		*(p + k) = data;
	this->len = this->capacity;
	this->epy = 0;
}

template <typename T>
void List<T>::clear()
{
	for (int k = 0; k < this->len; ++k)
		*(p + k) = 0;
	this->epy = 1;
	this->len = 0;
}

template <typename T>
T List<T>::at(int index)const
{
	if (index >= 0 && index < (this->len))	//边界检查
	{
		return p[index];
	}
	return -1;
}

template <typename T>
int List<T>::find(const T data) const
{
	int index = -1;
	for (int i = 0; i < this->len; ++i)
	{
		if (p[i] == data)
		{
			index = i;
			break;
		}
	}
	return index;
}

template <typename T>
int List<T>::Capacity() const
{
	return this->capacity;
}

template <typename T>
List<T>::~List()
{
	if (NULL == p)	return;
	delete[] p;
	p =NULL;
}
#endif
