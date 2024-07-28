#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;



int main()
{
	//string的定义
	string s1;
	string s2("1111112111");
	string s3(s2);


	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	//substring (3) 子字符串 （3）	
	//string(const string & str, size_t pos, size_t len = npos); 
	// npos == 42亿

	string s4(s2, 6, 2);
	cout << s4 << endl;

	string s5(s2, 6);
	cout << s5 << endl;

	string s6("hello world", 5);
	cout << s6 << endl;

	string s7(10, 'X');
	cout << s7 << endl;

	s6[0] = 'X';
	cout << s6 << endl;

	return 0;
}