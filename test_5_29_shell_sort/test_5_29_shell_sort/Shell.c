#include"Shell.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp > a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// O(N ^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//1.首先将待排序的数组构造成一个大根堆，此时，整个数组的最大值就是堆结构的顶端
//2.将顶端的数与末尾的数交换，此时，末尾的数为最大值，剩余待排序数组个数为n - 1
//3.将剩余的n - 1个数再构造成大根堆，再将顶端数与n - 1位置的数交换，如此反复执行，便能得到有序数组
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, n, 0);
		end--;
	}
}


void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1; i < end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
			maxi = mini;
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}

int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
			return midi;
		else
		{
			if (a[right] > a[left])
				return right;
			else
				return left;
		}
	}
	else
	{
		if (a[midi] > a[right])
			return midi;
		else
		{
			if (a[right] < a[left])
				return right;
			else
				return left;
		}
	}
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return NULL;
	}
	if (right - left <= 10)
	{
		InsertSort(a, right - left + 1);
	}
	else
	{
		int midi = GetMidi(a, left, right);
		Swap(&a[midi], &a[left]);

		int keyi = left;
		int begin = left + 1;
		int end = right;
		while (begin < end)
		{
			//右边都大
			while (begin < end && a[end] >= a[keyi])
			{
				end--;
			}
			//左边都小
			while (begin < end && a[begin] <= a[keyi])
			{
				begin++;
			}
			Swap(&a[begin], &a[end]);
		}
		Swap(&a[begin], &a[keyi]);
		keyi = begin;
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}