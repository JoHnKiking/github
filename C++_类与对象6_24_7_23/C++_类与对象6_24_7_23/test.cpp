#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//之前我们实现构造函数时，初始化成员变量主要使用函数体内赋值，
// 构造函数初始化还有一种方式，就是初始化列表，
// 初始化列表的使用方式是以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括号中的初始值或表达式。

class Time
{
public:
	//默认构造
	Time(int hour)		//假如没有合适的默认构造函数，就必须传值
		: _hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};


//每个成员都要走初始化列表
//1、在初始化列表初始化的成员
//2、没有在初始化列表的成员
	//a、声明的地方有缺省值用缺省值
	//b、没有缺省值
		//x : 内置类型，不确定，看编译器大概率是随机值
		//y : 自定义类型，调用默认构造，没有默认构造就编译报错
//3、引用 const 没有默认构造自定义 必须在初始化列表初始化

class Date
{
public:
	//初始化列表
	Date(int& xx, int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)

		//, _year(year)  无法实现，只能初始化一次

		, _n(1)//const成员只能在列表初始化时初始化

		, _ref(xx)//引用成员只能在列表初始化时初始化

		, _t(1)

		, _ptr((int*)malloc(12))
	{

		//引用成员变量，const成员变量，没有默认构造的类类型变量，必须放在初始化列表位置进行初始
		//化，否则会编译报错。
		// error C2512: “Time”: 没有合适的默认构造函数可⽤
		// error C2530 : “Date::_ref” : 必须初始化引⽤
		// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象

		if (_ptr == nullptr)
		{
			perror("malloc fail");
		}
		else
			memset(_ptr, 0, 12);
	}

	void Print() const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	//声明

	//普通成员可初始化，可不初始化
	int _year;
	int _month;
	int _day;

	//特殊成员必须初始化
	const int _n;		//const成员只能在列表初始化时初始化

	int& _ref;		//引用成员只能在列表初始化时初始化

	Time _t;	//假如没有合适的默认构造函数，就必须传值

	int* _ptr;
};

int main1()
{
	int x = 1;

	//对象定义
	Date d1(x, 2024, 7, 14);
	d1.Print();

	return 0;
}


//3.static成员
//用static修饰的成员变量，称之为静态成员变量，静态成员变量一定要在类外进行初始化。

//静态成员变量为所有类对象所共享，不属于某个具体的对象，不存在对象中，存放在静态区。

//用static修饰的成员函数，称之为静态成员函数，静态成员函数没有this指针。

//静态成员函数中可以访问其他的静态成员，但是不能访问非静态的，因为没有this指针

//非静态的成员函数，可以访问任意的静态成员变量和静态成员函数。

//突破类域就可以访问静态成员，可以通过类名::静态成员 或者 对象, 静态成员 来访问静态成员变量
	//和静态成员函数。


class A
{
public:
	A()
	{
		++_scount;
	} 
	
	A(const A& t)
	{
		++_scount;
	} 
	
	~A()
	{
		--_scount;
	} 
	
	 static int GetACount()
	{
		return _scount;
	}
private:
	// 类⾥⾯声明
	static int _scount;
};

// 类外⾯初始化
int A::_scount = 0;



int main2()
{ 

	//cout << sizeof(A) << endl;
	//cout << sizeof(int) << endl;
	
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;

	return 0;
}

class CA
{
public:
	CA()
	{
		_ret += _i;
		++_i;
	}
	static int GetRet()
	{
		return _ret;
	}
private:
	static int _i;
	static int _ret;
};
int CA::_i = 1;
int CA::_ret = 0;

class Soulation
{
public:
	int Sum_Solution(int n)
	{
		//CA a[n];			定义一个数组，调用n次构造，但VS不支持变长数组
		CA a[5];
		return CA::GetRet();
	}
};

int main3()
{
	Soulation s;
	cout << s.Sum_Solution(1) << endl;
	return 0;
}

//4.友元
//友元提供了一种突破类访问限定符封装的方式，友元分为 : 友元函数和友元类，在函数声明或者类声明的前面加friend，并且把友元声明放到一个类的里面。
//外部友元函数可访问类的私有和保护成员，友元函数仅仅是一种声明，他不是类的成员函数。
//友元函数可以在类定义的任何地方声明，不受类访问限定符限制。
//一个函数可以是多个类的友元函数。
//友元类中的成员函数都可以是另一个类的友元函数，都可以访问另一个类中的私有和保护成员。
//友元类的关系是单向的，不具有交换性，比如A类是B类的友元，但是B类不是A类的友元。
//友元类关系不能传递，如果A是B的友元，B是C的友元，但是A不是B的友元。
//有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多用。

// 前置声明，都则A的友元函数声明编译器不认识B
class B;
class A
{
	// 友元声明
	friend void func(const A& aa, const B& bb);
private:
	int _a1 = 1;
	int _a2 = 2;
};
class B
{
	// 友元声明
	friend void func(const A& aa, const B& bb);
private:
	int _b1 = 3;
	int _b2 = 4;
};
void func(const A& aa, const B& bb)
{
	cout << aa._a1 << endl;
	cout << bb._b1 << endl;
} 
int main()
{
	A aa;
	B bb;
	func(aa, bb);
	return 0;
}