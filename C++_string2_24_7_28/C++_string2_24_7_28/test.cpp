#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<string>
#include<map>
using namespace std;

// 大概底层逻辑
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


	// 下标 + 方括号[] 重载
	cout << "下标 + 方括号[] 重载 ->	";
	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;


	// 迭代器
	cout << "迭代器 ->		";// 像指针一样
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 链表迭代器
	cout << "链表迭代器 ->		";
	list<int> It = { 1,2,3,4,5,6,7 };
	list<int>::iterator lit = It.begin();
	while (lit != It.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;


	// 自动从 <s2> 中取 <每一个值（字符）> 给 <ch> 这个变量，<auto> 代表自动推导出类型
	// 自动赋值，自动迭代
	cout << "自动赋值，自动迭代 ->	";
	for (auto ch : s2)// 底层就是迭代器
	{
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;

	map<string, string> dict;

	// 两种情况都一样，上者可读性更强，下者更简便
	// 1. map<string, string>::iterator mit = dict.begin();
	// 2. auto mit = dict.begin();
	auto mit = dict.begin();


	// 反向迭代器
	cout << "反向迭代器 ->		";
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;


	// 常量迭代器
	cout << "常量迭代器 ->		";
	const string s3("hello world");
	string::const_iterator cit = s3.begin();
	while (cit != s3.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	// 常量反向迭代器
	cout << "常量反向迭代器 ->	";
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

// auto 不能做参数
//void func2(auto a)
//{}

// auto 可以做返回值
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
	// 类型包含"auto"的符号必须具有初始值设定项

	// typeid可以获取类型
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	// auto 不能定义数组
	// auto 不能做参数
	// auto 可以做返回值 

	// 范围for适用于容器和数组
	// C++11的遍历
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