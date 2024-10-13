#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

string minWindow(string s, string t) {
    string ret;
    int HashT[126] = { 0 };
    int HashS[126] = { 0 };
    int kinds = 0;
    for (auto ch : t)
        if (HashT[ch]++ == 0)
            kinds++;

    int nt = t.size(), ns = s.size();
    int start = -1, minlen = INT_MAX;
    for (int left = 0, right = 0, count = 0; right < ns; ++right) {
        char in = s[right];
        ++HashS[in];
        if (HashT[in] && HashS[in] == HashT[in])
            ++count;
        while (count == kinds) {
            if (right - left + 1 < minlen)
                minlen = right - left + 1, start = left;
            char out = s[left++];
            if (HashS[out]-- == HashT[out])
                --count;
        }
    }
    if (start == -1)
        return "";
    return s.substr(start, minlen);
}
int main()
{
    string s{ "ADOBECODEBANC" };
    string t("ABC");
    string ret = minWindow(s, t);
    cout << ret;
    return 0;
}