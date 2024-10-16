#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include<iostream>

using namespace std;

string convert(string s, int numRows) {
    int ns = s.size();
    int mem = 1; // 每组多少人
    int group = ns;  // 多少组
    int n = 0;
    if (numRows == 1)
        n = ns;
    else {
        mem = numRows * 2 - 2;
        group = ns / mem + 1;
        n = group * (numRows - 1); // 组数 * 每组列数
    }

    vector<vector<char>> ans(numRows, vector<char>(n, '0'));
    for (int i = 0; i < ns; ++i) {
        int g = i / mem;             // 第几组
        int id = i % mem;            // 这组的第几个
        int stl = g * max(1,(numRows - 1)); // 这组列的开始
        int row, col;
        if (id < numRows)
            row = id, col = stl;
        else {
            int x = id % numRows;
            row = (numRows - 1) - (x + 1);
            col = stl + x + 1;
        }
        ans[row][col] = s[i];
    }
    string ret;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < n; ++j)
            if (ans[i][j] != '0')
                ret += ans[i][j];
    }
    return ret;
}

int main() {
    string s{ "AB" };
    s = convert(s, 1);
    cout << s;
    return 0;
}