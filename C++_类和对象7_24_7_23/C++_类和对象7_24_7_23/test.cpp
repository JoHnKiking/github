#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//5.�ڲ���
//���һ���ඨ������һ������ڲ�������ڲ���ͽ����ڲ��ࡣ�ڲ�����һ���������࣬��������ȫ����ȣ���ֻ�����ⲿ���������ƺͷ����޶������ƣ������ⲿ�ඨ��Ķ����в������ڲ��ࡣ
//�ڲ���Ĭ�����ⲿ�����Ԫ�ࡣ
//�ڲ��౾��Ҳ��һ�ַ�װ����A���B����ܹ�����A��ʵ�ֳ�����Ҫ���Ǹ�B��ʹ�ã���ô���Կ��ǰ�A�����ΪB���ڲ��࣬����ŵ�private / protectedλ�ã���ôA�����B���ר���ڲ��࣬�����ط����ò��ˡ�
class A
{
private:
	static int _k;
	int _h = 1;
public:
	class B // BĬ�Ͼ���A����Ԫ
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