#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

struct cmp {
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
    for (auto l : lists)
        if (l) heap.push(l);

    ListNode* ret = new ListNode(0);
    ListNode* prev = ret;
    while (!heap.empty()) {
        ListNode* t = heap.top();
        heap.pop();
        prev->next = t;
        prev = t;
        if (t->next) heap.push(t->next);
    }
    prev = ret->next;
    delete ret;
    return prev;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n1->next = n2, n2->next = n3;

    ListNode* m1 = new ListNode(1);
    ListNode* m2 = new ListNode(3);
    ListNode* m3 = new ListNode(4);
    m1->next = m2, m2->next = m3;

    ListNode* x1 = new ListNode(1);
    ListNode* x2 = new ListNode(2);
    x1->next = x2;

    vector<ListNode*> List;
    List.push_back(n1);
    List.push_back(m1);
    List.push_back(x1);

    ListNode* ret =  mergeKLists(List);

    return 0;
}



