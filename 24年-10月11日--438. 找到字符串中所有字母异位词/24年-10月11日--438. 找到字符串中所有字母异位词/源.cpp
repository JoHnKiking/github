#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int Hash[128] = { 0 };
    vector<int> v;
    int left = 0, right = 0, ns = s.size(), np = p.size();
    int cur = 0, var = 0;
    while (right < ns)
    {
        if (++Hash[s[right++]] == 1 && ) ++var;
        ++cur;
        while (cur > np) {
            if (--Hash[s[left++] == 0]) --var;
            --cur;
        }
        if (var == np) v.push_back(left);
    }
    return v;
}
int main()
{
    string s{ "cbaebabacd" };
    string p{ "abd" };
    vector<int>ret = findAnagrams(s, p);
    
	return 0;
}