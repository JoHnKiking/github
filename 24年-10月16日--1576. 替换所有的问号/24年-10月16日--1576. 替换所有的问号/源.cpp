#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include<iostream>

using namespace std;

string modifyString(string s) {
    string ret;
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch != '?') ret += ch;
        else {
            for (char x = 'a'; x <= 'z'; ++x) {
                if ((i == 0 || x != s[i - 1]) && (i == s.size() - 1 || x != s[i + 1])) {
                    ret += x;
                    break;
                }
            }
        }
    }
    return ret;
}

int main() {
	string s = { "j?qg??b" };
    string ret = modifyString(s);
    cout << ret;
	return 0;
}
