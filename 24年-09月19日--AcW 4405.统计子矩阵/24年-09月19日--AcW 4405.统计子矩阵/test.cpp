#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

const int le = 100001;

int N, M, K;

int A[502][502] = {};

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];// ����(i, j)��(1, 1)�����ݺͣ�����(1, 1)
		}
	}

	long long ans = 0;
	for (int i1 = 1; i1 <= M; i1++)// ȷ�����
	{
		for (int i2 = i1; i2 <= M; i2++)// ȷ���ҽ�
		{
			for (int t = 1; t <= N; t++)// ȷ���½�
			{
				int s = 1;// �Ͻ������ƣ�ֱ������С��K��������������t-s+1����������
				while (s <= t && A[t][i2] - A[s-1][i2] - A[t][i1-1] + A[s-1][i1-1] > K)
				{
					s++;
				}
				if(s <=t) ans += t - s + 1;
			}
		}
	}

	cout << ans;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

const int le = 100001;

int N, M, K;

int A[502][502] = {};

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }

    long long ans = 0;
    for (int i1 = 1; i1 <= M; i1++) {
        for (int i2 = i1; i2 <= M; i2++) {
            int sum[502] = { 0 };
            for (int t = 1; t <= N; t++) {
                // Ԥ�ȼ���ÿһ�����Ӿ����з�Χ�ڵ�ǰ׺��
                sum[t] = A[t][i2] - A[t][i1 - 1];
            }
            int t1 = 1;
            int t2 = 1;
            int curSum = 0;
            for (int t2 = 1; t2 <= N; t2++)
            {
                
           }
        }
    }
    cout << ans;
    return 0;
}
