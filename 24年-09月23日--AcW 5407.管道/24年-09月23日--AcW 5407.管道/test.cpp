#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;

#define max(x,y) (x) > (y) ? (x) : (y)
#define min(x,y) (x) < (y) ? (x) : (y)
#define x first
#define y second

pair<int, int> q[N];


int n, len;
int L[N], S[N];


bool check(ll mid)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (S[i] <= mid)
		{
			int t = mid - S[i];
			int l = max(1, L[i] - t);
			int r = min((ll)len, (ll)L[i] + t);
			q[cnt++] = { l,r };
		}
	}
	sort(q, q + cnt);// 使q按照第一个元素升序

	// 区间合并
	int st = -1, ed = -1;
	for (int i = 0; i < cnt; i++)
	{
		if (q[i].x <= ed + 1) ed = max(ed, q[i].y);
		else st = q[i].x, ed = q[i].y;
	}
	return st == 1 && ed == len;
}

int main()
{
	cin >> n >> len;
	for (int i = 0; i < n; i++)
	{
		cin >> L[i] >> S[i];
	}

	// 定义时间轴的左右，找时间
	ll l = 0, r = 2e9;
	while (l < r)
	{
		ll mid = l + r >> 1;
		if (check(mid)) r = mid; // 此时已经覆盖完了
		else l = mid + 1;
	}
	printf("%lld\n", r);

	return 0;
}