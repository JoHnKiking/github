#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void func()
{
	int n = 1;
	while (1)
	{
		void* p = new char[1024 * 1024];
		cout << p << "->" << n << "MB" << endl;
		n++;
	}
}

int main1()
{
	try
	{
		func();
	} 
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

int main()
{

}