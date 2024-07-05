#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter you favorite dessert:\n";
	cin >> dessert;
	cout << name << endl;
	cout << dessert << endl;
}