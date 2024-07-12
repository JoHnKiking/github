#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main2()
{
	int a = 0;
	// 引⽤：b和c是a的别名
	int& b = a;
	int& c = a;
	// 也可以给别名b取别名，d相当于还是a的别名
	int& d = b;
	++d;
	// 这⾥取地址我们看到是⼀样的
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl << endl;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	return 0;
}

#include<iostream>
using namespace std;
int main1()
{
	int a = 10;
	// 编译报错：“ra”: 必须初始化引⽤
	//int& ra;
	int& b = a;
	int c = 20;
	// 这⾥并⾮让b引⽤c，因为C++引⽤不能改变指向，
	// 这⾥是⼀个赋值
	b = c;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	return 0;
}

//int& rondents = rats;
//int* const pr = &rats;

//cubes.cppregular and reference arguments#include <iostream>
double cube(double a);
double refcube(const double& ra);
int main() {
	using namespace std;
	double x = 3.0;

	double side = 3.0; 
	double* pd = &side; 
	double& rd = side; 
	long edge = 5L; 
	double lens[4] = { 2.0, 5.0, 10.0, 12.0 };
	double c1 = refcube(side); 
	double c2 = refcube(lens[2]);
	double c3 = refcube(rd);
	double c4 = refcube(*pd);
	double c5 = refcube(edge); 
	double c6 = refcube(7.0); 
	double c7 = refcube(side + 10.0);

	cout << refcube(7.0);
	cout << " = refcube of " << x << endl; return 0;
}
double cube(double a)
{
	a *= a * a;
	return a;
}

double refcube(const double &ra)
{
	return ra * ra * ra;
}

double z = cube(x + 2.0); 
z = cube(8.0); 
int k = 10; 
z = cube(k); 
double yo[3] = (2.2, 3.3, 4.4, 5.5);
z = cube(yo[2])