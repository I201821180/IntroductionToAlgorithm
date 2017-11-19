/**
 * 1. ����ָ��Ϊ�ջ�Ϊ�յ��жϣ�ȫ��д��if(!p)��if(p)����ʽ������nullptr���Ƚ�
 * 2. nullptr��Ϊ������ת��������ƥ���õ�
 */

#include "binaryTree.h"


template<typename T>
binaryTree<T>::binaryTree()
{
	root_ = nullptr;
}

template<typename T>
binaryTree<T>::binaryTree(std::initializer_list<T> _il)
	: binaryTree()
{
	for (const T& item : _il)
	{
		/*pNode newNode = new node<T>(item);
		treeInsert(newNode);*/
		insert(item);
	}
}

template<typename T>
binaryTree<T>::binaryTree(std::vector<T>& _v)
	: binaryTree()
{
	for (const T& item : _v)
	{
		//std::cout << item << std::endl;
		/*pNode newNode = new node<T>(item);
		treeInsert(newNode);*/
		insert(item);
	}
}

template<typename T>
binaryTree<T>::~binaryTree()
{
	treeFree(root_);
}

template<typename T>
void binaryTree<T>::preOrderTreeWalk(pNode _x)
{
	/*ǰ�����*/
	if (_x)
	{
		std::cout << _x->key() << " ";
		preOrderTreeWalk(_x->left());
		preOrderTreeWalk(_x->right());
	}
}

template<typename T>
void binaryTree<T>::inOrderTreeWalk(pNode _x)
{
	/*�������*/
	if (_x)
	{
		inOrderTreeWalk(_x->left());
		std::cout << _x->key() << " ";
		inOrderTreeWalk(_x->right());
	}
}

template<typename T>
void binaryTree<T>::postOrderTreeWalk(pNode _x)
{
	/*�������*/
	if (_x)
	{
		postOrderTreeWalk(_x->left());
		postOrderTreeWalk(_x->right());
		std::cout << _x->key() << " ";
	}
}

template<typename T>
void binaryTree<T>::print()
{
	inOrderTreeWalk(root_);
	std::cout << std::endl;
}

/**
 * 1. ��ģ��ĳ�Ա�����ķ���ֵ�����ͱ���ʱ����Ҫʹ��typename class<T>::alias������ʽ
 * 2. �漰��һ���� template��ģ�壩�е� nested dependent type name��Ƕ��������������
 *    ���κ�ʱ�������ѵ��� typename ���ڽ���������ǰ��
 * 3. �������ܸ��߱�������������һ������������������ᱻ�����Ǳ�ı�ʶ��
 */
template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeSearch(pNode _x, T _key)
{
	/*���ң��õݹ�*/
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
typename binaryTree<T>::pNode binaryTree<T>::iterativeTreeSearch(pNode _x, T _key)
{
	/*���ң���ѭ������ݹ飬Ч�ʸ�*/
	while (_x && _key != _x->key())
	{
		if (_key < _x->key())
		{
			_x = _x->left();
		}
		else
		{
			_x = _x->right();
		}
	}
	return _x;
}

template<typename T>
T binaryTree<T>::search(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	return res->key();
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeMinimum(pNode _x)
{
	/*����������ߵ�һ����*/
	while (_x->left())
	{
		_x = _x->left();
	}
	return _x;
}

template<typename T>
T binaryTree<T>::min()
{
	pNode res = treeMinimum(root_);
	return res->key();
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeMaximum(pNode _x)
{
	/*���������ұߵ�һ����*/
	while (_x->right())
	{
		_x = _x->right();
	}
	return _x;
}

template<typename T>
T binaryTree<T>::max()
{
	pNode res = treeMaximum(root_);
	return res->key();
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeSuccessor(pNode _x)
{
	/*��ǰ�ڵ������ӽڵ㣬�����ұ��Һ��*/
	if (_x->right())
	{
		return treeMinimum(_x->right());
	}
	/*��ǰ�ڵ�û�����ӽڵ㣬���Ÿ��ڵ���ұ������Һ��*/
	pNode y = _x->parent();
	while (y && _x == y->right())
	{
		_x = y;
		y = y->parent();
	}
	return y;
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treePreSuccessor(pNode _x)
{
	/*��ǰ�ڵ������ӽڵ㣬���������ǰ��*/
	if (_x->left())
	{
		return treeMaximum(_x->left());
	}
	pNode y = _x->parent();
	while (y && _x == y->left())
	{
		_x = y;
		y = y->parent();
	}
	return y;
}

template<typename T>
T binaryTree<T>::successor(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	pNode suc = treeSuccessor(res);
	return suc->key();
}

template<typename T>
T binaryTree<T>::preSuccessor(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	pNode suc = treePreSuccessor(res);
	return suc->key();
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
		/*��Ϊ��*/
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
		/*��y��_z*/
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
	delete _z;
}

template<typename T>
void binaryTree<T>::insert(T _key)
{
	pNode newNode = new node<T>(_key);
	treeInsert(newNode);
}

template<typename T>
void binaryTree<T>::remove(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	treeDelete(res);
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

template class binaryTree<int>;
template class binaryTree<std::string>;
template class binaryTree<std::shared_ptr<std::string>>;

