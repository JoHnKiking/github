#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>

using namespace std;


template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V> _left;
	AVLTreeNode<K, V> _right;
	AVLTreeNode<K, V> _parent;
	int _bf; // �������߶� - �������߶�


	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0) //ƽ�����ӣ�balance factor
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = nullptr;
			return bool
		}
		Node* parent = cur;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		// ���Ӹ���
		cur->_parent = parent;

		// ƽ��
		while (parennt)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ƽ���ˣ���ת����
				break;
			}
			else
			{
				assert(false); // ����֮ǰ�Ͳ��� AVLTree
			}
		}
		return true;
	}

private:
	Node* _root = nullptr;
};

int main()
{


	return 0;
}