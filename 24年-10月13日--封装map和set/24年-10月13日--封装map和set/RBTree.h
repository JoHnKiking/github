#pragma once
#include<iostream>
#include<map>
#include<utility>

enum Colour{
	RED,
	BLACK
};

// 为了实现泛型
template<class T>
struct RBTreeNode
{
	// 这里更新控制平衡也要加入parent指针
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

// T 类型		Ref 数据		Ptr指针
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
			// 右不为空，下一个访问的节点是右子树的最左节点
			Node* minRight = _node->_right;
			while (minRight->_left) {
				minRight = minRight->_left;
			}
			_node = minRight;
		}
		// 右为空，访问（左孩子是父亲）祖先
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
			// --end()，特殊处理，走到中序最后一个结点，整棵树的最右结点
			Node* rightMost = _root;
			while (rightMost && rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else if (_node->_left)
		{
			// 左子树不为空，中序左子树最后一个
			Node* rightMost = _node->_left;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}
			_node = rightMost;
		}
		else
		{
			// 孩子是父亲右的那个祖先
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
		
		// 链接父亲
		cur->_parent = parent;

		// 父亲是红色，出现连续的红色节点，需要处理
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			// 父亲是爷爷的左子树
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// 叔叔存在且为红，往上变色即可
				if (uncle && uncle->_col == RED){
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
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
			// 父亲是爷爷的右子树
			else{
				//   g
				// u   p
				Node* uncle = grandfather->_left;
				// 叔叔存在且为红，往上变色即可
				if (uncle && uncle->_col == RED){
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					// 情况二：叔叔不存在或者存在且为黑
					// 旋转+变色
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
	// 高度
	int _Height(Node* root){
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	// 元素个数
	int _Size(Node* root){
		if (root == nullptr)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

private:
	Node* _root = nullptr;
};
