#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include<iostream>

using namespace std;

string convert(string s, int numRows) {
    int ns = s.size();
    int mem = 1; // ÿ�������
    int group = ns;  // ������
    int n = 0;
    if (numRows == 1)
        n = ns;
    else {
        mem = numRows * 2 - 2;
        group = ns / mem + 1;
        n = group * (numRows - 1); // ���� * ÿ������
    }

    vector<vector<char>> ans(numRows, vector<char>(n, '0'));
    for (int i = 0; i < ns; ++i) {
        int g = i / mem;             // �ڼ���
        int id = i % mem;            // ����ĵڼ���
        int stl = g * max(1,(numRows - 1)); // �����еĿ�ʼ
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