#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;


vector<int> findSubstring(string s, vector<string>& words) {
    map<string, int> HashW;
    int len = words[0].size(); // words 中各个字符串的长度
    for (auto str : words) HashW[str]++;
    int m = words.size(); // words 中的元素数
    int n = s.size(); // s 的字符串长度
    vector<int> ret;
    for (int i = 0; i < len; ++i) {
        map<string, int> HashS;
        for (int left = i, right = i, count = 0; right < n; right += len) {
            string in = s.substr(right, len);
            if (++HashS[in] <= HashW[in]) ++count;
            if (right - left + 1 > len * m) {
                string out = s.substr(left, len);
                if (HashS[out]-- <= HashW[out]) --count;
                left += len;
            }
            if (count == m) ret.push_back(left);
        }
    }
    return ret;
}

int main()
{
    vector<string> words{ "word","good","best","good" };
    string s{ "wordgoodgoodgoodbestword" };
    vector<int> ret = findSubstring(s, words);
    for (auto e : ret) cout << e << " ";
    return 0;
}