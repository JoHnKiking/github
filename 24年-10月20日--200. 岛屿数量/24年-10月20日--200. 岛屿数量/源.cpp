#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<queue>
#include<string>
#include<iostream>

using namespace std;

int kx[4] = { 0, 0, 1, -1 };
int ky[4] = { 1, -1, 0, 0 };
int n, m;
bool vis[310][310];

// 法一 - 递归
void check(vector<vector<string>>& grid, int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int a = x + kx[i], b = y + ky[i];
        if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == "'1'" &&
            vis[a][b] == 0)
            check(grid, a, b);
    }
}

// 法二 - 栈
void bfs(vector<vector<string>>& grid, int x, int y) {
    queue<pair<int, int>> q;
    vis[x][y] = true;
    q.push({ x, y });

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int a = i + kx[k], b = j + ky[k];
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == "1" && vis[a][b] == 0)
                q.push({ a, b }), vis[i][j] = true;
        }
    }
}

int numIslands(vector<vector<string>>& grid) {
    int ret = 0;
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == "1" && !vis[i][j]) {
                ++ret;
                bfs(grid, i, j);
            }
        }
    }
    return ret;
}


int main()
{
    vector<vector<string>> grid{ {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},{"0","0","0","0","0"} };
    cout << numIslands(grid);

    return 0;
}