#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;


//int n;
//vector<int> parent;
//
//int Find(int index);
//void Union(int index1, int index2);
//
//vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//    n = edges.size();
//    parent.resize(n + 1);
//    // 将每个节点的父节点初始化为它本身
//    for (int i = 1; i <= n; ++i) parent[i] = i;
//
//    for (auto& edge : edges) {
//        int node1 = edge[0], node2 = edge[1];
//        int x = Find(node1), y = Find(node2);
//        if (Find(node1) != Find(node2))
//            Union(node1, node2);
//        else
//            return edge;
//    }
//    return {};
//}
//
//int Find(int index) {
//    if (parent[index] != index)
//        return Find(parent[index]);
//    return parent[index];
//}
//
//void Union(int index1, int index2) {
//    parent[Find(index1)] = Find(index2);
//}
//
//
//int main()
//{
//    vector<vector<int>> nums{ {1,2},{2,3},{3,4},{1,4},{1,5} };
//    cout << findRedundantConnection(nums)[0] << " " << findRedundantConnection(nums)[1] << endl;
//    
//}


//bool checkrow[10][10];
//bool checkcol[10][10];
//bool checkgrid[3][3][10];
//
//bool isValidSudoku(vector<vector<char>>& board) {
//    for (int row = 0; row < 9; ++row) {
//        for (int col = 0; col < 9; ++col) {
//            if (board[row][col] != '.') {
//                int num = board[row][col] - '0';
//                // 是否有效的
//                if (checkrow[row][num] || checkcol[col][num] || checkgrid[row / 3][col / 3][num])
//                    return false;
//
//                checkrow[row][num] = true;
//                checkcol[col][num] = true;
//                checkgrid[row / 3][col / 3][num] = true;
//            }
//        }
//    }
//    return true;
//}
//
//int main() {
//    vector<vector<char>> board = {
//        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };
//    isValidSudoku(board);
//}


//string word;
//int kx[4] = { 0,0,1,-1 };
//int ky[4] = { 1,-1,0,0 };
//int m, n;
//bool vis[7][7];
//
//bool dfs(vector<vector<char>>& board, int row, int col, int pos);
//bool exist(vector<vector<char>>& board, string _word) {
//    m = board.size(), n = board[0].size();
//    word = _word;
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (board[i][j] == word[0])
//                vis[i][j] = true;
//                if (dfs(board, i, j, 1) == true)
//                    return true;
//                vis[i][j] = false;
//        }
//    }
//    return false;
//}
//
//bool dfs(vector<vector<char>>& board, int row, int col, int pos) {
//    if (pos == word.size()) return true;
//    char ch = word[pos];
//    for (int k = 0; k < 4; ++k) {
//        int i = row + kx[k], j = col + ky[k];
//        if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == ch && !vis[i][j]) {
//            vis[i][j] = true;
//            if (dfs(board, i, j, pos + 1) == true) 
//                return true;
//            vis[i][j] = false;
//        }
//    }
//    return false;
//}
//
//
//int main() {
//    vector<vector<char>> board = {
//        {'A','B','C','E'},
//        {'S','F','C','S'},
//        {'A','D','E','E'}
//    };
//    if (exist(board, "ABCB")) cout << "true";
//    else cout << "false";
//}


//bool vis[15][15];
//int ret;
//int kx[4] = { 0,0,1,-1 };
//int ky[4] = { 1,-1,0,0 };
//int m, n;
//
//void dfs(vector<vector<int>>& grid, int cur, int row, int col);
//int getMaximumGold(vector<vector<int>>& grid) {
//    m = grid.size(), n = grid[0].size();
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (grid[i][j] != 0) {
//                vis[i][j] = true;
//                dfs(grid, grid[i][j], i, j);
//                vis[i][j] = false;
//            }
//        }
//    }
//    return ret;
//}
//
//void dfs(vector<vector<int>>& grid, int cur, int row, int col) {
//
//    for (int k = 0; k < 4; ++k) {
//        int a = row + kx[k], b = col + ky[k];
//        if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && grid[a][b]) {
//            vis[a][b] = true;
//            dfs(grid, cur + grid[a][b], a, b);
//            vis[a][b] = false;
//        }
//    }
//    ret = max(ret, cur);
//}
//
//int main() {
//   //vector<vector<int>> grid{ {0,6,0},{5,8,7},{0,9,0} };
//    vector<vector<int>> grid{ {1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20} };
//    cout << getMaximumGold(grid);
//    return 0;
//}


//
//bool vis[20][20];
//int path = 1, m, n, ret;
//int stx, sty, edx, edy;
//int kx[4] = { 0,0,1,-1 };
//int ky[4] = { 1,-1,0,0 };
//
//void dfs(vector<vector<int>>& grid, int cur, int i, int j);
//int uniquePathsIII(vector<vector<int>>& grid) {
//    m = grid.size(), n = grid[0].size();
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (grid[i][j] == 0) ++path;
//            else if (grid[i][j] == 1) stx = i, sty = j;
//        }
//    }
//
//    dfs(grid, 0, stx, sty);
//    return ret;
//}
//
//void dfs(vector<vector<int>>& grid, int cur, int i, int j) {
//    if (grid[i][j] == 2) {
//        if (cur == path) ++ret;
//        return;
//    }
//
//    for (int k = 0; k < 4; ++k) {
//        int x = i + kx[k], y = j + ky[k];
//        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != -1 && grid[x][y] != 1 && !vis[x][y]) {
//            vis[x][y] = true;
//            dfs(grid, cur + 1, x, y);
//            vis[x][y] = false;
//        }
//    }
//}
//
//
//int main()
//{
//    vector<vector<int>> grid{ {0,1},{2,0} };
//    cout << uniquePathsIII(grid);
//    return 0;
//}


//int kx[4] = { 0,0,1,-1 };
//int ky[4] = { 1,-1,0,0 };
//int m, n;
//int c, color;
//void dfs(vector<vector<int>>& image, int i, int j);
//vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int _color) {
//    m = image.size(), n = image[0].size();
//    if (image[sr][sc] == color) return image;
//    c = image[sr][sc];
//    color = _color;
//    dfs(image, sr, sc);
//    return image;
//}
//
//void dfs(vector<vector<int>>& image, int i, int j) {
//    image[i][j] = color;
//    for (int k = 0; k < 4; ++k) {
//        int x = i + kx[k], y = j + ky[k];
//        if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == c) {
//            dfs(image, x, y);
//        }
//    }
//}
//
//int main() {
//    vector<vector<int>> image{ {0,0,0},{0,0,0} };
//    floodFill(image, 1, 0, 2);
//}


//bool vis[300][300];
//int kx[4] = { 0,0,1,-1 };
//int ky[4] = { 1,-1,0,0 };
//int m, n, ret;
//
//void dfs(vector<vector<char>>& grid, int i, int j);
//int numIslands(vector<vector<char>>& grid) {
//    m = grid.size(), n = grid[0].size();
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (grid[i][j] == '1' && !vis[i][j]) {
//                dfs(grid, i, j);
//                ++ret;
//            }
//        }
//    }
//    return ret;
//}
//
//void dfs(vector<vector<char>>& grid, int i, int j) {
//    vis[i][j] = true;
//    for (int k = 0; k < 4; ++k) {
//        int x = i + kx[k], y = j + ky[k];
//        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y]) {
//            dfs(grid, x, y);
//        }
//    }
//}
//
//
//int main()
//{
//    vector<vector<char>> grid{ {'1','1','1','1','0'},
//                                                    {'1','1','0','1','0'},
//                                                    {'1','1','0','0','0'},
//                                                    {'0','0','0','0','0'} };
//    cout << numIslands(grid);
//}


int main() {
	priority_queue<pair<int, char>> hash;
	hash.push({ 3, 'a'});
	hash.push({ 2, 'b'});
	hash.push({ 4, 'c'});

	pair<int, char> cur = hash.top();
	cout << cur.second;
	hash.pop();
	cur = hash.top();
	cout << cur.second;

}

//string anew(string str) {
//    vector<int> tmp(26, 0);
//    priority_queue<pair<char, int>> hash;
//
//    for (auto ch : str)        ++tmp[ch - 'a'];
//
//    for (int i = 0; i < tmp.size(); ++i) {
//        if (tmp[i] != 0)
//            hash.push({ i + 'a', tmp[i] });
//    }
//    return 0;
//}
//
//int main() {
//    string s = "aaabbbcc";
//    anew(s);
//}

