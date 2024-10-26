#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() :val(0) ,left(nullptr) ,right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) :val(x), left(_left), right(_right) {}
};

bool bfs(TreeNode* root, int min, int max) {
    if (root == nullptr) return true;

    if (root->val <= min || root->val >= max) return false;
    // 检查左子树
    bool a = bfs(root->left, min, root->val);

    // 检查右子树
    bool b = bfs(root->right, root->val, max);

    return a && b;
}

bool isValidBST(TreeNode* root) {
    return bfs(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* x = new TreeNode(2147483647);
    if (isValidBST(x)) cout << '1';
    else cout << '0';
}