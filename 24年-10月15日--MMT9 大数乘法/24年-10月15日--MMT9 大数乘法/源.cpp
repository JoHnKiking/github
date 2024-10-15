#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    vector<int> nums(n1 + n2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            nums[i + j] += (s1[i] - '0') * (s2[j] - '0');
        }
    }
    string ret;
    int c = 0;
    for (auto x : nums) {
        c += x;
        ret += c % 10 + '0';
        c /= 10;
    }
    while (c != 0) {
        ret += c % 10 + '0';
        c /= 10;
    }

    while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
    reverse(ret.begin(), ret.end());
    cout << ret;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")