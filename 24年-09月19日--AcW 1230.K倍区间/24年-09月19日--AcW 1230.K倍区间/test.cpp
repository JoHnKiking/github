#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

const int le = 100001;

int N, K;
int* A = new int[le]();
int* S = new int[le]();

long long* res = new long long[le]();


//判断子区间的和是否为K的倍数。对于区间[i, j]，其和为sum[j] - sum[i - 1]（当i>1时），如果这个和是K的倍数，那么(sum[j] - sum[i - 1])%k = 0，也就是sum[j]%k = sum[i - 1]%k。

int main()
{
	cin >> N >> K;
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		S[i] = (A[i] + S[i - 1]) % K;// 前缀和取余

		ans += res[S[i]];// 当前出现的前缀和余数 与 到目前为止 前 出现过的相同余数 中的 任意一个 组合，都代表这两者范围内满足条件
		res[S[i]]++;// 到目前为止 出现过 多少次 这个 前缀和余数 的情况
	}
	printf("%lld", ans + res[0]);
	return 0;
}