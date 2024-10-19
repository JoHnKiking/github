#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include<iostream>

using namespace std;



string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int n = num1.size(), m = num2.size();
    vector<int> sum(m + n - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    string ret;
    int t = 0, i = 0;
    while (i < m + n  - 1|| t != 0) {
        if(i < m + n - 1) t += sum[i++];
        ret += t % 10 + '0';
        t /= 10;
    }

    while (ret.back() == '0' && ret.size() > 1)
        ret.pop_back();

    reverse(ret.begin(), ret.end());
    return ret;
}


int main()
{
    string num1{ "123" };
    string num2{ "456" };
    cout << multiply(num1, num2);
}