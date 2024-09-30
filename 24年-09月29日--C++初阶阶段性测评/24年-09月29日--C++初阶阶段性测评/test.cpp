#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<list>
#include<cstring>
#include<vector>

using namespace std;


//class A {
//public:
//	A(int a)
//		:_a1(a)
//		,_a2(_a1)
//	{
//		
//	}
//	void Print()
//	{
//		cout << _a1 << " " << _a2;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	int array[] = { 1,2,3,4,0,5,6,7,8,9 }; 
//	int n = sizeof(array) / sizeof(int); 
//	list<int> mylist(array, array + n);
//		auto it = mylist.begin(); 
//		while (it != mylist.end())
//		{
//			if (*it != 0)
//				cout << *it << " ";
//			else
//				it = mylist.erase(it);
//			++it;
//	}
//		A aa(1);
//		aa.Print();
//		return 0;
//}



//vector<vector<int> > generate(int numRows) {
//    // write code here
//    vector<vector<int>> ret(numRows, vector<int>(1, 1));
//
//    for (int i = 1; i < numRows; i++)
//    {
//        ret[i].resize(1 + 1, 1);
//        for (int j = 1; j < i; j++)
//        {
//            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
//        }
//    }
//    return ret;
//}
//int main()
//{
//    generate(3);
//
//    return 0;
//}


string multiply(string num1, string num2) {
    // write code here

    int s1 = num1.size();
    int s2 = num2.size();
    vector<int> res(s1 + s2, 0);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < s1; i++)
    {
        int flag = 0;
        for (int j = 0; j < s2; j++)
        {
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int sum = a * b + flag + res[i + j];
            flag = sum / 10;
            sum %= 10;
            res[i + j] = sum;
        }
        if (flag != 0)
            res[i + s2] = flag;
    }
    string ret;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        ret.push_back(res[i] + '0');
    }
    return ret;
}

int main()
{
    multiply("11", "999");
    return 0;
}