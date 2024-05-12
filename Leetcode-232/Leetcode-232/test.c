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

// 初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);

// 入栈  出栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// 取栈顶数据
STDataType STTop(ST* pst);

// 判空
bool STEmpty(ST* pst);
// 获取数据个数
int STSize(ST* pst);

// 初始化和销毁
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	// top指向栈顶数据的下一个位置
	pst->top = 0;

	// top指向栈顶数据
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

// 入栈  出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// 扩容
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

// 20:08继续
// 取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

// 判空
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// 获取数据个数
int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

//初始化两个栈ininin和outoutout，出队直接就往ininin压栈，出队先检查outoutout里面有没有元素，有的话outoutout的栈顶就是队首，否则就先把ininin里面的元素弹出压入到outoutout中。这样就能保证outoutout的栈顶始终都是队首，ininin的栈顶始终都是队尾。
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