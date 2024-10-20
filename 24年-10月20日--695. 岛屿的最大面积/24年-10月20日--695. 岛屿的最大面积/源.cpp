#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    bool vis[51][51] = {false};
    int m, n;
    int kx[4] = { 0, 0, -1, 1 };
    int ky[4] = { -1, 1, 0, 0 };

public:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int ret = 1;
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({ i, j });
        while (q.size()) {
            pair<int, int> frontPair = q.front();
            int a = frontPair.first;
            int b = frontPair.second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = a + kx[k], y = b + ky[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 &&
                    !vis[i][j]) {
                    q.push({ x, y });
                    vis[x][y] = true;
                    ++ret;
                }
            }
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    area = max(area, bfs(grid, i, j));
                }
            }
        }
        return area;
    }
};



int main() {
    std::vector<std::vector<int>> grid = {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

    Solution solution;
    int maxArea = solution.maxAreaOfIsland(grid);
    std::cout << "最大岛屿面积为：" << maxArea << std::endl;

    return 0;
}