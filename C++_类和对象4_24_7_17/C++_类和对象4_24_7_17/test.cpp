//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//  
//	//拷贝构造
//	//拷贝构造的第一个原则就是，必须是自身类类型的引用
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//构造
//	Date(const Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	// d1 = d2
//	// 赋值运算符重载
//	//有返回值，建议写成当前类类型引用，引用返回可以提高效率，有返回值目的是为了支持连续赋值场景。
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		//this->_year = d._year;
//		_month = d._month;
//		_day = d._day; 
//
//		//this是地址  
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////没有显式实现时，编译器会自动生成一个默认赋值运算符重载，默认赋值运算符重载行为跟默认拷贝构造函数类似，
//// 对内置类型成员变量会完成值拷贝 / 浅拷贝(一个字节一个字节的拷贝)，对自定义类型成员变量会调用他的拷贝构造。
//
//int main()
//{
//	Date d1(2024, 7, 10);
//	Date d2(2024, 7, 12);
//	d1.Print();
//
//	//复值重载拷贝
//	d1 = d2;
//
//	
//	//拷贝构造
//	//拿一个同类型的去构造，这种构造称为拷贝构造
//	Date d3(d1);
//	Date d4 = d1;
//	d3.Print();
//	d4.Print();
//
//
//
//	return 0;
//}


#include"Date.h"

int main()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;

	d1.Print();
	d2.Print();

	d1 += 100;
	d1.Print();

}