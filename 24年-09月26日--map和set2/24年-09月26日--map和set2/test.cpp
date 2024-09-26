#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
	// ȥ�� + ����
	set<int> s = { 4,2,7,2,8,5,9 };
	// ȥ�� + ����
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

	// ɾ��
	s.erase(4);
	// ����
	s.find(4);
	// �Ѿ��е�ֵ�����ٲ���
	s.insert(6);
	auto it = s.begin();
	while (it != s.end())
	{
		// *it = 1
		// it ���ܸ�������ֵ
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ����ʹ�ó�ʼ���б�ĸ�ֵ��ʼ����ʽ�����ȴ���һ����������ʱstd::set<string>����ʹ�ó�ʼ���б���г�ʼ����Ȼ���ٽ������ʱ����ֵ��strset��
	set<string> strset1 = { "sort","insert","add" };

	// ����ֱ���ڹ��캯����ʹ�ó�ʼ���б���г�ʼ���ķ�ʽ����ֱ�ӵ���std::set<string>�Ĺ��캯��������ʼ���б��е�Ԫ����Ϊ�������룬�����strset����
	set<string> strset2({ "sort","insert","add" });

	// ɾ���ڶ���Ԫ��
	strset1.erase(++strset1.begin());

	// �� ASCLL �Ƚ�
	for (auto& e : strset1)// & ������
	{
		//e = "aaa"; // ����ֱ���޸ĵ���������Ӧ��ֵ����Ӱ�� set �ڲ���ƽ�������
		cout << e << " ";
	}
	cout << endl;

	// std::set��swap�������ڽ�������std::set���������ݡ�
	strset1.swap(strset2);
	for (auto& e : strset1)
	{
		cout << e << " ";
	}
	cout << endl;

	// std::set��count��������ͳ��ָ��Ԫ���ڼ����г��ֵĴ�����
	// ��Ϊstd::set�в������ظ�Ԫ�أ����Զ����κ�Ԫ�أ�count�ķ���ֵҪô�� 0����ʾԪ�ز��ڼ����У���Ҫô�� 1����ʾԪ���ڼ����У���
	if (strset1.count("add")) cout << *++strset1.begin() << endl;
	// ��Ϊstd::set�� C++ ��׼���������� C ���Ե�printf���ʹ�ò�̫��Ȼ
	// ���� C++ ��׼�����������Ƽ�ʹ��std::cout����������������Ӱ�ȫ��ֱ��


	set<int> s11 = { 40,20,70,20,80,50,90 };

	// lower_bound(key)����������std::set�в��ҵ�һ����С�ڸ�������key����Ԫ�ص�λ�á�
	set<int>::iterator itlow = s11.lower_bound(30);
	// upper_bound(key)����������std::set�в��ҵ�һ�����ڸ�������key����Ԫ�ص�λ�á�
	set<int>::iterator itup = s11.lower_bound(60);

	set<int>::iterator e = s11.begin();
	while (itlow != itup)
	{
		cout << *itlow << " ";
		++itlow;
	}
	cout << endl;

	// multiset ��������
	multiset<int> set1 = { 4,2,7,5,4,3,8,6,4,4,4,3,3,3 };
	for (auto& e : set1)
	{
		cout << e << " ";
	}
	cout << endl;


	// multiset ����ʱ���ҵ���һ�����ֵ���ʱ�����������������ң�ֱ���Ҳ�������ǰ�ڵ��������ĵ�һ��
	// ƽ��ʱ�临�ӵ��� logN
	multiset<int>::iterator itset1 = set1.find(3);
	while (itset1 != set1.end())
	{
		cout << *itset1 << " ";
		++itset1;
	}
	cout << endl;

	map<string, string> dict;

	// ��һ
	pair<string, string> kv1("sort", "����");
	dict.insert(kv1);
	// ����
	dict.insert(pair<string, string>("add", "���"));
	// ����
	dict.insert(make_pair("insert", "����"));
	for (auto& e : dict)
	{
		cout << e.first << e.second << " ";
	}

	return 0;
}