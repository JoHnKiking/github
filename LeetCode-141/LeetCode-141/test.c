#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdbool.h>


struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode ListNode;
bool hasCycle(struct ListNode* head) {
    if (head == NULL)
        return false;
    ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}