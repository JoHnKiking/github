#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;


//class Person
//{
//	public :
//	// 进⼊校园/图书馆/实验室刷⼆维码等⾝份认证
//	void identity()
//	{
//		cout << "void identity()" << _name << endl;
//	}
//protected:
//	string _name = "张三"; // 姓名
//	string _address; // 地址
//	string _tel; // 电话
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	// 学习
//	void study()
//	{
//		// ...
//	}
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//public:
//	// 授课
//	void teaching()
//	{
//		//...
//	}
//protected:
//	string title; // 职称
//};
//
//int main()  
//{
//
//	return 0;
//}


//#define CONTAINER std::vector
//#define CONTAINER std::list
//#define CONTAINER std::deque


//namespace bit
//{
//	//template<class T>
//	//class vector
//	//{};
//
//	// stack和vector的关系，既符合is-a，也符合has-a
//	template<class T>
//	class stack : public CONTAINER<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// ⽗类是类模板时，需要指定⼀下类域，
//			// 否则编译报错:error C3861: “push_back”: 找不到标识符
//			// 因为stack<int>实例化时，也实例化vector<int>了
//			// 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
//			CONTAINER<T>::push_back(x);
//			//push_back(x);
//		}
//
//		void pop()
//		{
//			CONTAINER<T>::pop_back();
//		}
//
//		const T& top()
//		{
//			return CONTAINER<T>::back();
//		}
//
//		bool empty()
//		{
//			return CONTAINER<T>::empty();
//		}
//
//		// 13 - will not check template-dependent
//		// 19 - will check
//	};
//}
//
//
//int main()
//{
//	bit::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	return 0;
//}




//class Person
//{
////protected:
//	virtual void func()
//	{}
//public:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Student sobj;
//
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	rp._name = "张三";
//
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	// 2.父类对象不能赋值给子类对象，这里会编译报错
//	// 强转也不行
//	// sobj = (Student)pobj;
//
//	// 后面再细讲，这里简单了解一下
//	Student* ps1 = dynamic_cast<Student*>(pp);
//	cout << ps1 << endl;
//
//	// 父类不能转回子类
//	pp = &pobj;
//	Student* ps2 = dynamic_cast<Student*>(pp);
//	cout << ps2 << endl;
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _num << endl;
//		// 在⼦类成员函数中，可以使⽤ ⽗类::⽗类成员 显⽰访问
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//// 函数重载作用在一个作用域里
//int main()
//{
//
//	Student s;
//	s.Print();
//
//	return 0;
//}


class Person
{
public:
	// default constructor function
	Person(const char* name = "Peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	// copy constructor function
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	// function overloading
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}

	// destruct function
	~Person()
	{
		cout << "~Person()" << endl;
	}

protected:
	string _name; // 姓名
};


class Student : public Person
{
public:
	// Default generates constructor behavior
	// 1. bulit-in type
	// 2. custom type
	// 3. perceive the members inherited form parent class as single entity


	//⼦类的构造函数必须调⽤⽗类的构造函数初始化⽗类的那⼀部分成员。如果⽗类没有默认的构造函数，则必须在⼦类构造函数的初始化列表阶段显⽰调⽤
	Student(const char* name, int num, const char* address)
		:Person(name)
		,_num(num)
		,_address(address)
	{}

	// Strictly speaking, the Student's copy constructor function is enough.
	// If there're resource that required deep copy, we need to implement it ourselves.

	// Initialize list is related to statement, isn't related to squence
	Student(const Student& s)
		:Person(s)
		,_num(s._num)
		,_address(s._address)
	{
		// deep copy
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			operator=(s);
			_num = s._num;
			_address = s._address;
		}
		return *this;
	}

	
protected:
	int _num; // 学号
	string _address; // 地址
	//int* _ptr = new int[10];// 数组
};


int main()
{
	Student s("张三", 18, "1111");
	Student s2(s);

	return 0;
}