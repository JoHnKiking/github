//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//  
//	//��������
//	//��������ĵ�һ��ԭ����ǣ����������������͵�����
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//����
//	Date(const Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	// d1 = d2
//	// ��ֵ���������
//	//�з���ֵ������д�ɵ�ǰ���������ã����÷��ؿ������Ч�ʣ��з���ֵĿ����Ϊ��֧��������ֵ������
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		//this->_year = d._year;
//		_month = d._month;
//		_day = d._day; 
//
//		//this�ǵ�ַ  
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////û����ʽʵ��ʱ�����������Զ�����һ��Ĭ�ϸ�ֵ��������أ�Ĭ�ϸ�ֵ�����������Ϊ��Ĭ�Ͽ������캯�����ƣ�
//// ���������ͳ�Ա���������ֵ���� / ǳ����(һ���ֽ�һ���ֽڵĿ���)�����Զ������ͳ�Ա������������Ŀ������졣
//
//int main()
//{
//	Date d1(2024, 7, 10);
//	Date d2(2024, 7, 12);
//	d1.Print();
//
//	//��ֵ���ؿ���
//	d1 = d2;
//
//	
//	//��������
//	//��һ��ͬ���͵�ȥ���죬���ֹ����Ϊ��������
//	Date d3(d1);
//	Date d4 = d1;
//	d3.Print();
//	d4.Print();
//
//
//
//	return 0;
//}


#include"Date.h"

int main()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;

	d1.Print();
	d2.Print();

	d1 += 100;
	d1.Print();

}