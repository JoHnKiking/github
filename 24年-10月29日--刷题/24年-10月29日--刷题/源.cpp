#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> ret;
string path;
int n;

void dfs(int pos);
vector<string> validStrings(int _n) {
    n = _n;
    dfs(0);
    return ret;
}

void dfs(int pos) {
    if (pos == n) {
        ret.push_back(path);
        return;
    }

    // ·Å0
    if (pos == 0 || path.back() != '0') {
        path.push_back('0');
        dfs(pos + 1);
        path.pop_back();
    }
    // ·Å1
    path.push_back('1');
    dfs(pos + 1);
    path.pop_back();
}

int main()
{
    validStrings(3);
	return 0;
}