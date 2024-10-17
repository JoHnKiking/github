#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool IsContinuous(vector<int>& numbers) {
    sort(numbers.begin(), numbers.end());
    int zero = 0;
    int pre = 0;
    for (auto e : numbers) {
        if (e == 0) ++zero;
        else {
            if (pre == 0 || pre + 1 == e) pre = e;
            else {
                if (e == pre) return false;
                else if (e - pre <= zero) {
                    zero -= e - pre;
                    pre = e;
                }
                else return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> num{ 1,0,0,1,0 };
    if (IsContinuous(num)) cout << "True";
    else cout << "False";
}