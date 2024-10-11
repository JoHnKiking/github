#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;


// 枚举值表⽰颜⾊
enum Colour{
	RED,
	BLACK
};

// 这⾥我们默认按key/value结构实现
template<class K, class V>
struct RBTreeNode{
	// 这⾥更新控制平衡也要加⼊parent指针
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;
	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

template<class k, class v>
class RBTree{
	typedef RBTreeNode<k, v> Node;
public:
	// 旋转代码的实现跟AVL树是⼀样的，只是不需要更新平衡因⼦
	bool Insert(const pair<k, v>& kv){
		if (_root == nullptr)	{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		// 按平衡二叉树的插入规则插入
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}else	return false;
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)	{
			parent->_right = cur;
			cur->_parent = parent;
		}else {
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 连接父亲
		cur->_parent = parent;
		// 如果父亲是红色，就调整
		while (parent && parent->_col == RED) { // 父亲不能为空
			// 确认 g 爷爷位置
			Node* grandfather = parent->_parent;
			// 确认 u 叔叔位置
			if (parent == grandfather->_left) Node* uncle = grandfather->_right;
			else 	Node* uncle = grandfather->_left;

			// 变色 或 旋转
			if (uncle && uncle->_col == RED) { // 存在 u 且为黑时，可以逐层往上变色
				parent->_col = uncle->_col == BLACK;
				grandfather->_col = RED;
				// 继续往上处理
				cur = grandfather;
				parent = cur->_parent;
			} else { // 不存在 u 或为黑时，需要旋转+变色
				if (parent == grandfather->_left) {
					if (cur == parent->_left) { // 右单旋 g
						//			g								p
						//		p		u          ->		c		g
						// c												u
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}else { // 先左单旋 p ，使其左边单调，再右单旋 g
						//			g								g									c
						//		p		u          ->		c		u			->				p		g	
						//			c						p													u
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}else {
					if (cur == parent->_right) {
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}else {
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
				break;
			}
		}
		_root->col = BLACK;
		return true;
	}

	// 左单旋

	// 右单旋
	
	
private:
	Node* _root = nullptr;
};