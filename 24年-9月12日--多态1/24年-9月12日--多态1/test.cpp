#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// 多态条件
// 1. 必须指针或者引用调用虚函数
// 2. 被调用的函数必须是虚函数。派生类的函数不必须加 virtual
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票半价" << endl;
//	}
//};
//
//
//// 必须是父类形参
//void Func0(Person* ptr)
//{
//	// 只跟指针指向的对象有关
//	ptr->BuyTicket();
//}
//void Func1(Person& ptr)
//{
//	ptr.BuyTicket();
//}
//
//int main1()
//{
//	Person p1;
//	Student s1;
//	Func0(&p1);
//	Func0(&s1);
//	Func1(p1);
//	Func1(s1);
//
//	return 0;
//}
//
//
//class A
//{
//public:
//	// 只有加上 virtual 才能使多态成立，不然派生类的析构函数就不会调用派生类的析构，造成内存泄漏
//	// 即 满足多态的环境后，能使基类析构函数先被隐藏，等派生类析构函数完后再被调用
//	// 所以基类的虚构函数就必须定义成虚函数，否则有内存泄漏，但是派生类可以不需要加 virtual，否则有
//	virtual ~A()
//	//~A()
//	{
//		cout << "~A() -> delete:" << _p << endl;
//	}
//private:
//	int* _p = new int[10];
//};
//
//class B : public A
//{
//public:
//	~B()
//	{
//		cout << "~B() -> delete:" << _q << endl;
//	}
//private:
//	int* _q = new int[10];
//};
//
//
//int main2()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}
//
//class Base {
//public:
//	virtual void func() {
//		std::cout << "Base::func()" << std::endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	void func()  {
//		std::cout << "Derived::func()" << std::endl;
//	}
//};
//
//int main3() {
//	Base* ptr = new Derived();
//	ptr->func();// 这里会动态绑定到Derived::func()
//	delete ptr;
//	return 0;
//}


class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
	void func5() { cout << "Base::func5" << endl; }
protected:
	int a = 1;
};
class Derive : public Base
{
public:
	// 重写基类的func1
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func1" << endl; }
	void func4() { cout << "Derive::func4" << endl; }
protected:
	int b = 2;
};

int main()
{
	// 同类型对象，虚函数表一样
	Base b1;
	Base b2;
	cout << sizeof(b1) << endl;
	Derive d;
	cout << sizeof(d);
}

