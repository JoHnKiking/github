#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
	// 去重 + 升序
	set<int> s = { 4,2,7,2,8,5,9 };
	// 去重 + 降序
	set<int, greater<int>> s2 = { 4,2,7,2,8,5,9 };
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除
	s.erase(4);
	// 查找
	s.find(4);
	// 已经有的值不会再插入
	s.insert(6);
	auto it = s.begin();
	while (it != s.end())
	{
		// *it = 1
		// it 不能给常量赋值
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 这是使用初始化列表的赋值初始化方式。它先创建一个无名的临时std::set<string>对象，使用初始化列表进行初始化，然后再将这个临时对象赋值给strset。
	set<string> strset1 = { "sort","insert","add" };

	// 这是直接在构造函数中使用初始化列表进行初始化的方式。它直接调用std::set<string>的构造函数，将初始化列表中的元素作为参数传入，构造出strset对象。
	set<string> strset2({ "sort","insert","add" });

	// 删除第二个元素
	strset1.erase(++strset1.begin());

	// 按 ASCLL 比较
	for (auto& e : strset1)// & 是引用
	{
		//e = "aaa"; // 不能直接修改迭代器所对应的值，会影响 set 内部的平衡二叉树
		cout << e << " ";
	}
	cout << endl;

	// std::set的swap函数用于交换两个std::set容器的内容。
	strset1.swap(strset2);
	for (auto& e : strset1)
	{
		cout << e << " ";
	}
	cout << endl;

	// std::set的count函数用于统计指定元素在集合中出现的次数。
	// 因为std::set中不允许重复元素，所以对于任何元素，count的返回值要么是 0（表示元素不在集合中），要么是 1（表示元素在集合中）。
	if (strset1.count("add")) cout << *++strset1.begin() << endl;
	// 因为std::set是 C++ 标准库容器，与 C 语言的printf结合使用不太自然
	// 对于 C++ 标准库容器，更推荐使用std::cout进行输出，这样更加安全和直观


	set<int> s11 = { 40,20,70,20,80,50,90 };

	// lower_bound(key)函数用于在std::set中查找第一个不小于给定键（key）的元素的位置。
	set<int>::iterator itlow = s11.lower_bound(30);
	// upper_bound(key)函数用于在std::set中查找第一个大于给定键（key）的元素的位置。
	set<int>::iterator itup = s11.lower_bound(60);

	set<int>::iterator e = s11.begin();
	while (itlow != itup)
	{
		cout << *itlow << " ";
		++itlow;
	}
	cout << endl;

	// multiset 允许冗余
	multiset<int> set1 = { 4,2,7,5,4,3,8,6,4,4,4,3,3,3 };
	for (auto& e : set1)
	{
		cout << e << " ";
	}
	cout << endl;


	// multiset 查找时，找到第一个出现的数时，继续在左子树上找，直到找不到，当前节点就是中序的第一个
	// 平均时间复杂的是 logN
	multiset<int>::iterator itset1 = set1.find(3);
	while (itset1 != set1.end())
	{
		cout << *itset1 << " ";
		++itset1;
	}
	cout << endl;

	map<string, string> dict;

	// 法一
	pair<string, string> kv1("sort", "排序");
	dict.insert(kv1);
	// 法二
	dict.insert(pair<string, string>("add", "添加"));
	// 法三
	dict.insert(make_pair("insert", "插入"));
	for (auto& e : dict)
	{
		cout << e.first << e.second << " ";
	}

	return 0;
}