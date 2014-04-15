#ifndef _BINARY_TREE_H

#define _BINARY_TREE_H

#include <iostream>
using namespace std;

template <class T>
class BTNode
{
public:
	BTNode(){ lChild = rChild = NULL; }
	BTNode(const T& x)
	{
		element = x;
		lChild = rChild = NULL;
	}
	BTNode(const T& x, BTNode<T>* l, BTNode<T>* r)
	{
		element = x;
		lChild = l;
		rChild = r;
	}
	T element;
	BTNode<T>* lChild;
	BTNode<T>* rChild;
};

template <class T>
void Visit(T &x)
{
	cout << x << " ";
}

template <class T>
class BinaryTree
{
public:
	BinaryTree(){ root = NULL; }
	~BinaryTree();
	bool IsEmpty() const;
	void Clear();
	bool Root(T &x)const;
	void MakeTree(const T& x, BinaryTree<T>& left, BinaryTree<T>& right);
	void BreakTree(T& x, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder(void(*visit)(T &x));
	void InOrder(void(*visit)(T &x));
	void PostOrder(void(*visit)(T &x));

protected:
	BTNode<T>* root;
private:
	void Clear(BTNode<T>* &t);
	void PreOrder(void(*visit)(T &x), BTNode<T>* t);
	void InOrder(void(*visit)(T &x), BTNode<T>* t);
	void PostOrder(void(*visit)(T &x), BTNode<T>* t);
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
	Clear();
}

template <class T>
bool BinaryTree<T>::IsEmpty() const
{
	return root == NULL;
}

template <class T>
void BinaryTree<T>::Clear()
{
	if (root)
	{
		Clear(root);
	}
}

template <class T>
bool BinaryTree<T>::Root(T &x) const
{
	if (root)
	{
		x = root->element;
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void BinaryTree<T>::MakeTree(const T& x, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (root || &left == &right) return;
	root = new BTNode<T>(x, left.root, right.root);
	left.root = right.root = NULL;
}

template <class T>
void BinaryTree<T>::BreakTree(T& x, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (!root || &left == &right || left.root || right.root) return;
	x = root->element;
	left.root = root->lChild;
	right.root = root->rChild;
	delete root;
	root = NULL;
}

template <class T>
void BinaryTree<T>::PreOrder(void(*visit)(T &x))
{
	PreOrder(visit, root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::InOrder(void(*visit)(T &x))
{
	InOrder(visit, root);
	cout << endl;
}

template <class T>
void BinaryTree<T>::PostOrder(void(*visit)(T &x))
{
	PostOrder(visit, root);
	cout << endl;
}

template <class T>                             
void BinaryTree<T>::Clear(BTNode<T>* &t)
{
	if (t->lChild)
		Clear(t->lChild);

	if (t->rChild)
		Clear(t->rChild);

	if (t)
	{
		cout << "Delete " << t->element << endl;
		delete t;
	}
}

template <class T>
void BinaryTree<T>::PreOrder(void(*visit)(T &x), BTNode<T>* t)
{
	if (t)
	{
		visit(t->element);
		PreOrder(visit, t->lChild);
		PreOrder(visit, t->rChild);
	}
}

template <class T>
void BinaryTree<T>::InOrder(void(*visit)(T &x), BTNode<T>* t)
{
	if (t)
	{
		InOrder(visit, t->lChild);
		visit(t->element);
		InOrder(visit, t->rChild);
	}
}

template <class T>
void BinaryTree<T>::PostOrder(void(*visit)(T &x), BTNode<T>* t)
{
	if (t)
	{
		
		PostOrder(visit, t->lChild);
		PostOrder(visit, t->rChild);
		visit(t->element);
	}
}

#endif