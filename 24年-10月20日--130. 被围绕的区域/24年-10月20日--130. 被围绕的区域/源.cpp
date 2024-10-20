#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    int m, n;
    bool vis[210][210] = { false };
    int kx[4] = { 0,0,1,-1 };
    int ky[4] = { 1,-1,0,0 };

public:
    void bfs(vector<vector<char>>& board, int i, int j) {
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
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !vis[x][y]) {
                    vis[x][y] = true;
                    q.push({ x,y });
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        // 中间排
        for (int i = 0; i < m; ++i) {
            // 第一列
            if (board[i][0] == 'O' && !vis[i][0])
                bfs(board, i, 0);

            // 最后一列
            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                bfs(board, i, n - 1);

        }

        // 首尾两排
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !vis[0][j])
                bfs(board, 0, j);
            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                bfs(board, m - 1, j);
        }

        // vis 不是 true 的全部转换为 X
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
        {'O','O','O'},{'O','O','O'},{'O','O','O'}
    };

    Solution solution;
    solution.solve(grid);


    return 0;
}