#include"Heap.h"

int main()
{

	//测试创建二叉树
	char a[17] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	printf("二叉树中的数据是：\n");
	for (int i = 0; i < 17; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n\n");

	printf("创建的二叉树中的数据是：\n");
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

	// 二叉树前序遍历
	printf("\n二叉树前序遍历：");
	BinaryTreePrevOrder(root);
	printf("\n");

	// 二叉树中序遍历
	printf("\n二叉树中序遍历：");
	BinaryTreeInOrder(root);
	printf("\n");

	// 二叉树后序遍历
	printf("\n二叉树后序遍历：");
	BinaryTreePostOrder(root);
	printf("\n");

	// 测试层序遍历
	printf("\n层序遍历\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	//测试完全二叉树检验
	printf("\n完全二叉树的检验成果是%d\n", BinaryTreeComplete(root));

	//测试销毁
	BinaryTreeDestory(&root);

	printf("\n");
	return 0;
}