#include"Heap.h"


void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}


void TestHeap2()
{
	int a[] = { 1,3,4,2,6,8,5,7 };
	HeapSort(a, sizeof(a)/sizeof(a[0]));
}



void CreateNData()
{
	int n = 100000;
	srand((unsigned int)time(NULL));

	FILE* pFile = fopen("data.txt", "w");
	if (pFile == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 10000000;
		fprintf(pFile, "%d\n", x);
	}
	fclose(pFile);
}


void PrintTopK(int k)
{
	int* hminheap = (int*)malloc(sizeof(int) * k);
	if (hminheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	FILE* pFile = fopen("data.txt", "r");
	if (pFile == NULL)
	{
		perror("fopen fail");
		return;
	}
	
	//读取前k个数
	for (int i = 0; i < k; i++)
	{
		fscanf(pFile, "%d", &hminheap[i]);
	}

	//建立k个数的小堆
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hminheap, k, i);
	}

	//读取剩下的数
	int x;
	while (fscanf(pFile, "%d", &x) > 0)
	{
		if (x > hminheap[0])
		{
			hminheap[0] = x;
			AdjustDown(hminheap, k, 0);
		}
	}
	printf("最大前%d个数分别是：\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", hminheap[i]);
	}
}


int main()
{
	//CreateNData();

	PrintTopK(10);
	return 0;
}