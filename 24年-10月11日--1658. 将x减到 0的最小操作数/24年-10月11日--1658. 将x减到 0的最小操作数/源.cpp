#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int minOperations(vector<int>& nums, int x) {
    int left = 0, right = 0, sum = 0, n = nums.size();
    for (auto e : nums) sum += e;
    int target = sum - x;
    int len = -1, cur = 0;;
    while (right < n) {
        cur += nums[right++];
        while (cur > target) {
            cur -= nums[left++];
        }
        if (cur == target) len = max(len, right - left);
    }
    return len == -1 ? -1 : n - len;
}

int main()
{
    vector<int> v{ 5,2,3,1,1 };
    int ret = minOperations(v, 5);
    cout << ret;
    return 0;
}