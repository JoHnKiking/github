#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace bit
{
	// 单个节点
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		// 缺省构造函数
		list_node(const T& data = T())
			:_data(data) 
			, _next(nullptr)
			,_prev(nullptr)
		{}
	};

	// 迭代器  -  结构体
	// 利用迭代器实现STL数据库
	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		// 构造函数
		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		// 返回的是指针
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const Self & s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};


	/*template<class T>
	struct list_const_iterator
	{
		typedef list_node<T> Node;
		typedef list_const_iterator<T> Self;
		Node* _node;

		 构造函数
		list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_data;
		}

		 返回的是指针
		const T* operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};*/


	// 链表
	template<class T>
	class list
	{
		// 重命名
		typedef list_node<T> Node;

	public:
		/*typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/

		// 利用模板实现两个类（高度相似的两个类）
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void empty_init()
		{
			// 哨兵位
			_head = new Node(T());
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;

		}

		list()
		{
			empty_init();
		}

		// lt2(lt1) 拷贝构造
		list(const list <T>& it)
		{
			empty_init();
			for (auto& e : it)
			{
				push_back(e);
			}
		}
		
		// lt1 = lt3
		list<T>& operator=(list<T> it)
		{
			swap(it);
			return *this;
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			newnode->_next = cur;
			newnode->_prev = prev;

			prev->_next = newnode;
			cur->_prev = newnode;
		}

		void push_back(const T& x)
		{
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev;

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;

			//_head->_prev = newnode;

			//++_size;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;

			delete pos._node;

			return next;
		}

		void pop_back()
		{
			erase(end()--);
		}

		void pop_front()
		{
			earse(begin());
		}
		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			return _size == 0;
		}
	private:
		Node* _head;
		size_t _size; 
	};

	struct AA
	{
		int _a1 = 1;
		int _a2 = 1;
	};

	template<class Container>
	void print_container(const Container& con)
	{
		// const iterator ->迭代器本身不能修改
		// const_iterator -> 指向内容不能修改

		
		// 如果没有typename，编译器可能会错误地将Container::const_iterator解释为一个静态成员变量或成员函数，而不是一个类型。
		typename Container::const_iterator it = con.begin();
		while (it != con.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		for (auto e : con)
		{
			cout << e << " ";;
		}
		cout << endl;
	}


	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		list<AA> lta;
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		list<AA>::iterator ita = lta.begin();
		while (ita != lta.end())
		{
			//cout << (*ita)._a1 << ":" << (*ita)._a2 << endl;
			
			// 特殊处理，本来应该是两个->才合理，为了可读性，省略了一个->
			cout << ita->_a1 << ":" << ita->_a2 << endl;
			cout << ita.operator->()->_a1 << ":" << ita.operator->()->_a2 << endl;

			++ita;
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin(); 
		lt.insert(it, 10);
		*it += 100;
		
		print_container(lt);
		cout << endl;

		// 删除所有的偶数
		it = lt.begin();
		while (it != lt.end())
		{
			if (*it % 2 == 0)
			{
				it = lt.erase(it);
			}
			else
				++it;
		}
		print_container(lt);
	}

	void test_list3()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int> lt2(lt1);
		print_container(lt1);
		print_container(lt2);

		list<int> lt3;
		lt3.push_back(9);
		lt3.push_back(9);
		lt3.push_back(9);
		lt3.push_back(9);

		lt1 = lt3;
		print_container(lt1);
		print_container(lt3);

	}
}