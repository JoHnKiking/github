#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l3 = nums.size() - 1;
        int ans = 0;
        while (l3 >= 2) {
            int l1 = 0, l2 = l3 - 1;
            while (l1 < l2) {
                if (l1 + l2 > l3) {
                    ans += l2 - l1;
                    l2--;
                }
                else
                    l1++;
            }
            l3--;
        }
        return ans;
    }
};


int main() {
    Solution solution;
    std::vector<int> nums1 = { 2, 2, 3, 4 };
    std::cout << "Test case 1: " << solution.triangleNumber(nums1) << std::endl;

    std::vector<int> nums2 = { 0, 0, 0 };
    std::cout << "Test case 2: " << solution.triangleNumber(nums2) << std::endl;

    std::vector<int> nums3 = { 1, 1, 1, 2, 2, 2 };
    std::cout << "Test case 3: " << solution.triangleNumber(nums3) << std::endl;

    return 0;
}
