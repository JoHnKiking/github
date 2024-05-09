#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;

};
typedef struct ListNode ListNode;
struct ListNode* detectCycle(struct ListNode* head) {

    if (head == NULL)
        return NULL;
    ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            ListNode* phead = head;
            ListNode* meet = slow;
            while (phead != meet)
            {
                phead = phead->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}