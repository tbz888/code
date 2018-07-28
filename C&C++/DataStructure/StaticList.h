#ifndef SLL
#define SLL
#define nul 0	//仿NULL

template <typename T>
struct DATA
{
	T data;
	int cursor;
};

template <typename T>
class StaticList
{
public:
	StaticList(int);
	int length()const;
	bool insert(int, T);
	T get(int);
private:
	DATA<T> p[1025];	//given capacity
	int malloc_sll();	//simulate malloc
};

template <typename T>
T  StaticList<T>::get(int index)
{
	if (index < 0 || index > p[0].data)
		return -258;
	int cur = p[1].cursor;
	for (int i = 1; i < index - 1; ++i)
	{
		cur = p[cur].cursor;
	}
	return p[cur].data;
}

template <typename T>
int StaticList<T>::length()const
{
	return this->p[0].data;
}

template <typename T>
bool StaticList<T>::insert(int index, T num)
{
	if (index < 0 || index > 1024)
		return -1;
	int tCur = malloc_sll();
	if (!tCur)	return -1;
	p[tCur].cursor = p[index].cursor;
	p[index].cursor = tCur;
	p[tCur].data = num;
	++(p[0].data);
	return 0;
}

template <typename T>
int StaticList<T>::malloc_sll()
{
	if (p[0].cursor > 1025)
		return 0;
	++(p[0].cursor);
	return (p[0].cursor - 1);
}


template <typename T>
StaticList<T>::StaticList(int l = 0)
{
	if (l <0 || l >= 1025)	return;
	for (int i = 1; i < l; ++i)
	{
		p[i].cursor = i + 1; 
	}
	p[l].cursor = nul;
	p[0].cursor = l + 1;
	p[0].data = l;	
}//头结点指向下一个备用结点，其数据为长度

#endif
