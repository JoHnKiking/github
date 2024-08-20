#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace bit
{
	// Container����ת����stack
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		// �Ƚ��ȳ�
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			// ����ʵ������ʵ����ʱֻ��ʵ�������õĺ���
			//_con.pop_front();
			_con.pop_backt();
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