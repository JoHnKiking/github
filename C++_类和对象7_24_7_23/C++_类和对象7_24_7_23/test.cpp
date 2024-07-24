#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//5.内部类
//如果一个类定义在另一个类的内部，这个内部类就叫做内部类。内部类是一个独立的类，跟定义在全局相比，他只是受外部类类域限制和访问限定符限制，所以外部类定义的对象中不包含内部类。
//内部类默认是外部类的友元类。
//内部类本质也是一种封装，当A类跟B类紧密关联，A类实现出来主要就是给B类使用，那么可以考虑把A类设计为B的内部类，如果放到private / protected位置，那么A类就是B类的专属内部类，其他地方都用不了。
class A
{
private:
	static int _k;
	int _h = 1;
public:
	class B // B默认就是A的友元
	{
	public:
		void foo(const A& a)
		{
			cout << _k << endl; //OK
			cout << a._h << endl; //OK
		}
	private:
		int _b = 1;
	};
};
int A::_k = 1;
int main()
{
	cout << sizeof(A) << endl;
	A::B b;

	A aa;
	b.foo(aa);
	return 0;
}