#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;



void test_string5()
{
	string s("hello world");


	//	1.push_back	主要用于向字符串的末尾添加单个字符。
	//	2.append		则可以添加单个字符、字符数组、string 对象等多种形式的数据。
	s.push_back(' ');
	s.push_back('x');
	s.append("aaa");
	cout << s << endl;

	s += ' ';
	s += "3333333333";
	cout << s << endl;

	//	3.assign 函数用于为字符串对象赋予新的值。
	s.assign(5, 'A');
	cout << s << endl;

	s.assign("xxxxx");
	cout << s << endl;


	//	4.insert 函数用于在字符串中的指定位置插入指定的内容。
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

	//	头删
	s.erase(s.begin());
	cout << s << endl;

	//	尾删
	s.erase(--s.end());
	cout << s << endl;

	//	尾删
	s.erase(s.size() - 1, 1);
	cout << s << endl;
}

//	replace 函数的作用是替换字符串中的一部分内容。
void test_string7()
{
	string s("hello world");
	cout << s << endl;


	s.replace(6, 4, "%% ");
	cout << s << endl;


	string ss("hello              world");
	//	替换字符串中的空格为指定字符
	//	法一：
	//	效率并不高
	//	find 函数用于在字符串中查找指定的字符或子字符串
	size_t pos = ss.find(' ');
	//`string::npos 是一个静态常量成员，表示未找到匹配时的返回值
	while (pos != string::npos)
	{
		s.replace(pos, 1, "^^");
		pos = s.find(" ", pos + 2);//	替换完，相当于删掉了空格，再加入了^，所以pos还是对着^，所以要+1
	}
	cout << ss << endl;

	//	法二：
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
	cin >> file;//	输入文件名
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
	string s("test.cpp");  // 定义一个字符串 `s` 并初始化为 "test.cpp"
	size_t pos = s.rfind('.');  // 在字符串 `s` 中倒着查找 '.' 字符首次出现的位置，并将位置存储在 `pos` 中
	string suffix = s.substr(pos);  // substr 从 `pos` 位置开始提取字符串 `s` 的子串，并将其存储在 `suffix` 中
	cout << suffix << endl;  // 输出提取到的子串 `suffix` 并换行



	string str("dawdjkbabndkuawbdkuawbnkdaw");
	cout << str << endl;

	//	find_first_of 函数用于在字符串 str 中查找第一个出现在指定字符集合中的字符
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
			strcpy(_str, str);//	会把 \0 也拷贝过去
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