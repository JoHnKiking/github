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


//�ж�������ĺ��Ƿ�ΪK�ı�������������[i, j]�����Ϊsum[j] - sum[i - 1]����i>1ʱ��������������K�ı�������ô(sum[j] - sum[i - 1])%k = 0��Ҳ����sum[j]%k = sum[i - 1]%k��

int main()
{
	cin >> N >> K;
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		S[i] = (A[i] + S[i - 1]) % K;// ǰ׺��ȡ��

		ans += res[S[i]];// ��ǰ���ֵ�ǰ׺������ �� ��ĿǰΪֹ ǰ ���ֹ�����ͬ���� �е� ����һ�� ��ϣ������������߷�Χ����������
		res[S[i]]++;// ��ĿǰΪֹ ���ֹ� ���ٴ� ��� ǰ׺������ �����
	}
	printf("%lld", ans + res[0]);
	return 0;
}