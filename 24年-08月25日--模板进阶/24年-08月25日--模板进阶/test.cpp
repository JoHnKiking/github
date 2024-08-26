#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<array>
#include<vector>


using namespace std;

//namespace bite
//{
//	// 定义一个模板类型的静态数组
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index)
//		{
//			return _array[index];
//		}
//		const T& operator[](size_t index)const
//		{
//			return _array[index];
//		}
//		size_t size()const
//		{
//			return _size;
//		}
//		bool empty()const
//		{
//			return 0 == _size;
//		}
//
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
//
//int main()
//{
//	// 1、
//	// array数据在栈上
//	// 栈 开空间 相比 堆 效率更高
//	array<int, 10> a1;
//	array<int, 100> a2;
//
//	// array越界读写都可以检查
//	//a1[10];
//	//a2[12] = 10;
//
//
//	// 2、
//	// 静态数组
//	// 越界读不检查
//	int a3[10];
//	cout << a3[1] << endl; 
//
//	// 越界写抽查
//	//a3[12] = 10;
//	//cout << a3[12] << endl;
//
//
//	// 3、
//	// 堆
//	vector<int> v(100, 1);
//	cout << sizeof(a1) << endl;
//	cout << sizeof(v) << endl;
//
//	return 0;
//}


// 日期类
class Date
{
	// 友元函数
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	// 列表
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

// 函数模板 -- 参数匹配
template<class T>
bool Less(const T& left, const T& right)
{
	return left < right;
}

// 特化
// 1、不推荐
// 容易不匹配
template<>
bool Less<const Date*>(const Date* const& left, const Date* const& right)
{
	return *left < *right;
}
// 2、推荐
// 注意：一般情况下如果函数模板遇到不能处理或者处理有误的类型，为了实现简单通常都是将该函数直接给出
bool Less(Date* left, Date* right)
{
	return *left < *right;
}

//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	// 此时按的是指针比较
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//
//	const Date* p3 = &d1;
//	const Date* p4 = &d2;
//	cout << Less(p3, p4) << endl; // 可以比较，结果错误
//
//	// const 和 类型 的位置可以倒置，不影响
//	const int i = 0;
//	int const j = 0;
//
//	// 引用也一样
//	const int& r = i;
//	int const& ry = i;
//	
//	return 0;
//}


template<class T1, class T2>
class Data
{
	public :
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 全特化
template<>
class Data<int, char>
{
	public :
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

// 偏特化/半特化 
template<class T1>
class Data<T1, double>
{
	public :
	Data() { cout << "Data<T1, double>" << endl; }
private:
	T1 _d1;
	double _d2;
};

template<typename T1, typename T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>" << endl;
		T1 x;
		cout << typeid(x).name() << endl;
	}
};

template<typename T1, typename T2>
class Data<T1&, T2&>
{
public:
	Data()
	 {
		cout << "Data<T1&, T2&>" << endl;
	}
};

void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<int, double> d3;
	Data<int&, char&> d4;
	Data<int*, char*> d5;
}

int main()
{
	TestVector(); 
	return 0;
}