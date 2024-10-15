#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
using namespace std;


// 题1
//int main() {
//    string s;
//    cin >> s;
//    int left = 0, right = 0;
//    int a = 0, b = 0;
//    while (right < s.size()) {
//        if (s[right] >= '0' && s[right] <= '9') ++right;
//        else {
//            if (b - a < right - left) a = left, b = right;
//            while (right < s.size() && !(s[right] >= '0' && s[right] <= '9')) {
//                ++right;
//            }
//            left = right;
//        }
//    }
//    cout << s.substr(a, b - a);
//
//    return 0;
//}
// 64 位输出请用 printf("%lld")

// 题2
//int m, n;
//vector<int> kx{ 0 , 0, -1, 1 };
//vector<int> ky{ -1 ,1, 0, 0 };
//int check(vector<vector<char>>& grid, int i, int j) {
//    if (i < 0 || i >= m || j < 0 || j >= n)
//        return 0;
//    
//    if (grid[i][j] == '1') {
//        grid[i][j] = '0';
//        
//        return 1 + check(grid, i + kx[0], j + ky[0])// 左
//            + check(grid, i + kx[1], j + ky[1])// 右
//            + check(grid, i + kx[2], j + ky[2])// 上
//            + check(grid, i + kx[3], j + ky[3]);// 下
//    }
//    return 0;
//}
//int solve(vector<vector<char>>& grid) {
//    // write code here
//    int ret = 0;
//    m = grid.size(), n = grid[0].size();
//    vector<vector<int>> flag(m, vector<int>(n, 0));
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (grid[i][j] == '1') {
//                if (check(grid, i, j) > 1) ++ret;
//            }
//        }
//    }
//    return ret;
//}
//int main()
//{
//	//vector<vector<char>> grid = { {1,1,0,0,0},{0,1,0,1,1},{0,0,0,1,1},{0,0,0,0,0},{0,0,1,1,1} };
//    vector<vector<char>> grid = { {'1','0'},{'0','1'},{'0','1'}};
//    int x = solve(grid);
//    printf("%d", x);
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main()
{
    vector<vector<int>> twoDVector;
    int numRows, numCols;
    cin >> numRows >> numCols;

    // 循环读取每一行的数据
    for (int i = 0; i < numRows; ++i) {
        vector<int> row;
        for (int j = 0; j < numCols; ++j) {
            int num;
            cin >> num;
            row.push_back(num);
        }
        twoDVector.push_back(row);
    }
    for (auto e : twoDVector) {
        for (auto n : e) cout << n << " ";
    }
}

//int main() {
//    int t;
//    cin >> t;
//    int nums[t][6];
//    for (int i = 0; i < t; ++i) {
//        for (int j = 0; j < 6; ++j) {
//            cin >> nums[i][j];
//        }
//    }
//
//
//    for (int i = 0; i < t; ++i) {
//        if ((ll)nums[i][0] + nums[i][1] + nums[i][2] + nums[i][3] <= (ll)nums[i][4] +
//            nums[i][5])
//            cout << "No" << endl;
//        else {
//            if (((ll)nums[i][0] + nums[i][1] > (ll)nums[i][4]) &&
//                ((ll)nums[i][2] + nums[i][3] > (ll)nums[i][5]))
//                cout << "Yes" << endl;
//            else if (((ll)nums[i][0] + nums[i][2] > (ll)nums[i][4]) &&
//                ((ll)nums[i][1] + nums[i][3] > (ll)nums[i][5]))
//                cout << "Yes" << endl;
//            else if (((ll)nums[i][0] + nums[i][3] > (ll)nums[i][4]) &&
//                ((ll)nums[i][1] + nums[i][2] > (ll)nums[i][5]))
//                cout << "Yes" << endl;
//            else if (((ll)nums[i][0] + nums[i][3] > (ll)nums[i][5]) &&
//                ((ll)nums[i][1] + nums[i][2] > (ll)nums[i][4]))
//                cout << "Yes" << endl;
//            else cout << "No" << endl;
//        }
//    }
//
//}
























// 64 位输出请用 printf("%lld")

