#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>

using namespace std;


int m, n;
int kx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int ky[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void dfs(vector<vector<char>>& board, int i, int j);

vector<vector<char>> updateBoard(vector<vector<char>>& board,
    vector<int>& click) {
    m = board.size(), n = board[0].size();
    if (board[click[0]][click[1]] == 'M')
        return board;
    dfs(board, click[0], click[1]);
    return board;
}

void dfs(vector<vector<char>>& board, int i, int j) {
    int cout = 0;
    for (int k = 0; k < 8; ++k) {
        int x = i + kx[k], y = j + ky[k];
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') ++cout;
    }

    if (cout == 0) {
        board[i][j] = 'B';
        for (int k = 0; k < 8; ++k) {
            int x = i + kx[k], y = j + ky[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
                dfs(board, x, y);
        }
    }
    else
        board[i][j] = cout + '0';
}


int main() {
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };


    vector<int> click = { 0, 0 };

    // 调用函数更新棋盘状态
    vector<vector<char>> updatedBoard = updateBoard(board, click);

    for (const auto& row : updatedBoard) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}