#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

// k 往往是比较时用的值
// v 
template<class k, class v>
struct AVLTreeNode
{
	AVLTreeNode<k, v>* _parent;
	AVLTreeNode<k, v>* _left;
	AVLTreeNode<k, v>* _right;
	pair<k, v> _kv;
	int _bf;

	AVLTreeNode(const pair<k, v>& kv)
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		, _kv(kv)
		,_bf(0)
	{}
};

template<class k, class v>
class AVLTree
{
	typedef AVLTreeNode<k, v> Node;
public:
	bool Insert(const pair<k, v>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		// 找插入位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		// 插入（有问题）
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 看是否需要旋转
		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--; // 左子树减一
			else
				parent->_bf++; // 右子树加一
			
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转
				// ? + 旋 == 哪边高度加一，另一边减1
				if (parent->_bf == -2 && cur->_bf == -1) // 都左边高 -》 右旋
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1) // 都右边高 -》 左旋
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == 1) // 总体左边高，左子树右边高 -》 左子树先左旋，再总体右旋
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1) // 总体右边高，右子树左边高 -》 右子树先右旋，再总体左旋
					RotateRL(parent);
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	// 右旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}

		else
		{
			subL->_parent = parent->_parent;
			Node* pparent = parent->_parent;
			if (parent == pparent->_left)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
		
		subL->_right = parent;
		parent->_parent = subL;
		parent->_left = subLR;
		
		if (subLR)
			subLR->_parent = parent;
		parent->_bf = subL->_bf = 0;
	}

	// 左旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (parent == pparent->_left)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}
		subR->_left = parent;
		parent->_parent = subR;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		parent->_bf = subR->_bf = 0;
	}


	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);
		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 0)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
private:
	Node* _root = nullptr;
};