#ifndef _AVL_TREE_H

#define _AVL_TREE_H

#include <stack>
template <class T>
class AVLNode
{
public:
	T data;
	int bf;
	AVLNode<T>* _leftChild;
	AVLNode<T>* _rightChild;

	AVLNode() :_leftChild(nullptr), _rightChild(nullptr){}
	AVLNode(const T& e) :_leftChild(nullptr), _rightChild(nullptr)
	{
		data = e;
		bf = 0;
	}
};

template <class T>
class AVLTree
{
public:
	AVLTree() :_root(nullptr){}
	~AVLTree(){ Erase(_root); }
	bool Search(const T& k, AVLNode<T> *&f, AVLNode<T>* &p)const;
	AVLTree<T>& Insert(const T & e);
	AVLTree<T>& Delete(const T& k, T& e);
	void InOut(){ InOutPut(_root); }
	void PostOut(){ PostOutPut(_root); }

private:
	AVLNode<T>* _root;
	//Delete all nodes in AVL Tree with root
	void Erase(AVLNode<T>* t);

	//InOrderTravers
	void InOutPut(AVLNode<T>* t);

	//PostOrderTravers
	void PostOutPut(AVLNode<T>* t);

	//Balance factors form q to r were originally 0
	void FixBF(AVLNode<T>* q, AVLNode<T>* r, const int & e);

	//PA is parent of A, B left child of A
	void RRrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B);
	void LLrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B);
	void RLrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B);
	void LRrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B);
};

template <class T>
void AVLTree<T>::PostOutPut(AVLNode<T>* t)
{
	// Output in postorder.  
	if (t)
	{
		PostOutPut(t->_leftChild);
		PostOutPut(t->_rightChild);
		cout << t->data << " ";
	}
}

template <class T>
void AVLTree<T>::InOutPut(AVLNode<T>* t)
{
	// Output in ascending order.  
	// Use an inorder traversal.  
	if (t)
	{
		InOutPut(t->_leftChild);
		cout << t->data << " ";
		InOutPut(t->_rightChild);
	}
}

template <class T>
AVLTree<T>& AVLTree<T>::Delete(const T& k, T& e)
{
	// Delete element with key k and put it in e.  
	// Throw BadInput exception if there is no element  
	// with key k.  

	// define a stack to hold path taken from root  
	// to physically deleted node  
	// we will not run out of stack space unless  
	// the number of elements is much more than 2^60  
	stack<AVLNode<T> *> st;

	// set p to point to node with key k  
	AVLNode<T> *p = _root; // search pointer  
	while (p && p->data != k)
	{// move to a child of p  
		st.push(p);
		if (k < p->data)
			p = p->_leftChild;
		else
			p = p->_rightChild;
	}
	if (!p)
	{
		cout << "要删除的值不存在" << endl; // no element with key k  
		return *this;
	}
	e = p->data;  // save element to delete  

	// restructure tree  
	// handle case when p has two children  
	if (p->_leftChild && p->_rightChild)
	{// two children  
		// convert to zero or one child case  
		// find largest element in left subtree of p  
		st.push(p);
		AVLNode<T> *s = p->_leftChild;
		while (s->_rightChild)
		{// move to larger element  
			st.push(s);
			s = s->_rightChild;
		}

		// move largest from s to p  
		p->data = s->data;
		p = s;
	}

	// p has at most one child  
	// save child pointer in c  
	AVLNode<T> *c;
	if (p->_leftChild)
		c = p->_leftChild;
	else
		c = p->_rightChild;

	// delete p  
	if (p == _root)
		_root = c;
	else
	{// is p a left or right child?  
		if (p == st.top()->_leftChild)
			st.top()->_leftChild = c;
		else
			st.top()->_rightChild = c;
	}
	int f = p->data; // f may not equal e  
	delete p;

	// rebalance tree and correct balance factors  
	// use stack to retrace path to root  
	// set q to parent of deleted node  
	AVLNode<T> *q;
	if (!st.empty())
	{
		q = st.top();
		st.pop();
	}
	else
		return *this; //根节点被删  

	while (q)
	{
		if (f <= q->data)
		{
			// deleted from left subtree of q  
			// height of left subtree reduced by 1  
			q->bf--;
			if (q->bf == -1) // height of q is unchanged  
				return *this;       // nothing more to do                 
			if (q->bf == -2)
			{// q is unbalanced  
				// classify imbalance and rotate  
				AVLNode<T> *B = q->_rightChild,
					*PA;  // q is A node  
				// PA is parent of A  
				if (!st.empty())
				{
					PA = st.top();
					st.pop();
				}
				else
					PA = 0; // A is root  

				switch (B->bf)
				{
				case 0:    // L0 imbalance  
					RRrotate(PA, q, B);
					B->bf = 1;
					q->bf = -1;  // q is A node  
					return *this;
				case 1:    // L1 imbalance  
					RLrotate(PA, q, B);
					break;  // must continue on path to root  
				case -1:   // L-1 imbalance  
					RRrotate(PA, q, B);
				}
				q = PA;
			}
			else
			{// q->bf is 0  
				if (!st.empty())
				{
					q = st.top();
					st.pop();
				}
				else
					return *this;
			}
		}
		else
		{// f > q->data  
			// deleted from right subtree of q  
			// height of right subtree reduced by 1  
			q->bf++;
			if (q->bf == 1) // height of q is unchanged  
				// nothing more to do  
				return *this;
			if (q->bf == 2)
			{// q is unbalanced  
				// classify imbalance and rotate  
				AVLNode<T> *B = q->_leftChild,
					*PA;  // q is A node  
				// PA is parent of A  
				if (!st.empty())
				{
					PA = st.top();
					st.pop();
				}
				else
					PA = 0; // A is root  

				switch (B->bf)
				{
				case 0:    // R0 imbalance  
					LLrotate(PA, q, B);
					B->bf = -1;
					q->bf = 1;  // q is A node  
					return *this;
				case 1:    // R1 imbalance  
					LLrotate(PA, q, B);
					break;  // must continue on path to root  
				case -1:   // R-1 imbalance  
					LRrotate(PA, q, B);
				}
				q = PA;
			}
			else
			{// q->bf is 0  
				if (!st.empty())
				{
					q = st.top();
					st.pop();
				}
				else
					return *this;
			}
		}
	}
	return *this;
}

template <class T>
AVLTree<T>& AVLTree<T>::Insert(const T & e)
{
	AVLNode<T> *p = _root,  // search pointer  
		*pp = 0,    // parent of p  
		*A = 0,     // node with bf != 0  
		*PA;        // parent of A  
	// find place to insert  
	// also record most recent node with bf != 0  
	// in A and its parent in PA  
	while (p)
	{// examine p->data  
		if (p->bf)
		{// new candidate for A node  
			A = p;
			PA = pp;
		}
		pp = p;
		// move p to a child  
		if (e < p->data)
			p = p->_leftChild;
		else if (e > p->data)
			p = p->_rightChild;
		else
			cout << "与该值相等的元素已存在" << endl;
	}

	// get a node for e and attach to pp  
	AVLNode<T> *r = new AVLNode<T>(e);
	if (_root)
	{// tree not empty  
		if (e < pp->data)
			pp->_leftChild = r;
		else
			pp->_rightChild = r;
	}
	else
	{// insertion into empty tree  
		_root = r;
		return *this;
	}
	// see if we must rebalance or simply change  
	// balance factors  
	if (A) // possible rebalancing needed  
	{
		if (A->bf < 0) // bf = -1 before insertion  
		{
			if (e < A->data)
			{// insertion in left subtree  
				// height of left subtree has increased by 1  
				// new bf of A is 0, no rebalancing  
				A->bf = 0;
				// fix bf on path from A to r  
				FixBF(A->_leftChild, r, e);
			}
			else
			{// insertion in right subtree  
				// bf of A is -2, rebalance  
				AVLNode<T> *B = A->_rightChild;
				if (e > B->data)
				{// RR case  
					FixBF(B->_rightChild, r, e);
					RRrotate(PA, A, B);
				}
				else
				{// RL case  
					FixBF(B->_leftChild, r, e);
					RLrotate(PA, A, B);
				}
			}
		}
		else // bf = 1 before insertion  
		{
			if (e > A->data)
			{// insertion in right subtree  
				// height of right subtree has increased by 1  
				// new bf of A is 0, no rebalancing  
				A->bf = 0;
				// fix bf on path from A to r  
				FixBF(A->_rightChild, r, e);
			}
			else
			{// insertion in left subtree  
				// bf of A is +2, rebalance  
				AVLNode<T> *B = A->_leftChild;
				if (e < B->data)
				{// LL case  
					FixBF(B->_leftChild, r, e);
					LLrotate(PA, A, B);
				}
				else
				{// LR case  
					FixBF(B->_rightChild, r, e);
					LRrotate(PA, A, B);
				}
			}
		}
	}
	else // A is NULL, no rebalancing  
		FixBF(_root, r, e);

	return *this;
}

template <class T>
void AVLTree<T>::LRrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B)
{
	AVLNode<T> *C = B->_rightChild;

	// restructure subtree at A  
	A->_leftChild = C->_rightChild;
	B->_rightChild = C->_leftChild;
	C->_leftChild = B;
	C->_rightChild = A;
	if (PA) // A is not the root  
	{
		if (A == PA->_leftChild)
			PA->_leftChild = C;
		else PA->_rightChild = C;
	}
	else _root = C;

	// set balance factors  
	int b = C->bf;
	if (b == 1)
	{
		B->bf = 0;
		A->bf = -1;
	}
	else if (b == -1)
	{
		B->bf = 1;
		A->bf = 0;
	}
	else // b = 0  
		B->bf = A->bf = 0;
	C->bf = 0;
}

template <class T>
void AVLTree<T>::RLrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B)
{
	AVLNode<T> *C = B->_leftChild;

	// restructure subtree at A  
	A->_rightChild = C->_leftChild;
	B->_leftChild = C->_rightChild;
	C->_leftChild = A;
	C->_rightChild = B;
	if (PA) // A is not the root  
	{
		if (A == PA->_leftChild)
			PA->_leftChild = C;
		else PA->_rightChild = C;
	}
	else _root = C;

	// set balance factors  
	int b = C->bf;
	if (b == 1)
	{
		B->bf = -1;
		A->bf = 0;
	}
	else if (b == -1)
	{
		B->bf = 0;
		A->bf = 1;
	}
	else // b = 0  
		B->bf = A->bf = 0;
	C->bf = 0;
}

template <class T>
void AVLTree<T>::RRrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B)
{
	A->_rightChild = B->_leftChild;
	B->_leftChild = A;
	if (PA)
	{
		if (A == PA->_leftChild)
			PA->_leftChild = B;
		else
			PA->_rightChild = B;
	}
	else
	{
		_root = B;
	}
	A->bf = B->bf = 0;
}

template <class T>
void AVLTree<T>::LLrotate(AVLNode<T>* PA, AVLNode<T>* A, AVLNode<T>* B)
{
	A->_leftChild = B->_rightChild;
	B->_rightChild = A;
	if (PA)
	{
		if (A == PA->_leftChild)
			PA->_leftChild = B;
		else
			PA->_rightChild = B;
	}
	else
		_root = B;

	A->bf = B->bf = 0;
}

template <class T>
void AVLTree<T>::FixBF(AVLNode<T>* q, AVLNode<T>* r, const int & e)
{
	while (q != r)
	{
		if (e < q->data)
		{
			q->bf = 1;
			q = q->_leftChild;
		}
		else
		{
			q->bf = -1;
			q = q->_rightChild;
		}
	}
}

template <class T>
bool AVLTree<T>::Search(const T& k, AVLNode<T> *&f, AVLNode<T>* &p) const
{
	p = _root;
	while (p)
	{
		if (k < p->data)
		{
			f = p;
			p = p->_leftChild;
		}
		else if (k>p->data)
		{
			f = p;
			p = p->_rightChild;
		}
		else
		{
			return true;
		}
	}
	return false;
}

template <class T>
void AVLTree<T>::Erase(AVLNode<T>* t)
{
	if (t)
	{
		Erase(t->_leftChild);
		Erase(t->_rightChild);
		delete t;
	}
}

#endif