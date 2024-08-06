#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 1);

	vector<int> v3(++v2.begin(), --v2.end());

	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v(10, 1);
	v.reserve(20);// 理解为扩容
	cout << v.size() << endl;
	cout << v.capacity() << endl; 

	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	// reserve在vector中不缩容，string会缩容


	v.resize(5,3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10, 2);// 扩容到10，新扩容的为2

}

void test_vector3()
{
	vector<int> v(10, 1);
	v.push_back(2);
	v.insert(v.begin()+3, 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
}

void test_vector4()
{
	vector<string> v1;
	string s1("xxxx");
	v1.push_back(s1);

	v1.push_back("yyyy");
	for (const auto& e : v1)// 调用的是拷贝构造，用引用减少消耗
	{
		cout << e << " ";
	}

	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);
}


int main()
{
	test_vector4();
	return 0;
}