#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// ��̬����
// 1. ����ָ��������õ����麯��
// 2. �����õĺ����������麯����������ĺ���������� virtual
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊȫ��" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ���" << endl;
//	}
//};
//
//
//// �����Ǹ����β�
//void Func0(Person* ptr)
//{
//	// ֻ��ָ��ָ��Ķ����й�
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
//	// ֻ�м��� virtual ����ʹ��̬��������Ȼ����������������Ͳ�����������������������ڴ�й©
//	// �� �����̬�Ļ�������ʹ�������������ȱ����أ���������������������ٱ�����
//	// ���Ի�����鹹�����ͱ��붨����麯�����������ڴ�й©��������������Բ���Ҫ�� virtual��������
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
//	ptr->func();// ����ᶯ̬�󶨵�Derived::func()
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
	// ��д�����func1
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func1" << endl; }
	void func4() { cout << "Derive::func4" << endl; }
protected:
	int b = 2;
};

int main()
{
	// ͬ���Ͷ����麯����һ��
	Base b1;
	Base b2;
	cout << sizeof(b1) << endl;
	Derive d;
	cout << sizeof(d);
}

