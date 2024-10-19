#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<string>
#include<iostream>

using namespace std;

string addBinary(string a, string b) {
    string ret;
    int cur1 = a.size() - 1, cur2 = b.size() - 1, t = 0;
    while (cur1 >= 0 || cur2 >= 0 || t) {
        if (cur1 >= 0)
            t += a[cur1--] - '0';
        if (cur2 >= 0)
            t += a[cur2--] - '0';
        ret += t % 2 + '0';
        t /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){

    string a{ "1010" };
    string b{ "1011" };
    cout << addBinary(a, b);
    return 0;
}