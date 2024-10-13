#pragma once
#include<iostream>
#include<map>
#include<utility>

enum Colour{
	RED,
	BLACK
};

// Ϊ��ʵ�ַ���
template<class T>
struct RBTreeNode
{
	// ������¿���ƽ��ҲҪ����parentָ��
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

// T ����		Ref ����		Ptrָ��
template<class T, class Ref, class Ptr>
struct RBTreeIterator {
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;
	Node* _root;

	RBTreeIterator(Node* node, Node* root)
		:_node(node)
		, _root(root)
	{}

	Self operator++() {
		if (_node->_right) {
			// �Ҳ�Ϊ�գ���һ�����ʵĽڵ���������������ڵ�
			Node* minRight = _node->_right;
			while (minRight->_left) {
				minRight = minRight->_left;
			}
			_node = minRight;
		}
		// ��Ϊ�գ����ʣ������Ǹ��ף�����
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right) {
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self operator--()
	{
		if (_node == nullptr)  // --end()
		{
			// --end()�����⴦���ߵ��������һ����㣬�����������ҽ��
			Node* rightMost = _root;
			while (rightMost && rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else if (_node->_left)
		{
			// ��������Ϊ�գ��������������һ��
			Node* rightMost = _node->_left;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else
		{
			// �����Ǹ����ҵ��Ǹ�����
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
	}

	Ref operator*() {
		return _node->_data;
	}
	Ptr operator->() {
		return &_node->_data;
	}
	bool operator!= (const Self& s) const {
		return _node != s._node;
	}
	bool operator== (const Self& s) const {
		return _node == s._node;
	}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> Const_Iterator;

	Iterator Begin() {
		Node* cur = _root;
		while (cur && cur->_left) {
			cur = cur->_left;
		}
		return Iterator(cur, _root);
	}
	Iterator End() {
		return Iterator(nullptr, _root);
	}

	Const_Iterator Begin() const{
		Node* cur = _root;
		while (cur && cur->_left) {
			cur = cur->_left;
		}
		return Iterator(cur, _root);
	}
	Const_Iterator End() const{
		return Iterator(nullptr, _root);
	}

	bool Insert(const T& data) {
		if (_root == nullptr)	{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}
		 
		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (kot(cur->_data) < kot(data)){
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data)) {
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;

		}

		cur = new Node(data);
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
			parent->_right = cur;
		else
			parent->_left = cur;
		
		// ���Ӹ���
		cur->_parent = parent;

		// �����Ǻ�ɫ�����������ĺ�ɫ�ڵ㣬��Ҫ����
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			// ������үү��������
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// ���������Ϊ�죬���ϱ�ɫ����
				if (uncle && uncle->_col == RED){
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					if (cur == parent->_left)	{
						//     g
						//   p    u
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else{
						//      g
						//   p    u
						//     c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			// ������үү��������
			else{
				//   g
				// u   p
				Node* uncle = grandfather->_left;
				// ���������Ϊ�죬���ϱ�ɫ����
				if (uncle && uncle->_col == RED){
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					// ����������岻���ڻ��ߴ�����Ϊ��
					// ��ת+��ɫ
					//   g
					// u   p
					//       c
					if (cur == parent->_right){
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	void RotateR(Node* parent){
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root){
			_root = subL;
			subL->_parent = nullptr;
		}
		else{
			if (pParent->_left == parent)
				pParent->_left = subL;
			else
				pParent->_right = subL;

			subL->_parent = pParent; 
		}
	}

	void RotateL(Node* parent){
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr){
			_root = subR;
			subR->_parent = nullptr;
		}
		else{
			if (parent == parentParent->_left)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;

			subR->_parent = parentParent;
		}
	}

	int Height(){
		return _Height(_root);
	}

	int Size(){
		return _Size(_root);
	}


private:
	// �߶�
	int _Height(Node* root){
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	// Ԫ�ظ���
	int _Size(Node* root){
		if (root == nullptr)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

private:
	Node* _root = nullptr;
};
