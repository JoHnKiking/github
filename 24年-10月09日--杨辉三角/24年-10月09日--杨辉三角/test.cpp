#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        for (size_t i = 0; i < numRows; ++i) {
            vv[i].resize(i + 1, 1); // 设置每行的元素个数，并初始化为1
            // vv[i].front() = vv[i].back() = 1;// 首元素和尾元素为1
        }

        for (size_t i = 2; i < vv.size(); ++i) // 前两行都为1
        {
            for (size_t j = 1; j < vv[i].size() - 1; ++j)
                // 每一行的第一个和最后一个可以过掉
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv;
    }
};