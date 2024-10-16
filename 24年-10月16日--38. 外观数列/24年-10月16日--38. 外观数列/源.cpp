#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>

using namespace std;

string countAndSay(int n) {
    if (n == 1) return { "1" };
    string cur{ "1" };
    while (n-- > 1) {
        string next;
        int left = 0, right = 0;
        while (++right < cur.size()) {
            if (cur[right] && cur[right] != cur[left]) {
                next += to_string(right - left) + cur[left];
                left = right;
            }
        }
        next += to_string(right - left) + cur[left];
        cur = next;
    }
    return cur;
}

int main()
{
    string s = countAndSay(4);
    cout <<  s << endl;

    int n = 41;
    string sn = to_string(n) + '0';
    cout << sn;
    return 0;
}