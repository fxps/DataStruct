#ifndef _BINARY_TREE_H

#define _BINARY_TREE_H

#include <iostream>
using namespace std;

template<class T>
class TreeNode
{
public:
	TreeNode* _left;
	TreeNode* _right;
	T data;

	TreeNode() :_left(nullptr), _right(nullptr){}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree() :_root(nullptr){};
	~BinaryTree(){ clean(); }

	TreeNode<T>* Root(){ return this->_root; }
	void insertLeftChild(T data);
	void insertRightChild(T data);

	void preOrderTravers(TreeNode<T>* node);
	void inOrderTravers(TreeNode<T>* node);
	void postOrderTraves(TreeNode<T>* node);

	void clean();

protected:
	void insertLeftChild(TreeNode<T>* nodeToAdd, TreeNode<T>* preOld);
	void insertRightChild(TreeNode<T>* nodeToAdd, TreeNode<T>* preOld);
	void destory(TreeNode<T>* node);
	TreeNode<T>* _root;
};

template<class T>
void BinaryTree<T>::destory(TreeNode<T>* node)
{
	if (node)
	{
		destory(node->_left);
		destory(node->_right);
		delete node;
	}
	_root = nullptr;
}

template<class T>
void BinaryTree<T>::clean()
{
	if (nullptr != _root)
	{
		destory(_root);
	}
}

template<class T>
void BinaryTree<T>::postOrderTraves(TreeNode<T>* node)
{
	if (node)
	{
		postOrderTraves(node->_left);
		postOrderTraves(node->_right);
		cout << node->data << endl;
	}
}

template<class T>
void BinaryTree<T>::inOrderTravers(TreeNode<T>* node)
{
	if (node)
	{
		inOrderTravers(node->_left);
		cout << node->data << endl;
		inOrderTravers(node->_right);
	}
}

template<class T>
void BinaryTree<T>::preOrderTravers(TreeNode<T>* node)
{
	if (node)
	{
		cout << node->data << endl;
		preOrderTravers(node->_left);
		preOrderTravers(node->_right);
	}
}

template<class T>
void BinaryTree<T>::insertRightChild(TreeNode<T>* nodeToAdd, TreeNode<T>* preOld)
{
	if (preOld->_right)
		insertRightChild(nodeToAdd, preOld->_right);
	else
		preOld->_right = nodeToAdd;
}

template<class T>
void BinaryTree<T>::insertLeftChild(TreeNode<T>* nodeToAdd, TreeNode<T>* preOld)
{
	if (preOld->_left)
		insertLeftChild(nodeToAdd, preOld->_left);
	else
		preOld->_left = nodeToAdd;
}

template<class T>
void BinaryTree<T>::insertRightChild(T data)
{
	TreeNode<T>* node = new TreeNode<T>();
	node->data = data;
	if (nullptr == _root)
		_root = node;
	else
		insertRightChild(node, _root);
}

template<class T>
void BinaryTree<T>::insertLeftChild(T data)
{
	TreeNode<T>* node = new TreeNode<T>();
	node->data = data;
	if (nullptr == _root)
		_root = node;
	else
		insertLeftChild(node, _root);
}

#endif