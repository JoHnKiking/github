#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<int> ret{ -1, -1 };
    if (nums.empty()) return ret;
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[right] == target) ret[0] = right;
    right = nums.size() - 1;
    while (left < right) {
        int mid = left + ((right - left + 1) >> 1);
        if (nums[mid] > target) right = mid - 1;
        else left = mid;
    }
    if (nums[left] == target) ret[1] = left;
    return ret;
}
int main()
{
    vector<int> nums{ 5,7,7,8,8,10 };
    vector<int> ret = searchRange(nums, 11);
    for (auto e : ret) cout << e << " ";
    return 0;
}