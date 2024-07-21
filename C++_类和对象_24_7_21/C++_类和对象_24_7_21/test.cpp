#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class A
{
	public :
	A(int a)
		: _a1(a)
		, _a2(_a1)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2 = 2;
	int _a1 = 2;
};

int main()
{
	A aa(1);
	aa.Print();
}