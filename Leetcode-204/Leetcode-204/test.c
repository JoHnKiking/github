#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int count = 0;
	int x;
	scanf("%d", &x);

	int i = 0;
	int j = 0;
	
	for (i = 2; i < x; i++)
	{
		count += isPrime(i);
	}
	count++;
	printf("%d", count);
	return 0;
}