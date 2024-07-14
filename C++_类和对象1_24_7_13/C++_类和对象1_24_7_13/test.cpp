#define _CRT_SECURE_NO_WARNINGS 1

//C++ void* 无法隐式转换为其他类型的指针
//但 C 可以

//C++ NULL 代表 0

//nullptr 可以转换为任意类型的指针，但是不能为整形（指针专用）



//-------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------




//类和对象1

//class 为定义类的关键词

#include<iostream>
using namespace std;

class Stack
{
	//成员函数


	//成员变量


	//访问限定符			public公有			private私有			protected保护
	//1.	从该访问限定符到下一个访问限定符为止，或者类的结束
	//2.	class默认私有private，struc默认公有public
	//3.	类名就是类型
	//4.	可以使用struct定义类，但是C语言中不能这么做




};


//C++兼容C语言struct的用法，下面两套都可以编译
//C语言用法
typedef struct ListNodeC
{
	int val;
	struct ListNodeC* next;
}ListNodeC;
//CPP用法
struct ListNodeCPP
{
	int val;
	ListNodeCPP* next;
};


//声明和定义放一起
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	//为了区分成员变量，一般在开头添加特殊标识"_"或"m"，无固定标准规范
	int _year;
	int _month;
	int _day;
};


//声明和定义分离
class Date1
{
public:
	void Init(int year, int month, int day);
private:
	int _year;
	int _month;
	int _day;
};
void Date1::Init(int year, int month, int day)//类域函数
{
	_year = year;
	_month = month;
	_day = day;
}


//类域
//影响编译的查找规则
class Queue
{
public:
	void Push(int x);
};


//内存对齐规则和C语言完全一样
//之所以需要对齐，是因为如果每次都读取固定长度，后面的数据可能需要分两次读取，造成错误

//没有成员变量的B和C大小只有1个字节，用来占位标识对象存在
class B
{
public:
	void Prinrt()
	{

	}
};

class C
{
};


//3.	this隐藏指针
//编译器编译后，类的成员函数默认都会在形参第⼀个位置，增加⼀个当前类类型的指针，叫做this指针。
class Date2
{
public:
	//void Init(Date2* const this, int year, int month, int day);
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//void Print(Date2* const this)
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	//为了区分成员变量，一般在开头添加特殊标识"_"或"m"，无固定标准规范
	int _year;
	int _month;
	int _day;
};
//C++规定不能在实参和形参的位置显⽰的写this指针(编译时编译器会处理)，但是可以在函数体内显⽰使⽤this指针。
//this指针在内存的栈中   



//面向对象的三大特性			封装			继承			多态

 


int main()
{
	//Date d;

	//B b;
	//C c;
	//cout << sizeof(b) << endl;//1
	//cout << sizeof(c) << endl;//1

	return 0;
}