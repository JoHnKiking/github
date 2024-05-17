#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int difficulty;
    int profit;
} Work;

int cmp(const void* a, const void* b) {
    return ((Work*)b)->profit - ((Work*)a)->profit;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit,
    int profitSize, int* worker, int workerSize) {
    Work work[2000] = { 0 };
    int workNum = difficultySize;

    for (int i = 0; i < difficultySize; i++) {
        work[i].difficulty = difficulty[i];
        work[i].profit = profit[i];
    }

    qsort(work, workNum, sizeof(Work), cmp);

    int result = 0;

    for (int i = 0; i < workerSize; i++) {
        for (int j = 0; j < workNum; j++) {
            if (worker[i] >= work[j].difficulty) {
                result += work[j].profit;
                break;
            }
        }
    }

    return result;
}

int main()
{
    int difficulty[] = { 2,4,6,8,10 };
    int profit[] = { 10,20,30,40,50 };
    int worker[] = { 4,5,6,7 };
    maxProfitAssignment(difficulty, 5, profit, 5, worker, 4);
    return 0;
}