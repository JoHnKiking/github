#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int tmp[100010];

//struct cmp {
//    bool operator()(int x, int y) {
//        return x > y;
//    }
//};
//
//
//int mergesort(vector<int>& prices, int left, int right) {
//    int input = 0;
//    int mid = left + ((right - left) >> 1);
//    input += mergesort(prices, left, mid);
//    input += mergesort(prices, mid + 1, right);
//
//    input = max(input, (prices[right] - prices[left]));
//
//    int cur1 = left, cur2 = mid + 1, i = left;
//    while (cur1 <= mid && cur2 <= right) {
//        if (prices[cur1] < prices[cur2]) tmp[i++] = prices[cur1++];
//        else tmp[i++] = prices[cur2++];
//    }
//    while (cur1 <= mid) tmp[i++] = prices[cur1++];
//    while (cur2 <= right) tmp[i++] = prices[cur2++];
//
//    for (int i = left; i <= right; ++i) prices[i] = tmp[i];
//
//    return input;
//}
//
//int maxinput(vector<int>& prices) {
//    int input = 0;
//    //priority_queue<int, vector<int>, cmp> heap;
//    mergesort(prices, 0, n - 1);
//}
//
//int main() {
//    vector<int> prices;
//
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int x;
//        cin >> x;
//        prices.push_back(x);
//    }
//    cout << maxinput(prices);
//    return 0;
//}


int main() {
    string str;
    
    vector<string> words;

    string ret;
    string ch;
    for (auto c : str) {
        if (c == ' ') words.push_back(ch), ch = "";
        else ch += c;
    }
    words.push_back(ch);
    for (int i = words.size() - 1; i >= 0; --i)
        ret += words[i] + " ";
    cout << ret;
}