#pragma once
#include <iostream>
#include <vector>
using namespace std;



//int n;
//vector<int> prices;
//int tmp[100010];
//
//int mergesort(vector<int>& prices, int left, int right);
//
//int maxin(vector<int>& prices) {
//    return mergesort(prices, 0, n - 1);
//}
//
//int mergesort(vector<int>& prices, int left, int right) {
//    if (left >= right) return 0;
//    int mid = left + ((right - left) >> 1);
//
//    int ret = 0;
//    ret = max(ret, mergesort(prices, left, mid));
//    ret = max(ret, mergesort(prices, mid + 1, right));
//
//    int diff = max(0, prices[mid + 1] - prices[mid]);
//    ret = max(ret, diff);
//
//    int cur1 = left, cur2 = mid + 1, i = left;
//    while (cur1 <= mid && cur2 <= right) {
//        if (prices[cur1] >= prices[cur2]) tmp[i++] = prices[cur1++];
//        else tmp[i++] = prices[cur2++];
//    }
//    while (cur1 <= mid) tmp[i++] = prices[cur1++];
//    while(cur2 <= right) tmp[i++] = prices[cur2++];
//    for (int i = left; i <= right; ++i) {
//        prices[i] = tmp[i];
//    }
//    return ret;
//}
//
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int x;
//        cin >> x;
//        prices.push_back(x);
//    }
//   /* n = 7;
//    prices  = { 8, 9, 2, 5, 4, 7, 1 };*/
//    cout << maxin(prices);
//    return 0;
//}


#include <iostream>
#include <vector>

using namespace std;
int n, m;
int x, y;


int check(int i, int j) {// 传入 i , j 的实际位置
    if (i < 0 || i > n || j < 0 || j > m) return 0;
    else if ((x == i && y == j) || (x != i && y != j &&(abs(x - i) + abs(y - j)) == 3)) return 0;
    return 1;
}



int main() {
    cin >> n >> m >> x >> y;
    //n = 6, m = 6, x = 3, y = 3;
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));// 映射 ，实际 横纵坐标 + 1 为 dp座标
    dp[1][1] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            if (check(i - 1, j - 1) == 0) dp[i][j] = 0;
            else dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    cout << dp[n+1][m+1];
    return 0;
}
