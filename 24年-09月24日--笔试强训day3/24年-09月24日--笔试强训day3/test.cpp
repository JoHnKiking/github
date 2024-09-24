#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;

//int main1()
//{
//	vector<string> str;
//	string sentence;
//	string temp;
//	getline(cin, sentence);
//	for (char c : sentence)
//	{
//		if (c == ' ')
//		{
//			if (!temp.empty())		str.push_back(temp), temp = "";
//		}
//		else temp += c;
//	}
//	if (!temp.empty())	str.push_back(temp);
//
//	string ret;
//	for (auto e : str)
//	{
//		char c = e[0];
//		if (c >= 'a' && c <= 'z')
//			c -= 32;
//		ret += c;
//	}
//	cout << ret << endl;
//
//	return 0;
//	
//
//}


//int main()
//{
//	int n, x;
//	cin >> n >> x;
//	int* nums = new int[N]();
//	// 1e * 1e3 = 1
//	LL* sum = new LL[N]();// 记录到n的前缀和
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> nums[i];
//		sum[i] = sum[i - 1] + nums[i];
//	}
//
//	int l1 = 0, l2 = n;
//	int l = 0, r = 1;
//	while (r <= n)
//	{
//		if (sum[r] - sum[l] < x)		++r;
//		else
//		{
//			if ((r - l < l2 - l1))
//				l1 = l, l2 = r;
//			else
//			{
//				if (l + 1 < r)
//					l++;
//				else
//					l++, r++;
//			}
//		}
//	}
//	printf("%d %d", l1 + 1, l2);
//
//	delete[] nums;
//	delete[] sum;
//
//	return 0;
//}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, k;
	LL ans = 0;
	cin >> n >> k;
	int* a = new int[N]();
	int* p = new int[N]();
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 0) p[cnt++] = a[i];
		else ans += a[i];
	}
	sort(p, p + cnt, cmp);

	while (k > 0 && p[0] != 0) {
		p[0] /= 2;
		if (p[0] % 2 != 0)
		{
			ans += p[0];
			--cnt;
			p[0] = p[cnt];
			sort(p, p + cnt, cmp);
		}
		if (p[0] < p[1])
			sort(p, p + cnt, cmp);
		--k;
	}
	for (int i = 0; i < cnt; i++)
	{
		ans += p[i];
	}
	printf("%lld", ans);
	

	delete[] a;
	return 0;
}