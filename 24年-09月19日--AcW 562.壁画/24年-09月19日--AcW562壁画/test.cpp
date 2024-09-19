#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;


const int N = 10000000;



// Ç°×ººÍ

int main()
{
	int T;
	int* s = new int[N]();
	char* data = new char[N];

	cin >> T;
	int cnt = 0;

	while (T--)
	{
		cnt++;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> data[i];
			s[i] = (data[i] - '0') + s[i-1];
		}

		int k = (n + 1) >> 1;

		int max = 0;
		for (int i = 1; i <= n - k + 1; i++)
		{
			if (max < (s[i + k - 1] - s[i-1]))
				max = s[i + k - 1] - s[i-1];
		}
		printf("Case #%d: %d\n", cnt, max);
	}
	delete[] s;
	delete[] data;
	return 0;
}