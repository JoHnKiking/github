#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

class Date
{
public:
	//ȫȱʡ���캯��
	Date(int year = 1900, int month = 1, int day = 1);

	//��������
	Date(const Date& d);

	// Ĭ����inline�����ý���ջ֡��Ҳ�����������������
	int GetMonthDay(int year, int month)
	{
		static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);
	void operator-(int day);

	void Print();

private:
	int _year;
	int _month;
	int _day;
};