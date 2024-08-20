#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
#include<list>
using namespace std;

// ģ���ԭ���ǽ�����Ҫ�����½���������ȥ



// vector<vector<int>> vv(10, v);   // �е����ά����

// vector<int> v(5, 1);

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// C++11 ǰ������Ĭ�Ϲ���
		vector() = default;

		// ��������
		//vector(const vector<T>& v)
		vector(const vector& v)
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		// ����
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

		// ģ��
		// �������͵�������ʼ����Ҫ��������ƥ���
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

		// ����ڶ���constû�У��ͻᵼ�£����� const ���󣬽��޷�������� begin ��������Ϊ const ����ֻ�ܵ��� const ��Ա������
		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		// ����
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();

				T* tmp = new T[n];
				//memcpy(tmp, _start, size() * sizeof(T));
				// T��һ�����������ͣ����ܻ�������룬�����
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

		// β��
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
				size_t len = pos - begin();// ��ֹ���ݺ������λ�÷����仯
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

		// ɾ��ָ��λ��
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
		void swap(vector& v)// ������Ӳ���<T>����
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

	// ���ģ��
	template<class T>
	void print_vector(const vector<T>& v)
	{
		// �����typename
		// ��û��ʵ��������ģ�壨û��int�ȣ���ȡ�����������������������const_iterator�����ͻ��Ǿ�̬��Ա���������ǳ�����飩
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

		// ɾ�����е�ż��
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

