#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode ListNode;
ListNode* ReverseList(struct ListNode* head) {
	// write code here
	if (head == NULL) {
		return;
	}
	ListNode* Next = head->next;
	ListNode* piror = NULL;
	ListNode* current = head;
	while (Next != NULL) {
		current->next = piror;
		piror = current;
		current = Next;
		Next = Next->next;
	}
	current->next = piror;
	head = current;
	return head;
}

bool chkPalindrome(struct ListNode* A) {
	// write code here
	if (A == NULL)
		return true;
	ListNode* quick = A;
	ListNode* slow = A;
	while (quick != NULL && quick->next != NULL) {
		quick = quick->next->next;
		slow = slow->next;
	}
	slow = ReverseList(slow);
	while (slow) {
		if (slow->val == A->val) {
			slow = slow->next;
			A = A->next;
		}
		else {
			return false;
		}
	}
	return true;
}

int main()
{
	//链表是由一个一个的节点组成的
	//创建几个节点
	ListNode* node1 = (ListNode*)malloc(sizeof(ListNode));
	node1->val = 1;

	ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
	node2->val = 3;

	ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
	node3->val = 2;

	ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
	node4->val = 3;

	ListNode* node5 = (ListNode*)malloc(sizeof(ListNode));
	node5->val = 1;

	//将4个节点联系起来
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	ListNode* node6 = (ListNode*)malloc(sizeof(ListNode));
	node6 == NULL;

	ListNode* node7 = NULL;

	bool x = chkPalindrome(node7);
	return 0;
}







