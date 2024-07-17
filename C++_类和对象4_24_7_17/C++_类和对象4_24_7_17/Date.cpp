#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//拷贝构造
//拷贝构造的第一个原则就是，必须是自身类类型的引用
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//返回引用
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	return tmp;
}

void Date::operator-(int day)
{

 }