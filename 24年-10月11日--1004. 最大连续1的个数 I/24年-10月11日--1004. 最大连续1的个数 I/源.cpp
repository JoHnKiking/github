#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int ret = 0, zero = 0;
    while (right < n)
    {
        if (nums[right++] == 0) ++zero;
        while (zero > k)
        {
            zero -= nums[left++] ^ 0x1;
        }
        ret = max(ret, right - left);
    }
    return ret;
}

int main()
{
	vector<int> v{ 1,1,1,0,0,0,1,1,1,1,0 };
    int ret = longestOnes(v, 2);
    cout << ret;
}