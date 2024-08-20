#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace bit
{
	// Container����ת����stack
	// vector��֧��ͷɾ����listʵ��
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		// �Ƚ��ȳ�
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& top() const
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}