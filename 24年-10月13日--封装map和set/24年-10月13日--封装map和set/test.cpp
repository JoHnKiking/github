#define _CRT_SECURE_NO_WARNINGS 1

#include"Mymap.h"
#include"Myset.h"

int main()
{
	my::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	my::set<int>::iterator sit = s.begin();
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//Print(s);


	my::map<string, string> dict;
	dict.insert({ "sort", "����" });
	dict.insert({ "left", "���" });
	dict.insert({ "right", "�ұ�" });

	/*dict["left"] = "��ߣ�ʣ��";
	dict["insert"] = "����";
	dict["string"];*/

	my::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// �����޸�first�������޸�second
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}