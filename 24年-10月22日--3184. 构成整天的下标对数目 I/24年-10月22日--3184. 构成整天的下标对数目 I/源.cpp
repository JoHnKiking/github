#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

int countCompleteDayPairs(vector<int>& hours) {
    unordered_map<int, int> hash;
    int ret = 0;
    for (auto e : hours) {
        int need = (24 - e % 24) % 24;
        if (hash.count(need)) ret += hash[need];
        ++hash[e % 24];
    }
    return ret;
}

int main() {
	vector<int> hours{ 12,12,30,24,24 };
    cout << countCompleteDayPairs(hours);
}