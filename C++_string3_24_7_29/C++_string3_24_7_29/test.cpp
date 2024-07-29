#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;



void test_string5()
{
	string s("hello world");


	//	1.push_back	��Ҫ�������ַ�����ĩβ��ӵ����ַ���
	//	2.append		�������ӵ����ַ����ַ����顢string ����ȶ�����ʽ�����ݡ�
	s.push_back(' ');
	s.push_back('x');
	s.append("aaa");
	cout << s << endl;

	s += ' ';
	s += "3333333333";
	cout << s << endl;

	//	3.assign ��������Ϊ�ַ����������µ�ֵ��
	s.assign(5, 'A');
	cout << s << endl;

	s.assign("xxxxx");
	cout << s << endl;


	//	4.insert �����������ַ����е�ָ��λ�ò���ָ�������ݡ�
	s.insert(2, " World ");
	cout << s << endl;

	s.insert(0, 1, 'p');
	cout << s << endl;

}

void test_string6()
{
	string s("hello world");

	s.erase(0, 1);
	cout << s << endl;

	//	ͷɾ
	s.erase(s.begin());
	cout << s << endl;

	//	βɾ
	s.erase(--s.end());
	cout << s << endl;

	//	βɾ
	s.erase(s.size() - 1, 1);
	cout << s << endl;
}

//	replace �������������滻�ַ����е�һ�������ݡ�
void test_string7()
{
	string s("hello world");
	cout << s << endl;


	s.replace(6, 4, "%% ");
	cout << s << endl;


	string ss("hello              world");
	//	�滻�ַ����еĿո�Ϊָ���ַ�
	//	��һ��
	//	Ч�ʲ�����
	//	find �����������ַ����в���ָ�����ַ������ַ���
	size_t pos = ss.find(' ');
	//`string::npos ��һ����̬������Ա����ʾδ�ҵ�ƥ��ʱ�ķ���ֵ
	while (pos != string::npos)
	{
		s.replace(pos, 1, "^^");
		pos = s.find(" ", pos + 2);//	�滻�꣬�൱��ɾ���˿ո��ټ�����^������pos���Ƕ���^������Ҫ+1
	}
	cout << ss << endl;

	//	������
	string tmp;
	for (auto ch : ss)
	{
		if (ch == ' ')
			tmp += "^^";		
		else
			tmp += ch;
		//cout << tmp << endl;
	}
	cout << tmp << endl;
	//ss = tmp;
	ss.swap(tmp);
	cout << ss << endl;


	string file;
	cin >> file;//	�����ļ���
	FILE* fout = fopen(file.c_str(), "r");
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}
}


void test_string8()
{
	string s("test.cpp");  // ����һ���ַ��� `s` ����ʼ��Ϊ "test.cpp"
	size_t pos = s.rfind('.');  // ���ַ��� `s` �е��Ų��� '.' �ַ��״γ��ֵ�λ�ã�����λ�ô洢�� `pos` ��
	string suffix = s.substr(pos);  // substr �� `pos` λ�ÿ�ʼ��ȡ�ַ��� `s` ���Ӵ���������洢�� `suffix` ��
	cout << suffix << endl;  // �����ȡ�����Ӵ� `suffix` ������



	string str("dawdjkbabndkuawbdkuawbnkdaw");
	cout << str << endl;

	//	find_first_of �����������ַ��� str �в��ҵ�һ��������ָ���ַ������е��ַ�
	size_t found = str.find_first_of("abcd");
	while (found != string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("abcd", found + 1);
	}
	cout << str << endl;

}


namespace bit 
{
	class string
	{
	public:
		string()
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{}

		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);//	��� \0 Ҳ������ȥ
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
int main()
{
	//test_string8();
	return 0;
}