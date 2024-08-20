#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
#include<list>
using namespace std;

// 模板的原理是将我们要做的事交给编译器去



// vector<vector<int>> vv(10, v);   // 有点像二维数组

// vector<int> v(5, 1);

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// C++11 前置生成默认构造
		vector() = default;

		// 拷贝构造
		//vector(const vector<T>& v)
		vector(const vector& v)
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		// 重载
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}


		void clear()
		{
			_finish = _start;
		}

		// v3 =v1
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				clear();
				reverse(v.size());
				for (auto& e : v)
				{
					push_back(e);
				}
			}
			return *this;
		}

		// 模板
		// 任意类型迭代器初始化，要求类型是匹配的
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		  

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		// 如果第二个const没有，就会导致，对于 const 对象，将无法调用这个 begin 函数。因为 const 对象只能调用 const 成员函数。
		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		// 扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();

				T* tmp = new T[n];
				//memcpy(tmp, _start, size() * sizeof(T));
				// T不一定是内置类型，可能会造成乱码，得深拷贝
				for (size_t i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;

				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty()
		{
			return (_finish == _start);
		}

		// 尾插
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish;

		}

		void pop_back() 
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - begin();// 防止扩容后导致相对位置发生变化
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = begin() + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		// 删除指定位置
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}


		T operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		//void swap(vector<T>& v) 
		void swap(vector& v)// 类里面加不加<T>都行
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

	private:
		iterator  _start = nullptr;
		iterator  _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	// 添加模板
	template<class T>
	void print_vector(const vector<T>& v)
	{
		// 必须加typename
		// 在没有实例化的内模板（没有int等）中取东西，编译器不能区分这个const_iterator是类型还是静态成员变量（仅是初步检查）
		typename vector<T>::const_iterator it = v.begin();

		while (it != v.end())
		{
			cout << *it << "	";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << "	";
		}
		cout << endl;

	}

	template<class Container>
	void print_container(const Container& v)
	{
		/*auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;*/

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		v.insert(v.begin() + 2, 9);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for(auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << endl;

		print_vector(v);
		cout << endl;

		vector<double> vd;
		vd.push_back(1.1);
		vd.push_back(2.2);
		vd.push_back(3.3);
		vd.push_back(4.4);
		vd.push_back(5.5);
		vd.insert(vd.begin() + 2, 9);
		print_vector(vd);
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		print_container(v);

		// 删除所有的偶数
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
				v.erase(it);
			else
				++it;
		}

		print_container(v);
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(4);
		v1.push_back(5);
		  
		v1.resize(10, 9);
		v1.resize(20);
		print_container(v1);

		vector<int> v2(v1);
		print_container(v2);

		vector<int> v3(v1.begin(), v1.begin() + 3);
		print_container(v3);

		vector<string> v4(10, "11111");
		print_container(v4);
		v4.push_back("22222");
		v4.push_back("22222");
		v4.push_back("22222");
		v4.push_back("22222");
		v4.push_back("22222");
		print_container(v4);


	}

}

