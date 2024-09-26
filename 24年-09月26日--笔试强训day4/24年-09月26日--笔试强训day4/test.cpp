#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

#define MIN(x,y) (x) < (y) ? (x) : (y)
#define MAX(x,y) (x) > (y) ? (x) : (y)

using namespace std;



//int main1()
//{
//	int n;
//	scanf("%d", &n);
//	int f1 = 0, f2 = 1;
//	while (f1 + f2 <= n)
//	{
//		int tmp = f2;
//		f2 += f1;
//		f1 = tmp;
//	}
//	int ans = MIN((n - f2), (f1 + f2 - n));
//	cout << ans;
//
//	return 0;
//}



//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param board string字符串vector
//     * @param word string字符串
//     * @return bool布尔型
//     */
//
//    bool check(vector<string>& board, string word, int index, vector<vector<int>> flag, int i, int j, int x, int y)
//    {
//        if (index == word.size())
//            return true;
//        flag[x][y] = 1;
//        // 上方向
//        if (x - 1 >= 0 && board[x - 1][y] == word[index + 1] && flag[x - 1][y] == 0);
//        {
//            if (!check(board, word, index + 1, flag, i, j, x - 1, y))
//            {
//                flag[x][y] = 0;
//            }
//        }
//        // 下方向
//        if (x + 1 < i && board[x + 1][y] == word[index + 1] && flag[x + 1][y] == 0)
//        {
//            if(!check(board, word, index + 1, flag, i, j, x + 1, y))
//            {
//                flag[x][y] = 0;
//            }
//        }
//        // 左方向
//        if (y - 1 >= 0 && board[x][y - 1] == word[index + 1] && flag[x][y - 1] == 0)
//        {
//            if (!check(board, word, index + 1, flag, i, j, x, y - 1))
//            {
//                flag[x][y] = 0;
//            }
//        }
//        // 右方向
//        if (y + 1 < j && board[x][y + 1] == word[index + 1] && flag[x][y + 1] == 0)
//        {
//            if (!check(board, word, index + 1, flag, i, j, x, y + 1))
//            {
//                flag[x][y] = 0;
//            }
//        }
//        return false;
//    }
//    bool exist(vector<string>& board, string word) {
//        // write code here
//
//        int len = word.size();
//        int i = board.size();// 行数
//        int j = board[0].size();// 列数
//
//        for (int x = 0; x < i; x++)
//        {
//            for (int y = 0; y < j; y++)
//            {
//                vector<vector<int>> flag(i, vector<int>(j, 0));
//                if (check(board, word, 0, flag, i, j, x , y))
//                    return true;
//            }
//        }
//        return false;
//    }
//};
//int main()
//{
//	vector<string> v;
//    v.push_back("XYZE");
//    v.push_back("SFZS");
//    v.push_back("XDEE");
//    Solution::exist(v, "XYZZED");
//
//
//	return 0;
//}


//int main()
//{
//	int n = 15;
//	//cin >> n;
//	vector<vector<int>> num(n, vector<int>(n, 0));
//
//	num[0][0] = 1;
//	printf("%5d\n", 1);
//	for (int i = 1; i < n; i++)
//	{
//		num[i][0] = 1;
//		printf("%5d", 1);
//		for (int j = 1; j <= i; j++)
//		{
//			num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
//			printf("%5d", num[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}


class Solution {
	int m, n;
	bool vis[101][101] = { 0 };
	int dx[4] = { -1, 1 ,0,0 };
	int dy[4] = { 0 ,0 ,-1,1 };
public:
	bool exist(vector<string>& board, string word)
	{
		m = board.size(), n = board[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] = word[0])
				{
					if (dfs(board, i, j, word, 1))	return true;
				}
			}
		}
		return false;
	}
	
	bool dfs(vector<string>& board, int i, int j, string word, int pos)
	{
		if (pos == word.size()) return true;

		vis[i][j] = true;
		for (int k = 0; k < 4; k++)
		{
			int a = i + dx[k], b = j + dy[k];
			if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && board[a][b] == word[pos])
			{
				if (dfs(board, a, b, word, pos + 1))	return true;
			}
		}
		vis[i][j] = false;
		return false;
	}
};

int main()
{
	std::vector<std::string> board = { "ABCE",
														   "SFCS", 
														   "ADEE" };
	std::string word = "ABCCEE";
	Solution solution;
	bool result = solution.exist(board, word);
	std::cout << "Word found: " << (result ? "true" : "false") << std::endl;
	return 0;

	return 0;
}
