#include"Sort.h"


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//≤Â»Î≈≈–Ú£¨…˝–Ú
void InsertSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}


//œ£∂˚≈≈–Ú
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
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
 	}
}


//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (size_t i = begin + 1; i < end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[mini], &a[begin]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}


//∂—≈≈–Ú
void AdjustDown(int* a, int parent, int n)
{
	//Ω®¥Û∂—
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
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

void HeapSort(int* a, int n)
{
	//Ω®¥Û∂— O(n^2)
	for (int i = (n - 1 - 1) / 2 ; i > 0; i--)
	{
		AdjustDown(a, i, n);
	}
	int end = n - 1;

	//O(logn)
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, 0, end);
		end--;
	}
}


//øÏÀŸ≈≈–Ú
int midi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else
		{
			if (a[left] > a[right])
				return left;
			else
				return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else
		{
			if (a[left] < a[right])
				return left;
			else
				return right;
		}
	}
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return NULL;
	}

	if ((right - left + 1) < 10)
	{
		InsertSort(a+left, right - left + 1);
	}
	else
	{
		int mid = midi(a, left, right);
		Swap(&a[mid], &a[left]);


		int ret = left;
		int begin = left;
		int end = right;
		while (begin < end)
		{
			while (end > begin && a[end] >= a[ret])
				end--;
			while (end > begin && a[begin] <= a[ret])
				begin++;
			Swap(&a[end], &a[begin]);
		}
		Swap(&a[begin], &a[ret]);
		QuickSort(a, left, begin - 1);
		QuickSort(a, begin + 1, right);
	}
}


void QuickSort0(int* a, int left, int right)
{
	if (left >= right)
	{
		return NULL;
	}



	int ret = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (end > begin && a[end] >= a[ret])
			end--;
		while (end > begin && a[begin] <= a[ret])
			begin++;
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[begin], &a[ret]);
	QuickSort(a, left, begin - 1);
	QuickSort(a, begin + 1, right);
}



void BubbleSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (size_t j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
			flag = 1;
		}
		if (flag == 0)
			break;
	}
}