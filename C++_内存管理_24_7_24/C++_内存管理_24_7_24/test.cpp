#include<iostream>
using namespace std;
//
class A
{
public:
	//构造函数
	A(int a = 0)
		: _a1(a)
	{
		cout << "A(int a)" << endl;
	} 
	//拷贝构造函数
	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	} 
	//运算符重载
	A& operator=(const A& aa)
	{ 
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		} return *this;
	}
	//析构函数
	~A()
	{
		cout << "~A()" << endl;
	}

	void Print()
	{
		cout << _a1 << endl;
	}

	A& operator++()
	{
		_a1 += 100;
		return *this;
	}
private:
	int _a1 = 1;
};
//
//void f1(A aa)
//{}
//
//A f2()
//{
//	A aa(1);//存储在
//	++aa;
//	cout << "############" << endl;
//	return aa;//临时对象
//}
//
//int main1()
//{
//	A aa1 = 1;//构造加拷贝构造优化的结果
//	f1(aa1);//如果函数形参是引用的话，形参是实参的别名，不用额外创建，
//			    //但如果不是需要额外拷贝构造一份，并在函数结束时析构 
//	cout << endl;
//
//	f1(A(1));
//	cout << endl;
//
//	f1(1);
//	cout << endl;
//
//	const A& aa2 = 1;//构造
//
//	return 0;
//}
//
//int main()
//{
//	//优化
//	//A ret = f2();
//
//	A ret;
//	ret = f2();
//	ret.Print();
//	cout << "*********" << endl;
//	return 0;
//}










int main1()
{
	int* p1 = new int;
	int* p2 = new int[10];

	delete p1;
	delete[] p2;

	//申请对象+初始化
	int* p3 = new int[0];
	int* p4 = new int [10] {0};
	int* p5 = new int[10] {1, 2, 3, 4, 5};


	return 0;
}


struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x)
		:val(x)
		,next(nullptr)
	{}
};

int main()
{
	A* p1 = new A;
	A* p2 = new A(1);

	delete p1;
	delete p2;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(1);
	ListNode* n5 = new ListNode(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	return 0;
}