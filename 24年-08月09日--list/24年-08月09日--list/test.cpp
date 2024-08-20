#include"list.h"

//void test_list1()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	l1.push_back(4);
//	l1.push_back(4);
//	l1.push_back(4);
//	l1.push_back(1);
//	l1.push_back(1);
//	l1.push_back(3);
//
//
//
//	list<int>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	// 升序
//	
//	int x = 0;
//	cin >> x;
//	it = find(l1.begin(), l1.end(), x);
//	if (it != l1.end())
//	{
//		l1.splice(l1.begin(), l1, it);
//	}
//
//	for (auto e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string s("ddawlidjaikwldja");
//	cout << s << endl;
//	sort(s.begin() + 2, s.end());
//	cout << s << endl;
//}
//
//void test_list2()
//{
//	list<int> l1;
//	l1.push_back(1);
//	l1.emplace_back(2);
//	l1.emplace_back(3);
//	l1.emplace_back(4);
//	l1.emplace_back(5);
//	l1.emplace_back(6);
//	for (auto e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//struct A
//{
//public:
//	A(int a1 = 1, int a2 = 1)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	int a1()
//	{
//		return _a1;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//void 	test_list3()
//{
//	list<A> l1;
//	A aa1(1, 1);
//	l1.push_back(aa1);
//	l1.push_back(A(2, 2));
//	l1.push_back(A(2, 2));
//	l1.push_back(A(2, 2));
//	l1.push_back(A(2, 2));
//
//	// emplace_back 直接在列表的末尾就地构造对象，通过传递对象的构造参数。
//	l1.emplace_back(3, 3);
//	l1.emplace_back(3, 3);
//	l1.emplace_back(3, 3);
//
//	l1.emplace_front(4, 4);
//	l1.emplace_front(4, 4);
//	l1.emplace_front(4, 4);
//	l1.emplace_front(4, 4);
//	
//
//
//	list<A>::iterator it = l1.begin();
//	while (it != l1.end())
//	{
//		cout << (*it).a1() << " ";
//		it++;
//	}
//	cout << endl;
//}


int main()
{
	bit::test_list1();

	return 0;
}