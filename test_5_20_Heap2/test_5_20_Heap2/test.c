#include"Heap.h"

int main()
{

	//测试创建二叉树
	char a[17] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int b = 0;
	int* pi = &b;
	BTNode* root = BinaryTreeCreate(a, 16, pi);
	printf("\n");
	
	//测试二叉树节点个数
	printf("\n节点个数为%d\n", BinaryTreeSize(root));

	//测试二叉树叶子节点个数
	printf("\n叶子节点个数为%d\n", BinaryTreeLeafSize(root));
	
	//测试二叉树第k层节点个数
	printf("\n第k层节点个数为%d\n", BinaryTreeLevelKSize(root, 4));

	//测试二叉树查找值为x的节点
	BTNode* ret = BinaryTreeFind(root, 'E');

	//测试销毁
	BinaryTreeDestory(&root);

	return 0;
}