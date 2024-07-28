#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<string>
#include<map>
using namespace std;

// ��ŵײ��߼�
//class string
//{
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};

void test_string1()
{
	string s1;
	string s2("hello world");

	cout << s1 << s2 << endl;

	s2[0] = 'x';
	cout << s1 << s2 << endl;


	// �±� + ������[] ����
	cout << "�±� + ������[] ���� ->	";
	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;


	// ������
	cout << "������ ->		";// ��ָ��һ��
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ���������
	cout << "��������� ->		";
	list<int> It = { 1,2,3,4,5,6,7 };
	list<int>::iterator lit = It.begin();
	while (lit != It.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;


	// �Զ��� <s2> ��ȡ <ÿһ��ֵ���ַ���> �� <ch> ���������<auto> �����Զ��Ƶ�������
	// �Զ���ֵ���Զ�����
	cout << "�Զ���ֵ���Զ����� ->	";
	for (auto ch : s2)// �ײ���ǵ�����
	{
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;

	map<string, string> dict;

	// ���������һ�������߿ɶ��Ը�ǿ�����߸����
	// 1. map<string, string>::iterator mit = dict.begin();
	// 2. auto mit = dict.begin();
	auto mit = dict.begin();


	// ���������
	cout << "��������� ->		";
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;


	// ����������
	cout << "���������� ->		";
	const string s3("hello world");
	string::const_iterator cit = s3.begin();
	while (cit != s3.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	// �������������
	cout << "������������� ->	";
	string::const_reverse_iterator rcit = s3.rbegin();
	while (rcit != s3.rend())
	{
		cout << *rcit << " ";
		++rcit;
	}
	cout << endl;


}

int func1()
{
	return 10;
}

// auto ����������
//void func2(auto a)
//{}

// auto ����������ֵ
auto func3()
{
	return 10;
}

void test2()
{
	int a = 10;
	auto b = 1l;
	auto c = 'a';
	auto d = func1();
	// ���Ͱ���"auto"�ķ��ű�����г�ʼֵ�趨��

	// typeid���Ի�ȡ����
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	// auto ���ܶ�������
	// auto ����������
	// auto ����������ֵ 

	// ��Χfor����������������
	// C++11�ı���
	int array[] = { 1,2,3,4,5,6,7,8 };
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " " << endl;

}

int main()
{
	test_string1();


	return 0;
}