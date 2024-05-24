#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef char BinaryData;
typedef struct BTNode
{
    BinaryData data;
    struct BTNode* left;
    struct BTNode* right;
}BTNode;

BTNode* BuyNode(BinaryData x)
{
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    if (root == NULL)
    {
        perror("malloc fail");
        return;
    }
    root->data = x;
    printf("%c ", x);
    root->left = NULL;
    root->right = NULL;
    return root;
}

BTNode* BinaryTreeCreate(BinaryData* arr, int* pi, int n)
{
    if (arr[(*pi)] == '#' || *pi >= n)
    {
        printf("N ");
        (*pi)++;
        return NULL;
    }

    BTNode* dst = BuyNode(arr[(*pi)]);
    (*pi)++;
    dst->left = BinaryTreeCreate(arr, pi, n);
    dst->right = BinaryTreeCreate(arr, pi, n);

    return dst;
}

void BinaryInOrder(BTNode* root)
{
    if (root == NULL)
        return;
    BinaryInOrder(root->left);
    printf("%c ", root->data);
    BinaryInOrder(root->right);
}

void BinaryDestory(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryDestory(root->left);
    BinaryDestory(root->right);
    free(root);
    root = NULL;
}

int main() {
    //char arr[100];
    //scanf("%100s", arr);
    char arr[] = "ABD##E#H##CF##G##";
    int i = 0;
    int* pi = &i;
    BTNode* root = BinaryTreeCreate(arr, pi, sizeof(arr));
    printf("\n");
    BinaryInOrder(root);
    BinaryDestory(root);
    return 0;
}