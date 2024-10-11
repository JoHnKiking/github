#define _CRT_SECURE_NO_WARNINGS 1
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = nums[left];
        int ans = 0;
        while (left <= right && right < n) {
            if (sum < target) {
                if (++right == n)
                    break;
                sum += nums[right];
            }
            else {
                if (ans == 0)
                    ans = right - left + 1;
                else {
                    ans = min(ans, right - left + 1);
             
                    sum -= nums[left++];
                }
                if (ans == 1)
                    return 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v{ 2,3,1,2,4,3 };
    Solution s;
    int ret = s.minSubArrayLen(7, v);
    cout << ret;
}