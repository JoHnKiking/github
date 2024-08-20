#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace bit
{
	// Container适配转换出stack
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		// 先进先出
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			// 按需实例化，实例化时只会实例化调用的函数
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