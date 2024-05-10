#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);

// ��β����
void QueuePush(Queue* pq, QDataType x);
// ��ͷɾ��
void QueuePop(Queue* pq);

// ȡ��ͷ�Ͷ�β������
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//��ȡ���г���
int QueueSize(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

