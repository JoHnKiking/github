#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef int QueueDataType;

typedef struct {
    QueueDataType* a;
    QueueDataType head;//头元素下标
    QueueDataType tail;//尾元素后一个位置的下标
    QueueDataType k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue* pcd = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    pcd->k = k + 1;
    pcd->head = pcd->tail = 0;
    pcd->a = (QueueDataType*)malloc(sizeof(QueueDataType) * pcd->k);
    return pcd;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->tail + 1) % (obj->k) == (obj->head))
    {
        return false;
    }
    obj->a[obj->tail] = value;
    obj->tail = (obj->tail + 1) % (obj->k);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if ((obj->head) == (obj->tail))
    {
        return false;
    }
    obj->head = (obj->head + 1) % (obj->k);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if ((obj->head) == (obj->tail))
    {
        return -1;
    }
    return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if ((obj->head) == (obj->tail))
    {
        return -1;
    }
    return obj->a[(obj->tail - 1 + obj->k) % (obj->k)];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return ((obj->head) == (obj->tail));
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (((obj->tail + 1) % (obj->k)) == (obj->head));
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

int main()
{
    MyCircularQueue* obj = myCircularQueueCreate(4);
    bool x = myCircularQueueEnQueue(&obj, 1);
    x = myCircularQueueEnQueue(&obj, 2);
    x = myCircularQueueEnQueue(&obj, 3);
    x = myCircularQueueEnQueue(&obj, 4);
    x = myCircularQueueEnQueue(&obj, 5);
    return 0;
}