#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace bit
{
	// Container适配转换出stack
	// vector不支持头删，用list实现
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		// 先进先出
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