#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// ��ʼ��������
void STInit(ST* pst);
void STDestroy(ST* pst);

// ��ջ  ��ջ
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// ȡջ������
STDataType STTop(ST* pst);

// �п�
bool STEmpty(ST* pst);
// ��ȡ���ݸ���
int STSize(ST* pst);

// ��ʼ��������
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	// topָ��ջ�����ݵ���һ��λ��
	pst->top = 0;

	// topָ��ջ������
	//pst->top = -1;

	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

// ��ջ  ��ջ
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// ����
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

// 20:08����
// ȡջ������
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

// �п�
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// ��ȡ���ݸ���
int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

//��ʼ������ջininin��outoutout������ֱ�Ӿ���inininѹջ�������ȼ��outoutout������û��Ԫ�أ��еĻ�outoutout��ջ�����Ƕ��ף�������Ȱ�ininin�����Ԫ�ص���ѹ�뵽outoutout�С��������ܱ�֤outoutout��ջ��ʼ�ն��Ƕ��ף�ininin��ջ��ʼ�ն��Ƕ�β��
typedef struct {
	ST instack;
	ST outstack;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&pq->instack);
	STInit(&pq->outstack);
	return pq;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&obj->instack, x);
}

void inTOout(MyQueue* obj)
{
	while (!STEmpty(&obj->instack))
	{
		STPush(&obj->outstack, STTop(&obj->instack));
		STPop(&obj->instack);
	}
}
int myQueuePop(MyQueue* obj) {
	if (STEmpty(&obj->outstack))
	{
		inTOout(obj);
	}
	int ret = STTop(&obj->outstack);
	STPop(&obj->outstack);
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&obj->outstack))
	{
		inTOout(obj);
	}
	int ret = STTop(&obj->outstack);
	return ret;
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&obj->instack) && STEmpty(&obj->outstack);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->instack);
	STDestroy(&obj->outstack);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	myQueuePush(obj, 3);
	myQueuePush(obj, 4);

	int x = myQueuePop(obj);

	myQueuePush(obj, 3);

	x = myQueuePop(obj);
	return 0;
}