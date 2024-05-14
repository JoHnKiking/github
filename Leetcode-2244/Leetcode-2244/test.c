#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//int minimumRounds(int* tasks, int tasksSize) {
//    int flag[10];
//    memset(flag, 0, sizeof(flag));
//    int ans = 0;
//    for (int i = 0; i < tasksSize; i++)
//    {
//        if (flag[i] == 1)
//        {
//            continue;
//        }
//        int garde = tasks[i];
//        int nums = 1;
//        int index = i + 1;
//        flag[i] = 1;
//        while (nums<3 && index<tasksSize)
//        {
//            if (tasks[index] == garde)
//            {
//                nums++;
//                flag[index] = 1;
//            }
//            index++;
//        }
//        if (nums == 1)
//        {
//            return -1;
//        }
//        else
//            ans++;
//    }
//    return ans;
//}
//int main()
//{
//    int tasks[10] = {2,2,3,3,2,4,4,4,4,4};
//    int answer = minimumRounds(tasks, 10);
//}

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    }
    else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem* curr = NULL, * tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}
