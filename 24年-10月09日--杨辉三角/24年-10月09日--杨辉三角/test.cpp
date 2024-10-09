#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        for (size_t i = 0; i < numRows; ++i) {
            vv[i].resize(i + 1, 1); // ����ÿ�е�Ԫ�ظ���������ʼ��Ϊ1
            // vv[i].front() = vv[i].back() = 1;// ��Ԫ�غ�βԪ��Ϊ1
        }

        for (size_t i = 2; i < vv.size(); ++i) // ǰ���ж�Ϊ1
        {
            for (size_t j = 1; j < vv[i].size() - 1; ++j)
                // ÿһ�еĵ�һ�������һ�����Թ���
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv;
    }
};