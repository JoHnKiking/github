#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>

using namespace std;

typedef long long LL;
const int N = 1000001;

int n, m;
int r[N];
int d[N], s[N], t[N];
LL e[N];

bool check(int mid)
{
	memset(e, 0, sizeof(e));

	for (int i = 1; i <= mid; i++)
	{
		e[s[i]] += d[i];
		e[t[i] + 1] -= d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		e[i] += e[i - 1];
		if (e[i] > r[i])
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &d[i], &s[i], &t[i]);
	}
	int L = 0, R = m;
	while (L < R)
	{
		int mid = L + (R - L + 1) / 2;
		if (check(mid))
			L = mid;
		else
			R = mid -1;
	}
	if (R == m)
		printf("%d", 0);
	else
		printf("%d\n%d", -1, R + 1);
}

