#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

class Solution {
private:
    int m, n;
    int kx[4] = { 0, 0, 1, -1 };
    int ky[4] = { 1, -1, 0, 0 };

public:
    int cutOffTree(std::vector<std::vector<int>>& f) {
        m = f.size();
        n = f[0].size();
        std::vector<std::pair<int, int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (f[i][j] > 1) trees.push_back({ i, j });
            }
        }

        std::sort(trees.begin(), trees.end(), [&](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return f[p1.first][p1.second] > f[p2.first][p2.second];
            });

        int bx = 0, by = 0;
        int ret = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int a = trees[i].first, b = trees[i].second;
            int step = bfs(f, bx, by, a, b);
            if (step == -1) return -1;
            ret += step;
            bx = a;
            by = b;
        }
        return ret;
    }

    int bfs(std::vector<std::vector<int>>& f, int bx, int by, int ex, int ey) {
        if (bx == ex && by == ey) return 0;
        bool vis[51][51] = { false };
        std::queue<std::pair<int, int>> q;
        q.push({ bx, by });
        vis[bx][by] = true;
        int step = 0;
        while (q.size()) {
            ++step;
            int sz = q.size();
            while (sz--) {
                int a = q.front().first, b = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = a + kx[i];
                    int y = b + ky[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && f[x][y]) {
                        if (x == ex && y == ey) return step;
                        q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};

void testCutOffTree() {
    Solution solution;

    std::vector<std::vector<int>> forest1 = {
        {1, 2, 3},
        {0, 0, 4},
        {7, 6, 5}
    };
    int result1 = solution.cutOffTree(forest1);
    std::cout << "Test 1 result: " << result1 << std::endl;

    std::vector<std::vector<int>> forest2 = {
        {1, 2, 3},
        {0, 0, 0},
        {7, 6, 5}
    };
    int result2 = solution.cutOffTree(forest2);
    std::cout << "Test 2 result: " << result2 << std::endl;
}

int main() {
    testCutOffTree();
    return 0;
}