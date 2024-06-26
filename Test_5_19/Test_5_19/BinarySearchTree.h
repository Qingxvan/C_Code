#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else 
		{
			parent->_left = cur;
		}
		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Eraer(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key) // 比根节点大，往右走
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key) // 比根节点小，往左走
			{
				parent = cur;
				cur = cur->_left;
			}
			else // 相等&删除
			{
				if (cur->_left == nullptr) // 左子树为空
				{
					if (cur == _root) // 删除的值是头结点，直接链接到右节点的子树
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left) 
						{// 删除节点与父节点的左子树相等，将父节点的左子树链接到删除节点的右子树
							parent->_left = cur->_right;
						}
						else
						{// 相反 父节点的右子树链接到删除节点的左子树
							parent->_right = cur->_left;
						}
					}
				}
				else if (cur->_right == nullptr) // 右子树为空
				{
					if (cur == _root) // 假如删除的值是头结点，直接链接到左节点的子树
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else // 左右子树都不为空
				{
					// 找子树当中的最小节点(最左节点)
					Node* parent = cur;
					Node* subLeft = cur->_right;
					while (subLeft->_left)
					{
						parent = subLeft;
						subLeft = subLeft->_left;
					}
					swap(cur->_key, subLeft->_key);
					if (subLeft == parent->_left)
						parent->_left = subLeft->_right;
					else
						parent->_right = subLeft->_right;
				}
				return true;
			}
		}
		return false;
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;

};

