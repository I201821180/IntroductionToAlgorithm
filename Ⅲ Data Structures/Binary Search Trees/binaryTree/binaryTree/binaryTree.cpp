/**
 * 1. 所有指针为空或不为空的判断，全部写成if(!p)或if(p)的形式，不和nullptr做比较
 * 2. nullptr是为了完美转发和重载匹配用的
 */

#include "binaryTree.h"
#include <iostream>

template<typename T>
binaryTree<T>::binaryTree()
{
	root_ = nullptr;
}

template<typename T>
binaryTree<T>::binaryTree(std::initializer_list<T> il)
{
	for (const T& item : il)
	{
		pNode newNode = new node<T>(item);
		treeInsert(newNode);
	}
}

template<typename T>
binaryTree<T>::~binaryTree()
{
	treeFree(root_);
}

template<typename T>
void binaryTree<T>::inorderTreeWalk(pNode _x)
{
	/*中序遍历*/
	if (_x)
	{
		inorderTreeWalk(_x->left());
		std::cout << _x->key() << std::endl;
		inorderTreeWalk(_x->right());
	}
}

template<typename T>
pNode binaryTree<T>::treeSearch(pNode _x, T _key)
{
	/*查找，用递归*/
	if (!_x || _key == _x->key())
	{
		return _x;
	}
	if (_key < _x->key())
	{
		return treeSearch(_x->left(), _key);
	}
	else
	{
		return treeSearch(_x->right(), _key);
	}
}

template<typename T>
pNode binaryTree<T>::iterativeTreeSearch(pNode _x, T _key)
{
	/*查找，用循环代替递归，效率高*/
	while (_x && _key != _x->key())
	{
		if (_key < _x->key())
		{
			_x = -x->left();
		}
		else
		{
			_x = _x->right();
		}
	}
	return _x;
}

template<typename T>
pNode binaryTree<T>::treeMinimum(pNode _x)
{
	/*遍历到最左边的一个点*/
	while (_x->left())
	{
		_x = _x->left();
	}
	return _x;
}

template<typename T>
pNode binaryTree<T>::treeMaximum(pNode _x)
{
	/*遍历到最右边的一个点*/
	while (_x->right())
	{
		_x = _x->right();
	}
	return _x;
}

template<typename T>
pNode binaryTree<T>::treeSuccessor(pNode _x)
{
	/*当前节点有右子节点，沿着右边找后继*/
	if (_x->right())
	{
		return treeMinimum(_x->right());
	}
	/*当前节点没有右子节点，沿着父节点的右边向上找后继*/
	pNode y = _x->parent();
	while (y && x == y->right())
	{
		_x = y;
		y = y->parent();
	}
	return y;
}

template<typename T>
void binaryTree<T>::treeInsert(pNode _z)
{
	pNode y = nullptr;
	pNode x = root_;
	while (x)
	{
		y = x;
		if (_z->key() < x->key())
		{
			x = x->left();
		}
		else
		{
			x = x->right();
		}
	}
	_z->setParent(y);
	if (!y)
	{
		/*树为空*/
		root_ = _z;
	}
	else if (_z->key() < y->key())
	{
		y->setLeft(_z);
	}
	else
	{
		y->setRight(_z);
	}
}

template<typename T>
void binaryTree<T>::transplant(pNode _u, pNode _v)
{
	if (!(_u->parent()))
	{
		root_ = _u;
	}
	else if (_u == _u->parent()->left())
	{
		_u->parent()->setLeft(_v);
	}
	else
	{
		_u->parent()->setRight(_v);
	}
	if (_v != nullptr)
	{
		_v->setParent(_u->parent());
	}
}

template<typename T>
void binaryTree<T>::treeDelete(pNode _z)
{
	if (!(_z->left()))
	{
		transplant(_z, _z->right());
	}
	else if (!(_z->right()))
	{
		transplant(_z, _z->left());
	}
	else
	{
		/*用y换_z*/
		pNode y = treeMinimum(_z);
		if (y->parent() != _z)
		{
			transplant(y, y->right());
			y->setRight(_z->right());
			y->right()->setParent(y);
		}
		transplant(_z, y);
		y->setLeft(_z->left());
		y->left()->setParent(y);
	}
}

template<typename T>
void binaryTree<T>::treeFree(pNode _x)
{
	if (_x)
	{
		treeFree(_x->left());
		treeFree(_x->right());
		delete _x;
		_x = nullptr;
		return;
	}
}
