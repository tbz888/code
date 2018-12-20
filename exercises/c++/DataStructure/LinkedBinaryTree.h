#ifndef LINKED_TREE
#define LINKED_TREE

#include <stdio.h>
//just demo, so only char
struct Node
{
	char data;
	Node* left;
	Node* right;
};

//virtual node == '#'
class BiTree
{
public:
	BiTree(const char*);
	int get_depth()const;
	int get_amount()const;
	void PreOrderTraverse();
	void InOrderTraverse();
	void PostOrderTraverse();
	void print();
	void clear();
	~BiTree()
	{
		clear();
	}
private:
	void clearHelper(Node* &);
	void printHelper(Node*, int);
	void PreOrderTraverseHelper(Node* &);
	void InOrderTraverseHelper(Node* &);
	void PostOrderTraverseHelper(Node* &);
	int _depth(Node*)const;
	bool create(Node* &);
	Node* root;
	int amount;
	char buffer[100];
	int cursor;
};

void BiTree::print()
{
	printHelper(root, 1);
}

void BiTree::printHelper(Node* temp, int times)
{
	if (temp == NULL)	return;
	for (int i = 0; i < times-1; ++i)
	{
		printf("  ");
	}

	printf("|¡ª%c\n", temp->data);

	if (temp->left)
		printHelper(temp->left, 1+times);
	if (temp->right)
		printHelper(temp->right, 1+times);
}

int BiTree::get_amount()const
{
	return amount;
}

int BiTree::get_depth()const
{
	_depth(root);
}

int BiTree::_depth(Node* from)const
{
	if (NULL == from)	return 0;
	int l = BiTree::_depth(from->left);
	int r = BiTree::_depth(from->right);
	return (l > r? l : r) + 1;
}

#include <cstring>
BiTree::BiTree(const char str[])
{
	root = NULL;
	amount = 0;
	cursor = 0;
	strcpy(buffer, str);
	buffer[strlen(str)] = 0;
	BiTree::create(root);
}

//building needs PreOderTraverse
bool BiTree::create(Node* &rt)
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
		BiTree::create(rt->left);
		BiTree::create(rt->right);
	}
	return 1;
}

void BiTree::PreOrderTraverse()
{
	BiTree::PreOrderTraverseHelper(root);
}

void BiTree::PreOrderTraverseHelper(Node* &now)
{
	if (NULL == now)
	{
		printf("~");
		return;
	}
	printf("%c", now->data);
	BiTree::PreOrderTraverseHelper(now->left);
	BiTree::PreOrderTraverseHelper(now->right);
}

void BiTree::InOrderTraverse()
{
	BiTree::InOrderTraverseHelper(root);
}

void BiTree::InOrderTraverseHelper(Node* &now)
{
	if (NULL == now)
	{
		printf("~");
		return;
	}
	BiTree::InOrderTraverseHelper(now->left);
	printf("%c", now->data);
	BiTree::InOrderTraverseHelper(now->right);
}

void BiTree::PostOrderTraverse()
{
	BiTree::PostOrderTraverseHelper(root);
}

void BiTree::PostOrderTraverseHelper(Node* &now)
{
	if (NULL == now)
	{
		printf("~");
		return;
	}
	BiTree::PostOrderTraverseHelper(now->left);
	BiTree::PostOrderTraverseHelper(now->right);
	printf("%c", now->data);
}

void BiTree::clearHelper(Node* &from)
{
	if (NULL == from)	
		return;
	clearHelper(from->left);
	clearHelper(from->right);
	delete from;
	from = NULL;
}

void BiTree::clear()
{
	clearHelper(root);
	amount = 0;
}

#endif