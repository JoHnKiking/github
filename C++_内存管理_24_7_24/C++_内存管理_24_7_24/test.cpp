#include<iostream>
using namespace std;
//
class A
{
public:
	//���캯��
	A(int a = 0)
		: _a1(a)
	{
		cout << "A(int a)" << endl;
	} 
	//�������캯��
	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	} 
	//���������
	A& operator=(const A& aa)
	{ 
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		} return *this;
	}
	//��������
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
//	A aa(1);//�洢��
//	++aa;
//	cout << "############" << endl;
//	return aa;//��ʱ����
//}
//
//int main1()
//{
//	A aa1 = 1;//����ӿ��������Ż��Ľ��
//	f1(aa1);//��������β������õĻ����β���ʵ�εı��������ö��ⴴ����
//			    //�����������Ҫ���⿽������һ�ݣ����ں�������ʱ���� 
//	cout << endl;
//
//	f1(A(1));
//	cout << endl;
//
//	f1(1);
//	cout << endl;
//
//	const A& aa2 = 1;//����
//
//	return 0;
//}
//
//int main()
//{
//	//�Ż�
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

	//�������+��ʼ��
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