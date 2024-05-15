#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>



struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
 

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (root == NULL) {
        return res;
    }

    struct TreeNode* p1 = root, * p2 = NULL;

    while (p1 != NULL) {
        p2 = p1->left;
        if (p2 != NULL) {
            while (p2->right != NULL && p2->right != p1) {
                p2 = p2->right;
            }
            if (p2->right == NULL) {
                res[(*returnSize)++] = p1->val;
                p2->right = p1;
                p1 = p1->left;
                continue;
            }
            else {
                p2->right = NULL;
            }
        }
        else {
            res[(*returnSize)++] = p1->val;
        }
        p1 = p1->right;
    }
    return res;
}
