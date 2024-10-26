#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>

using namespace std;


class Solution {
    vector<vector<int>> ret;
    int n;
    vector<int> path;
    bool check[7] = { false };
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums) {
        if (path.size() == n) ret.push_back(path);

        for (int i = 0; i < nums.size(); ++i) {
            if (!check[i]) {
                check[i] = true;
                path.push_back(nums[i]);
                dfs(nums);

                // »ØËÝ
                check[i] = false;
                path.pop_back();
            }
        }
    }
};