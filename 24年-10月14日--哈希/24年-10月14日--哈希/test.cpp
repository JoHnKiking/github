
#include"HashTable.h"


void test_set1()
{
	unordered_set<int> s = { 3,1,6,7,8,2,1,1,5,6,7,6 };
	unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void test_set2()
{
	const size_t N = 1000000;
	unordered_set<int> us;
	set<int> s;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand()); // N�Ƚϴ�ʱ���ظ�ֵ�Ƚ϶�
		v.push_back(rand() + i); // �ظ�ֵ�����
		//v.push_back(i); // û���ظ�������
	}

	// 21:15
	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert:" << end1 - begin1 << endl;

	size_t begin2 = clock();
	us.reserve(N);
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert:" << end2 - begin2 << endl;

	cout << "�������ݸ�����" << s.size() << endl;
	cout << "�������ݸ�����" << us.size() << endl << endl;

	int m1 = 0;
	size_t begin3 = clock();
	for (auto e : v)
	{
		auto ret = s.find(e);
		if (ret != s.end())
		{
			++m1;
		}
	}
	size_t end3 = clock();
	cout << "set find:" << end3 - begin3  << "s ->" << m1 << endl;

	int m2 = 0;
	size_t begin4 = clock();
	for (auto e : v)
	{
		auto ret = us.find(e);
		if (ret != us.end())
		{
			++m2;
		}
	}
	size_t end4 = clock();
	cout << "unorered_set find:" << end4 - begin4 << "s ->" << m2 << endl << endl;

	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();
	cout << "set erase:" << end5 - begin5 << endl;
	size_t begin6 = clock();

	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();
	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
}



int main()
{
	//int a[] = { 19,30,52,63,11,22 };
	int a[] = { 19,30,5,36,13,20,21,12 };
	//test_set2();
	HashTable<int, int> ht;
	for (auto e : a) {
		ht.Insert({ e,e });
	}
	ht.Insert({ 9,9 });

	int x = 21;
	if (ht.Find(x)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;

	if (!ht.Erase(x)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;

	return 0;
}