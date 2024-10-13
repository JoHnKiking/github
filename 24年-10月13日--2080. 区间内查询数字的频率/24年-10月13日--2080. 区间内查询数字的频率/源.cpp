#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include <queue>
#include<unordered_map>

using namespace std;

class RangeFreqQuery {
private:
    // 记录每个元素出现的下标 无序
    unordered_map<int, vector<int>> occurences;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) occurences[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        vector<int>& cur = occurences[value];
        // 找下标数组中大于等于左下标 left 的第一个数
        int Lleft = 0, Rright = cur.size();
        while (Lleft < Rright) {
            int mid = Lleft + ((Rright - Lleft) >> 1);
            if (cur[mid] >= left) Rright = mid;
            else Lleft = mid + 1;
        }
        int l = Rright;

        // 找下标数组中小于等于右下标 right 的第一个数
        Lleft = -1, Rright = cur.size() - 1;
        while (Lleft < Rright) {
            int mid = Lleft + ((Rright - Lleft + 1) >> 1);
            if (cur[mid] <= right) Lleft = mid;
            else Rright = mid - 1;
        }
        int r = Lleft;
        if (r < l) return 0;
        return r - l + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main()
{

    std::vector<int> arr = { 2,2,1,2,2 };
    RangeFreqQuery rf(arr);
    rf.query(2, 4, 1);

    return 0;
}