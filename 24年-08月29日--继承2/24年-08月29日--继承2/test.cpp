#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//// 1. Final class cann't be inherited
////class Base final
//class Base
//{
//public:
//	void func5()
//	{
//		cout << "Base::func5" << endl;
//	}
//
//protected:
//	int a = 1;
//
//private:
//	// C++98的⽅法
//	// If parent class was be defined in privated area, subclass cann't call and it will generate error.
//	//Base()
//	//{};
//};
//
//class Derive : public Base
//{
//public: 
//	void func4()
//	{
//		cout << "Base::func4" << endl;
//	}
//
//private:
//	int b = 1;
//};
//
//int main()
//{
//	Derive d;
//
//	return 0;
//}



//// 2. Inheritance and Friend declaration
//class Student;
//class Person
//{
//public :
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	// Friend declarration
//	friend void Display(const Person& p, const Student& s);
//protected :
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//} 
//int main()
//{
//	Person p;
//	Student s;
//	// 编译报错：error C2248: “Student::_stuNum”: ⽆法访问 protected 成员
//	// 解决⽅案：Display也变成Student 的友元即可
//	Display(p, s);
//	return 0;
//}





//// 3. Inheritance and Static member
//class Person
//{
//public:
//	string _name;
//	static int _count;
//};
//
//int Person::_count = 10;
//
//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	// 这⾥的运⾏结果可以看到⾮静态成员_name的地址是不⼀样的
//	// 说明⼦类继承下来了，⽗⼦类对象各有⼀份
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//	// 这⾥的运⾏结果可以看到静态成员_count的地址是⼀样的
//	// 说明⼦类和⽗类共⽤同⼀份静态成员
//	cout << &p._count << endl;
//	cout << &s._count << endl;
//	// 公有的情况下，⽗⼦类指定类域都可以访问静态成员
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	return 0;
//}


//// 4. Multiple inheritance and diamond inheritance.
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // 职⼯编号
//};
//
//// Try not to use diamond inheritance.
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 编译报错：error C2385: 对“_name”的访问不明确
//	Assistant a;
//	//a._name = "peter";
//
//	// 需要显⽰指定访问哪个⽗类的成员可以解决⼆义性问题，但是数据冗余问题⽆法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}





//// 5. 继承通过在继承方式前加上 “virtual” 关键字来实现。使用虚继承后，派生类中只会保留一份共同基类的实例
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//// 使⽤虚继承Person类
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//// 使⽤虚继承Person类
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职⼯编号
//};
//
//// 教授助理
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 使⽤虚继承，可以解决数据冗余和⼆义性
//	Assistant a;
//	a._name = "peter";
//	return 0;
//}



//class A
//{
//public:
//
//	void f() { cout << "A::f()" << endl; }
//	int a;
//};
//
//
//
//class B : public A
//{
//public:
//	void f(int a) { cout << "B::f()" << endl; }
//	int a;
//};
//
//
//
//int main()
//{
//	B b;
//	b.f();
//	return 0;
//}


//class A
//{
//public:
//	A() { cout << "A::A()" << endl; }
//	~A() { cout << "A::~A()" << endl; }
//	int a;
//};
//
//
//
//class B : public A
//{
//public:
//	B() { cout << "B::B()" << endl; }
//	~B() { cout << "B::~B()" << endl; }
//	int b;
//};
//
//
//
//void f()
//{
//	B b;
//}
//
//int main()
//{
//	f();
//	return 0;
//}





//template<typename Type>
//Type Max(const Type& a, const Type& b)
//{
//	cout << "This is Max<Type>" << endl;
//	return a > b ? a : b;
//}
//
//template<>
//int Max<int>(const int& a, const int& b)
//{
//	cout << "This is Max<int>" << endl;
//	return a > b ? a : b;
//}
//
//template<>
//char Max<char>(const char& a, const char& b)
//{
//	cout << "This is Max<char>" << endl;
//	return a > b ? a : b;
//}
//
//int Max(const int& a, const int& b)
//{
//	cout << "This is Max" << endl;
//	return a > b ? a : b;
//}
//
//int main()
//{
//	Max(10, 20);
//	Max(12.34, 23.45);
//	Max('A', 'B');
//	Max<int>(20, 30);
//	return 0;
//}



template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()

{
	Data<double, int> d1;
	Data<int, double> d2;
	Data<int*, int*> d3;
	Data<int&, int&> d4(1, 2);
	return 0;
}