//#define _CRT_SECURE_NO_WARNINGS 1
//#include<vector>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	vector<int> team{ 9,7,7,1,1,8 };
//	sort(team.rbegin(), team.rend());
//	team.resize(4);
//}


#include <atomic>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//int ret, n, sum;
//int vis[10009] = { 1 };
//int kinds;
//
//int dfs(vector<int> num) {
//    if (kinds == 0) return 0;
//    sum = 0;
//    for (int i = 0; i < 6; ++i) {
//        if (num[i] != 0 && vis[i] != 0 && num[i] > num[i + 1] * vis[i + 1] + num[i - 1] * vis[i - 1]) {
//            vis[i - 1] = vis[i - 1] = 0;
//            kinds -= 3;
//            sum = max(sum, dfs(num));
//            vis[i - 1] = vis[i - 1] = 0;
//            kinds += 3;
//        }
//    }
//    return sum;
//}
//
//int main() {
//   /* vector<int> num(10009, 0);
//    cin >> n;
//    for (int i = 0; i < n * 3; ++i) {
//        int x;
//        cin >> x;
//        if (num[x] == 0) ++kinds;
//        num[x] += x;
//    }*/
//
//    vector<int> num{ 0,6,10,6,4 };
//    kinds = 4;
//    //sort(num.begin(), num.end());
//    dfs(num);
//    cout << ret;
//}


int main() {
    vector<long long> nums;
    for (int i = 0; i < 1000000; ++i)
        nums.push_back((long long)i * i);

    long long x = 5;
    int left = -1, right = nums.size();
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] >= x) right = mid;
        else left = mid + 1;
    }
    if (x - nums[right - 1] < nums[right] - x) cout << nums[right - 1];
    else cout << nums[right];
}

