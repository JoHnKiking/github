#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;




template<class T1, class T2>
void func(const T1& x, const T2& y)
{
	  
}

// 用函数模板生成对应的函数 -> 函数的实例化
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

template<class T1, class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

//当形参未输入模板参数类型，就必须显示实例化
template<class T>
T* func1(int n)
{
	return new T[n];
}

//当存在现成的函数，先用现成的
int Add(const int& x, const int& y)
{
	return x + y + 1;
}

int main1()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;


	//推导实例化
	cout << Add(a1, a2) << endl;
	cout << Add(a1, (int)d2) << endl;
	cout << Add(d1, d2) << endl;

	//显示实例化
	cout << Add<int>(a1, d2) << endl;

	double* p1 = func1<double>(5);

	return 0;
}


template<typename T>
class Stack
{
public:
	Stack(int n = 4)
		:_array(new T[n])
		,_size(0)
		,_capacity(0)
	{}
	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}
	void Push(const T& x);//声明定义分离
	//{
	//	if (_size == _capacity)
	//	{
	//		T* tmp = new T[_capacity * 2];
	//		memcpy(tmp, _array, sizeof(T) * _size);
	//		delete[] _array;
	//		_array = tmp;
	//		_capacity *= 2;
	//	}
	//	_array[_size++] = x;
	//}
	
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};
template<class T>
void Stack<T>::Push(const T& x)
{
	if (_size == _capacity)
	{
		T* tmp = new T[_capacity * 2];
		memcpy(tmp, _array, sizeof(T) * _size);
		delete[] _array;
		_array = tmp;
		_capacity *= 2;
	}
	_array[_size++] = x;
}


int main()
{
	//类模板都是显示实例化
	Stack<int> st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);

	Stack<double> st2;
	st2.Push(1.1);
	st2.Push(1.2);
	st2.Push(1.3);

	return 0;
}