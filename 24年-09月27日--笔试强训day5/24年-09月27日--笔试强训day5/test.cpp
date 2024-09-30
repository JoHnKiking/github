#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include <utility>


using namespace std;

typedef long long LL;


//int main()
//{
// int q;
//	cin >> q;
//	vector<vector<int>> num(q, vector<int>(3, 0));
//	for (int i = 0; i < q; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			int tmp;
//			cin >> tmp;
//			num[i][j] = tmp;
//		}
//	}
//
//	LL ans = 0;
//	int k = 0;
//	while (k < q)
//	{
//		if (num[k][0] < num[k][1] && num[k][0] < num[k][2])
//			ans += 2 * num[k][0];
//		else if (num[k][1] < num[k][0] && num[k][1] < num[k][2])
//			ans += 2 * num[k][1];
//		else
//			ans += 2 * num[k][2];
//		
//		if ((LL)num[k][1] - ans / 2 > 0)
//		{
//			ans += ((LL)num[k][1] - ans / 2) - 1;
//		}
//		cout << ans << endl;
//		ans = 0;
//		k++;
//	}
//	
//
//
//	return 0;
//}

// 题1 解
//int main()
//{
//	int q;
//	int a, b, c;
//	cin >> q;
//	while (q--)
//	{
//		cin >> a >> b >> c;
//		int x = min(a, min(b, c));
//		cout << (x * 2 + max(0, b - x - 1)) << endl;
//	}
//	return 0;
//}


//int n, m;
//int s[2][4] = {{-1,1,0,0},{0,0,-1,1}};
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//
//    bool ISsafe(vector<vector<int>>& grid, int i, int j)
//    {
//        int k = 0;
//        while (k < 4)
//        {
//            if (i + s[0][k] >= 0 && i + s[0][k] < n && j + s[1][k] >= 0 && j + s[1][k] < m && grid[i + s[0][k]][j + s[1][k]] != 0)
//                return false;
//        }
//        return true;
//    }
//
//    bool check(vector<vector<int>>& grid, int mid)
//    {
//        
//    }
//    int rotApple(vector<vector<int>>& grid) 
//    {
//        // write code here
//        n = grid[0].size(), m = grid.size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if(ISsafe(grid,i,j))
//            }
//        }
//    }
//};
//
//int main()
//{
//	vector<vector<int>> gezi(3, vector<int>(3));
//
//		
//
//	return 0;
//}

// NC398 腐烂的苹果
//class Solution {
//public:
//    int m, n;
//    int a, b;
//    int dx[4] = { 0,0,-1,1 };
//    int dy[4] = { -1,1,0,0 };
//    
//
//    int rotApple(vector<vector<int>>& grid) 
//    {
//        m = grid.size(); 
//        n = grid[0].size();
//        queue<pair<int, int>> q;
//        vector<vector<bool>> vis(m, vector<bool>(n, false));
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] == 2)
//                    q.push({ i,j });
//            }
//        }
//        int ret = 0;
//        while (q.size())
//        {
//            int sz = q.size();
//            ++ret;
//            while (sz--)
//            {
//                auto p = q.front();
//                a = p.first;
//                b = p.second;
//                
//                q.pop();
//                for (int i = 0; i < 4; i++)
//                {
//                    int x = a + dx[i], y = b + dy[i];
//                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
//                    {
//                        vis[x][y] = true;
//                        q.push({ x,y });
//                    }
//                }
//            }
//        }
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] == 1 && !vis[i][j])
//                    return -1;
//            }
//        }
//        return ret - 1;
//    }
//};

//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param n int整型
//     * @param m int整型
//     * @return int整型
//     */
//    int check(vector<int> num, int st, int ed, int n)
//    {
//        int ret = 0;
//        while ((++st) % n != (ed + ret) % n)
//        {
//            ret += num[st % n];
//        }
//        return ret;
//    }
//
//    int LastRemaining_Solution(int n, int m) {
//        // write code here
//        vector<int> num(n, 0);
//        int count = 0;
//        int last = -1;
//        while (count < n - 1)
//        {
//            //num[((last + m + check(num, last, last + m + count, n)) % n)] = 1;
//            last = (last + m + check(num, last, last + m + count, n)) % n;
//            num[last] = 1;
//            count++;
//        }
//        return last;
//    }
//};
//
//
//int main()
//{
//    Solution sol;
//    int x = sol.LastRemaining_Solution(5, 3);
//    cout << x;
//	return 0;
//}

// 约瑟夫环

// 1. 先考虑只有一个人的情况，很明显最后剩下的就是这个人，编号为 0。
// 2. 然后逐渐增加人数，每次增加一个人时，就利用状态转移的方法，根据上一步的结果来计算新的结果。
// 3. 在计算过程中，不断进行下标映射，以保证编号的正确性。

// f(n) 代表当人数为 n 时，获胜(出列)的人的编号
// 假设这个编号是 m-1
// 那么 f(n-1) 中存的就是上一次的获胜(出列)的人的编号，即编号 m 往前推 m 个
// 
// 如此可以倒推  f(n-1) 到 f(n) 即为 (f(n-1) + m) % n
// 即 f(n) = (f(n-1) + m) % n

int main()
{
	int x ,m;
	int f = 0; // 当人数 i 为 1 时得获胜编号
	cin >> x >> m;
	for (int i = 2; i <= x; i++) f = (f + m) % i;
	cout << f;
}