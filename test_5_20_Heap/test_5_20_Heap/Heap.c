#include"Heap.h"


void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a,sizeof(HPDataType) * newcapacity);

		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}

		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size++] = x;
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			child++;
		}

		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}

void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child / 2) - 1;
	while (parent >= 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = child / 2 - 1;
		}
		else
			break;
	}
}

void HPPop(HP* php)//É¾³ýÕ»¶¥
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}