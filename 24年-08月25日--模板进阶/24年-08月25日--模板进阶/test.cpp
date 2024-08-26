#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<array>
#include<vector>


using namespace std;

//namespace bite
//{
//	// ����һ��ģ�����͵ľ�̬����
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index)
//		{
//			return _array[index];
//		}
//		const T& operator[](size_t index)const
//		{
//			return _array[index];
//		}
//		size_t size()const
//		{
//			return _size;
//		}
//		bool empty()const
//		{
//			return 0 == _size;
//		}
//
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
//
//int main()
//{
//	// 1��
//	// array������ջ��
//	// ջ ���ռ� ��� �� Ч�ʸ���
//	array<int, 10> a1;
//	array<int, 100> a2;
//
//	// arrayԽ���д�����Լ��
//	//a1[10];
//	//a2[12] = 10;
//
//
//	// 2��
//	// ��̬����
//	// Խ��������
//	int a3[10];
//	cout << a3[1] << endl; 
//
//	// Խ��д���
//	//a3[12] = 10;
//	//cout << a3[12] << endl;
//
//
//	// 3��
//	// ��
//	vector<int> v(100, 1);
//	cout << sizeof(a1) << endl;
//	cout << sizeof(v) << endl;
//
//	return 0;
//}


// ������
class Date
{
	// ��Ԫ����
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	// �б�
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

// ����ģ�� -- ����ƥ��
template<class T>
bool Less(const T& left, const T& right)
{
	return left < right;
}

// �ػ�
// 1�����Ƽ�
// ���ײ�ƥ��
template<>
bool Less<const Date*>(const Date* const& left, const Date* const& right)
{
	return *left < *right;
}
// 2���Ƽ�
// ע�⣺һ��������������ģ���������ܴ�����ߴ�����������ͣ�Ϊ��ʵ�ּ�ͨ�����ǽ��ú���ֱ�Ӹ���
bool Less(Date* left, Date* right)
{
	return *left < *right;
}

//int main()
//{
//	cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
//	
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ
//	
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	// ��ʱ������ָ��Ƚ�
//	cout << Less(p1, p2) << endl; // ���ԱȽϣ��������
//
//	const Date* p3 = &d1;
//	const Date* p4 = &d2;
//	cout << Less(p3, p4) << endl; // ���ԱȽϣ��������
//
//	// const �� ���� ��λ�ÿ��Ե��ã���Ӱ��
//	const int i = 0;
//	int const j = 0;
//
//	// ����Ҳһ��
//	const int& r = i;
//	int const& ry = i;
//	
//	return 0;
//}


template<class T1, class T2>
class Data
{
	public :
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// ȫ�ػ�
template<>
class Data<int, char>
{
	public :
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

// ƫ�ػ�/���ػ� 
template<class T1>
class Data<T1, double>
{
	public :
	Data() { cout << "Data<T1, double>" << endl; }
private:
	T1 _d1;
	double _d2;
};

template<typename T1, typename T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>" << endl;
		T1 x;
		cout << typeid(x).name() << endl;
	}
};

template<typename T1, typename T2>
class Data<T1&, T2&>
{
public:
	Data()
	 {
		cout << "Data<T1&, T2&>" << endl;
	}
};

void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<int, double> d3;
	Data<int&, char&> d4;
	Data<int*, char*> d5;
}

int main()
{
	TestVector(); 
	return 0;
}