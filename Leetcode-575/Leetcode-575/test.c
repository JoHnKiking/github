#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void QuickSort(int* a, int left, int right)
{
    if (left >= right)
        return NULL;
    int keyi = left;
    int begin = left;
    int end = right;
    while (begin < end)
    {
        while (begin < end && a[end] >= a[keyi])
            end--;
        while (begin < end && a[begin] <= a[keyi])
            begin++;
        Swap(&a[begin], &a[end]);
    }
    Swap(&a[begin], &a[keyi]);
    QuickSort(a, left, begin - 1);
    QuickSort(a, begin + 1, right);
}


int distributeCandies(int* candyType, int candyTypeSize) {
    QuickSort(candyType, 0, candyTypeSize - 1); 
    int cur = candyType[0];
    int nums = 1;
    for (int i = 0; i < candyTypeSize; i++)
    {
        if (candyType[i] != cur)
        {
            cur = candyType[i];
            nums++;
        }
    }
    return nums > candyTypeSize/2 ? candyTypeSize/2 : nums;
}

int main()
{
	int a[] = { 1,2,3,4,2,2,1,1,1,1 };
    int x = distributeCandies(a, 10);
    printf("%d", x);
	return 0;
}