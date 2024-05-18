#include"Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HPDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//��С�´�
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//��С�´�
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			child++;
		}
		
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
		}
		php->a = tmp;
		php->capacity = newcapacity;
		
		AdjustUp(php->a, php->size - 1);
	}
	php->a[php->size++] = x;
}

//ɾ��ջ��
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

//��ȡ�Ѷ�Ԫ��
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return (php->a[0]);
}

//�ж϶��Ƿ�Ϊ��
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

// ��������ж����򣬽���
void HeapSort(int* a, int n)
{
	assert(a);

	//�ҵ���СԪ�أ�ʵ��С��
	for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}

	//��ȡС�Ѷ����������¶Ѵ���ʵ������
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}


