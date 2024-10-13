#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include <queue>

using namespace std;
// ·¨1
int f(string s) {
    int f(string s) {
        map<char, int> nums;
        for (auto e : s) nums[e]++;
        auto it = nums.begin();
        return it->second;
    }
}
vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> ret;
    int nw = words.size(), nq = queries.size();
    vector<int> wordsNum;
    vector<int> queNum;
    for (int i = 0; i < nw; ++i) wordsNum.push_back(f(words[i]));
    sort(wordsNum.begin(), wordsNum.end());

    for (int i = 0; i < nq; ++i) queNum.push_back(f(queries[i]));
    
    for (int i = 0; i < nq; ++i) {
        int que = queNum[i];
        int left = 0, right = nw;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (wordsNum[mid] > que) right = mid;
            else left = mid + 1;
        }
        ret.push_back(nw - right);
    }
    return ret;
}

// ·¨2
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries,
        vector<string>& words) {
        int m = words.size();
        vector<int> word(m, 0);

        for (int i = 0; i < m; i++) {
            word[i] = f(words[i]);
        }

        sort(word.begin(), word.end());

        int n = queries.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int query_f = f(queries[i]);
            ans[i] = m - lower_bound(word, query_f + 1);
        }

        return ans;
    }

private:
    int f(const string& s) {
        char smallest = 'z';
        int times = 0;

        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                times = 1;
            }
            else if (c == smallest) {
                times++;
            }
        }

        return times;
    }

    int lower_bound(const vector<int>& nums, int target) {
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};

int main()
{
    vector<string> queries{ "bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb" };
    vector<string> words{ "aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa" };
    vector<int> ret = numSmallerByFrequency(queries, words);
    for (auto e : ret) cout << e << " ";
    return 0;
}