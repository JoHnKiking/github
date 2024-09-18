#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>

using namespace std;

const int N = 100000;

int n, k;
int* H = new int[N];
int* W = new int[N];

bool check(int mid)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		num += (H[i] / mid) * (W[i] / mid);
		if (num >= k)
			return true;
 	}
	return false;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> H[i] >> W[i];
	}
	int l = 0;
	int r = N;
	while (l < r)
	{
		int mid = l + ((r - l + 1) >> 1);
		if (check(mid))	l = mid;
		else r = mid - 1;
	}
	
	printf("%d", r);
	return 0;
}