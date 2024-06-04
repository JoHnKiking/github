#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>




typedef struct {
    int* sums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret = (NumArray*)malloc(sizeof(NumArray));
    if (ret == NULL)
    {
        perror("ret malloc fail");
        return NULL;
    }

    ret->sums = (int*)malloc(sizeof(int) * (numsSize + 1));
    if (ret->sums == NULL)
    {
        perror("sums malloc fail");
        return NULL;
    }

    ret->sums[0] = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret->sums[i + 1] = ret->sums[i] + nums[i];
    }
    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->sums[right + 1] - obj->sums[left];
}

void numArrayFree(NumArray* obj) {
    assert(obj);
    free(obj->sums);
    obj->sums = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/