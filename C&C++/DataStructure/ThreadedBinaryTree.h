#ifndef THREADED_BINARY_TREE
#define THREADED_BINARY_TREE

//just demo, so only char
struct Node
{
	char data;
	Node* left;
	Node* right;
};

//virtual node == '#'
class ThreadBiTree
{
public:
	ThreadBiTree(const char*);
	void clear();
	~ThreadBiTree()
	{
		clear();
	}
	void inThread();
	void threadAccess();
private:
	void threadAccessHelper(Node* );
	bool create(Node* &);
	void clsLeft(Node* &);
	void clsRight(Node* &);
	void f(Node* &);
	Node* root;
	int amount;
	char buffer[100];
	int cursor;
	Node head;
	Node* pre;
};

#include <cstring>
ThreadBiTree::ThreadBiTree(const char str[])
{
	root = NULL;
	amount = 0;
	cursor = 0;
	strcpy(buffer, str);
	buffer[strlen(str)] = 0;
	ThreadBiTree::create(root);
	head.left = NULL;
	head.right = NULL;
}

//building needs PreOderTraverse
bool ThreadBiTree::create(Node* &rt)
{
	rt = NULL;
	if (!buffer[cursor])	return 0;
	if (buffer[cursor] == '#')	
	{
		++cursor;
		return 0;
	}
	rt = new Node;
	rt->data = buffer[cursor];
	++amount;
	++cursor;
	if (buffer[cursor])
	{
		ThreadBiTree::create(rt->left);
		ThreadBiTree::create(rt->right);
	}
	return 1;
}

void ThreadBiTree::f(Node* &post)
{
	if (!post)	return;
	ThreadBiTree::f(post->left);
	if (NULL == pre->right)
	{
		pre->right = post;
	}
	if (NULL == post->left)
	{
		post->left = pre;
	}
	pre = post;
	ThreadBiTree::f(post->right);
}

void ThreadBiTree::inThread()
{
	pre = &head;
	f(root);
	head.left = pre;
	if (NULL == pre->right)
		pre->right = &head;
}

void ThreadBiTree::clear()
{
	clsLeft(head.left);
	//clsRight(head.right);
	//head.left = NULL;		error
	//head.right = NULL;
}

void ThreadBiTree::clsRight(Node* &from)
{
	if (from == NULL)
		return;
	from->right->left = NULL;
	Node* temp = from->right;
	delete from;
	ThreadBiTree::clsRight(temp);
}

void ThreadBiTree::clsLeft(Node* &from)
{
	if (from == NULL)
		return;
	from->left->right = NULL;
	Node* temp = from->left;
	delete from;
	ThreadBiTree::clsLeft(temp);
}

void ThreadBiTree::threadAccessHelper(Node* pNode)
{
	if (pNode == &head)	return;
	printf("%c", pNode->data);
	ThreadBiTree::threadAccessHelper(pNode->right);
}

void ThreadBiTree::threadAccess()
{
//	ThreadBiTree::threadAccessHelper(head.right);
	ThreadBiTree::inThread();
	Node* p = head.right;
	while(p != &head)
	{
		printf("%c", p->data);
		p = p->right;
	}
}

#endif