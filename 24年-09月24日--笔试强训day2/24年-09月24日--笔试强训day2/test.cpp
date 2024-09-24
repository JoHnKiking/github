#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

#define Big(x,y) (x) > (y) ? (x) : (y);
#define Small(x,y) (x) < (y) ? (x) : (y);

const int N = 1e5 + 10;



//int main1()
//{
//	float a;
//	char b;
//	cin >> a >> b;
//
//	int pay = 0;
//	if (b == 'y')		pay += 5;
//	if (a <= 1)		pay += 20;
//	else
//	{
//		if ((a - 1.0) == (int)a - 1)
//			pay += 20 + a - 1;
//		else
//			pay += 20 + (int)a;
//	}
//	printf("%d", pay);
//
//	return 0;
//}


//int n;
//int cost[N];
//int dp[N]; // dp表示到某一级台阶所需的最短时间
//
//int main2()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)	cin >> cost[i];
//
//	memset(dp, 1e4 + 10, sizeof(dp));
//	dp[0] = dp[1] = 0;// 前两级设为0
//
//	for (int i = 2; i <= n; i++)
//	{
//		// 最大值为1e9 比 21亿 小，int足以
//		dp[i] = Small(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//	}
//	printf("%d", dp[n]);
//
//	return 0;
//}

int n;
string str1, str2;
vector<string> strs;

int main()
{
	cin >> n >> str1 >> str2;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}

	int x = -1, y = -1;
	for (int i = 0; i < n; i++)
	{
		if (strs[i] == str1)
		{
			if((y != -1 && x != -1 && abs(x-y) > abs(i - y) || (y == -1 || x == -1)))
				x=i;
		}
		else if (strs[i] == str2)
		{
			if ((y != -1 && x != -1 && abs(x - y) > abs(i - x) || (y == -1 || x == -1)))
				y = i;
		}
	}
	if (x != -1 && y != -1)
		printf("%d", abs(x - y));
	else
		printf("%d", -1);



	return 0;
}