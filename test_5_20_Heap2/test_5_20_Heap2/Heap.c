#include"Heap.h"


BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	//a为外界传进的数组
	//n为最大长度
	//pi为我们遍历数组的指针
	//使用‘#’表示NULL
	//(*pi)++ 意味着pi所指向的那个数加一，所以pi作为指针，它所指向的数的地址不会发生变化，但它所指向的那个数会加一
	if (a[*pi] == '#' || *pi >= n)
	{
		printf("N ");
		(*pi)++;
		//因为是二叉树，所以遇到 '#' 意味着后面很有可能还有，所以pi所指向的那个数，即要查看现在查看的数组元素的下一个元素
		return NULL;
	}

	//若不为#就要创建一个新的节点
	BTNode* dst = BuyNode(a[*pi]);
	printf("%c ", dst->data);

	//递归数组的下一个元素
	(*pi)++;

	//赋值左右节点元素给当前节点
	dst->left = BinaryTreeCreate(a, n, pi);
	dst->right = BinaryTreeCreate(a, n, pi);

	return dst;
}


// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	//利用二叉树节点的特点，递归到最底层的结点，并释放
	//再一层层返回调用，自下而上逐渐销毁
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));

	free(*root);
	root = NULL;
	return;
}


// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	//递归直到叶子节点的左右节点，每往下一次，节点个数加1
	return (root == NULL) ? 0 : (BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//这种方法输出的节点是最后一个这个值的二叉树节点
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BinaryTreeFind(root->left, x);
	BinaryTreeFind(root->right, x);
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	
}