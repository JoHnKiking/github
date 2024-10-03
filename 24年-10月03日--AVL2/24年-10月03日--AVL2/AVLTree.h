#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

// k �����ǱȽ�ʱ�õ�ֵ
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
		// �Ҳ���λ��
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

		// ���루�����⣩
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

		// ���Ƿ���Ҫ��ת
		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--; // ��������һ
			else
				parent->_bf++; // ��������һ
			
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת
				// ? + �� == �ı߸߶ȼ�һ����һ�߼�1
				if (parent->_bf == -2 && cur->_bf == -1) // ����߸� -�� ����
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1) // ���ұ߸� -�� ����
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == 1) // ������߸ߣ��������ұ߸� -�� ������������������������
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1) // �����ұ߸ߣ���������߸� -�� ������������������������
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
	// ����
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

	// ����
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