#ifndef _BINARY_SEARCH_TREE_H

#define _BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
public:
	BSTNode* _left;
	BSTNode* _right;
	unsigned int unFreq;
	T data;
	
	BSTNode() : _left(nullptr), _right(nullptr), unFreq(1){};
};

template <class T>
class BSTree
{
public:
	BSTree() :_root(nullptr){}
	~BSTree(){}

	void Insert(T data);
	BSTNode<T>* find(T data);
	void Delete(T x);
	BSTNode<T>* Root(){ return _root; }
	void Traversal();
	void clean();
private:
	BSTNode<T>* _root;
	void Insert(BSTNode<T>* & node, T data);
	BSTNode<T>* find(BSTNode<T>* node, T data);
	void Delete(BSTNode<T>* &node, T data);
	void InOrderTravers(BSTNode<T>* node);
	void destory(BSTNode<T>* &node);

};

template <class T>
void BSTree<T>::Delete(BSTNode<T>* &node, T data)
{
	if (nullptr == node)
		return;

	if (data < node->data)
	{
		Delete(node->_left, data);
	}
	else if (data>node->data)
	{
		Delete(node->_right, data);
	}
	else
	{
		//very important
		if (node->_left&&node->_right)
		{
			BSTNode<T>* temp = node->_right;
			while (temp->_left)
			{
				temp = temp->_left;
			}
			node->data = temp->data;
			node->unFreq = temp->unFreq;
			Delete(node->_right, temp->data);
		}
		else
		{
			BSTNode<T>* temp = node;
			if (nullptr == node->_right)
			{
				node = node->_left;
			}
			else if (nullptr == node->_left)
			{
				node = node->_right;
			}
			delete temp;
		}
	}
}

template <class T>
void BSTree<T>::Delete(T x)
{
	Delete(_root, x);
}

template <class T>
BSTNode<T>* BSTree<T>::find(BSTNode<T>* node, T data)
{
	if (nullptr == node)
		return nullptr;

	if (data < node->data)
	{
		return find(node->_left, data);
	}
	else if (data>node->data)
	{
		return find(node->_right, data);
	}
	else
	{
		return node;
	}
}

template <class T>
BSTNode<T>* BSTree<T>::find(T data)
{
	return find(_root, data);
}

template <class T>
void BSTree<T>::destory(BSTNode<T>* &node)
{
	if (node)
	{
		destory(node->_left);
		destory(node->_right);
		delete node;
	}
	node = nullptr;
}

template <class T>
void BSTree<T>::clean()
{
	destory(_root);
}

template <class T>
void BSTree<T>::InOrderTravers(BSTNode<T>* node)
{
	if (nullptr == node)
		return;

	InOrderTravers(node->_left);
	cout << node->data << endl;
	InOrderTravers(node->_right);
}

template <class T>
void BSTree<T>::Traversal()
{
	InOrderTravers(_root);
}

template <class T>
void BSTree<T>::Insert(BSTNode<T>* & node, T data)
{
	if (nullptr == node)
	{
		node = new BSTNode<T>();
		node->data = data;
		return;
	}
	else if (data<node->data)
	{
		Insert(node->_left, data);
	}
	else if (data>node->data)
	{
		Insert(node->_right, data);
	}
	else
	{
		++(node->unFreq);
	}
}

template <class T>
void BSTree<T>::Insert(T data)
{
	Insert(_root, data);
}

#endif