#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


int maxDivScore(int* nums, int numsSize, int* divisors, int divisorsSize) {
    int index = 0;
    int flag = 0;
    int score[1000] = { 0 };
    int max = 0;
    for (int i = 0; i < divisorsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] % divisors[i] == 0) {
                flag = 1;
                score[i]++;
            }
        }
        if (max < score[i]|| (max == score[i] && divisors[i] < divisors[index])) {
            index = i;
            max = score[i];
        }
    }
    if (flag == 0)
        return -1;
    else
        return divisors[index];
}

int main()
{
    int nums[] = {4,7,9,3,9};
    int divisors[] = { 5,2,3 };

    int x = maxDivScore(nums, 5, divisors, 3);

    return 0;
}