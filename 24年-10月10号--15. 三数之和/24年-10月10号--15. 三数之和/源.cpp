#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; ++i) {
            // i ÖØ¸´
            while (i > 0 && nums[i] == nums[i - 1]) ++i;
            if (i >= nums.size() - 2) break;

            int j = i + 1, k = nums.size() - 1;
            int oldj = j, oldk = k;
            while (j < k) {
                // j ÖØ¸´
                if (j != oldj && nums[j] == nums[oldj]) {
                    ++j;
                    ++oldj;
                    continue;
                }
                // k ÖØ¸´
                if (k != oldk && nums[k] == nums[oldk]) {
                    --k;
                    --oldk;
                    continue;
                }

                if (nums[j] + nums[k] == -nums[i]) {
                    vector<int> v{ nums[i], nums[j], nums[k] };
                    ret.push_back(v);
                    oldj = j, ++j;
                }
                else if (nums[j] + nums[k] < -nums[i]) oldj = j, ++j;
                else oldk = k, --k;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result = solution.threeSum(nums);
    for (const auto& triplet : result) {
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}