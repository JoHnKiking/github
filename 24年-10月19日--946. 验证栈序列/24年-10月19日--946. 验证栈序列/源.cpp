#define _CRT_SECURE_NO_WARNINGS 1
#include<stack>
#include<vector>
#include<iostream>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int n = pushed.size(), m = popped.size();
    int cur1 = 0, cur2 = 0;
    while (cur1 < n && cur2 < m) {
        if (st.empty() || st.top() != popped[cur2]) {
            st.push(pushed[cur1++]);
        }
        else st.pop(), cur2++;
    }
    while (cur2 < m && st.top() == popped[cur2++]) st.pop();
    return st.empty();
}

int main()
{
    vector<int> pushed{ 1,2,3,4,5 };
    vector<int> poped{ 4,5,3,2,1 };
    if (validateStackSequences(pushed, poped)) cout << true;
    else cout << false;
    return 0;
}