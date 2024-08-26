#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


//template<size_t N>
//class Stack
//{
//private:
//	int _a[N];
//	int _top;
//};
//int main()
//{
//	Stack<5> s1;
//	Stack<10> s2;
//
//	return 0;
//}


//template<class T, size_t N = 10>
//class Array
//{
//public:
//	T& operator[](size_t index) 
//	{ 
//		assert(index < N);
//		return _array[index];
//	}
//private:
//	T _array[N];
//	size_t _size;
//};
//
//int main()
//{
//	Array<int, 10> a1;
//	Array<int, 100> a2;
//
//		int a3[10];
//		// 越界检查的问题
//		// 静态数组，抽查
//		// 越界读不检查，越界写抽查
//		std::cout << a3[10] << std::endl;
//
//		//a3[10] = 10;
//		//a3[11] = 10;
//		//a3[12] = 10;
//		//a3[20] = 10;
//
//		// 堆
//		vector<int> v(10, 1);
//		cout << sizeof(a1) << endl;
//		cout << sizeof(v) << endl;
//	
//	return 0;
//}


// 函数模板 -- 参数匹配
template<class T>
//bool LessFunc(T const & left, T const & right)
bool LessFunc(const T& left, const T& right)
{
	return left < right;
}
int main()
{
	cout << LessFunc(1, 2) << endl; // 可以比较，结果正确

	Date d1(2022, 7, 7);
	Date d2(2022, 7, 8);
	cout << LessFunc(d1, d2) << endl; // 可以比较，结果正确

	Date* p1 = &d1;
	Date* p2 = &d2;
	cout << LessFunc(p1, p2) << endl; // 可以比较，结果错误

	return 0;
} 


class MinStack
{
	public :
	void push(int x)
	{
		// 只要是压栈，先将元素保存到_elem中
		_elem.push(x);
		// 如果x小于_min中栈顶的元素，将x再压入_min中
		if (_min.empty() || x <= _min.top())
			_min.push(x);
	} v	oid pop()
	{
		// 如果_min栈顶的元素等于出栈的元素，_min顶的元素要移除
		if (_min.top() == _elem.top())
			_min.pop();
		_elem.pop();
	} i
		nt top() { return _elem.top(); }
	int getMin() { return _min.top(); }
private:
	// 保存栈中的元素
	std::stack<int> _elem;
	// 保存栈的最小值
	std::stack<int> _min;
};

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//入栈和出栈的元素个数必须相同
		if (pushV.size() != popV.size())
			return false;
		// 用s来模拟入栈与出栈的过程
		int outIdx = 0;
		int inIdx = 0;
		stack<int> s;
		while (outIdx < popV.size())
		{
			// 如果s是空，或者栈顶元素与出栈的元素不相等，就入栈
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			} /	/ 栈顶元素与出栈的元素相等，出栈
				s.pop();
			outIdx++;
		} return true;
	}
};

#include<vector>
namespace bite
{
	template<class T>
	class stack
	{
	public:
		stack() {}
		void push(const T& x) { _c.push_back(x); }
		void pop() { _c.pop_back(); }
		T& top() { return _c.back(); }
		const T& top()const { return _c.back(); }
		size_t size()const { return _c.size(); }
		bool empty()const { return _c.empty(); }
	private:
		std::vector<T> _c;
	};
}


#include <list>
namespace bite
{
	template<class T>
	class queue
	{
	public:
		queue() {}
		void push(const T& x) { _c.push_back(x); }
		void pop() { _c.pop_front(); }
		T& back() { return _c.back(); }
		const T& back()const { return _c.back(); }
		T& front() { return _c.front(); }
		const T& front()const { return _c.front(); }
		size_t size()const { return _c.size(); }
		bool empty()const { return _c.empty(); }
	private:
		std::list<T> _c;
	};
}