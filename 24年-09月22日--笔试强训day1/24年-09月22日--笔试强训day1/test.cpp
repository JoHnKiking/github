#define _CRT_SECURE_NO_WARNINGS 1


// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm> // sort
#include<List>

using namespace std;

typedef long long  ll;
const int MAX = 100001;

//int main1() 
//{
//	int l, r;
//	long long num = 0;
//	cin >> l >> r;
//	int tmp;
//	for (int i = l; i <= r; i++)
//	{
//		tmp = i;
//		while (tmp > 0)
//		{
//			if (tmp % 10 == 2)
//				++num;
//			tmp /= 10;
//		}
//	}
//	cout << num;
//
//	return 0;
//}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // write code here
    vector<int> ret;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] > nums2[j])
            ++j;
        else if (nums1[i] < nums2[j])
            ++i;
        else
        {
            if (ret.empty() || nums1[i] != ret.back())
            {
                ret.push_back(nums1[i]);
            }
           
            ++i;
            ++j;
        }
    }
    return ret;
}

int main()
{
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 2,2,2,2 };
    vector<int> ret = intersection(nums1, nums2);


    return 0;
}

//int main3_1()
//{
//    char* str1 = new char[300003]();
//    char* str2 = new char[300003]();
//    cin >> str1;
//    int len = strlen(str1);
//    
//
//    
//
//    int flag = 1;
//    int str = 1;
//    while (flag && len != 0)
//    {
//        flag = 0;
//        int i = 0;
//        int len_tmp = len;
//        int tmp = 0;
//        while (i < len_tmp)
//        {
// 
//            if (str == 1)
//            {
//                if (str1[i] == str1[i + 1])
//                {
//                    len -= 2;
//                    flag = 1;
//                    ++i;
//                }
//                else
//                {
//                    str2[tmp] = str1[i];
//                    ++tmp;
//                }
//            }
//            else
//            {
//                if (str2[i] == str2[i + 1] + 1 || str2[i] == str2[i + 1] - 1 || str2[i] == str2[i + 1])
//                {
//                    len -= 2;
//                    flag = 1;
//                }
//                else
//                {
//                    str1[tmp] = str2[i];
//                    ++tmp;
//                }
//            }
//            ++i;
//        }
//        ~str;
//    }
//
//    if (strlen(str1) == len) {
//        cout << str1;
//    }
//    else {
//        cout << str2;
//    }
//    
//    delete[] str1;
//    delete[] str2;
//
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<stack>
//using namespace std;

//string sweep_away(string s)
//{
//    stack<char> st;
//    for (auto e : s)
//    {
//        if (!st.empty() && st.top() == e)
//        {
//            st.pop();
//        }
//        else
//        {
//            st.push(e);
//        }
//    }
//    if (st.empty())
//    {
//        return "0";
//    }
//    string ret;
//    while (!st.empty())
//    {
//        ret = st.top() + ret;
//        st.pop();
//    }
//    return ret;
//}
//
//bool is_sweep_away(string s)
//{
//    for (int i = 0; i < s.size() - 2; i++)
//    {
//        if (s[i] == s[i+1])
//            return true;
//    }
//    return false;
//}
//
//int main3()
//{
//
//    string s;
//    cin >> s;
//       
//    while (is_sweep_away(s) && s.size() > 1)
//    {
//        s = sweep_away(s);
//    }
//   
//    cout << s << endl;
//    
//    return 0;
//}