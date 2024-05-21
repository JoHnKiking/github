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


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	//aΪ��紫��������
	//nΪ��󳤶�
	//piΪ���Ǳ��������ָ��
	//ʹ�á�#����ʾNULL
	//(*pi)++ ��ζ��pi��ָ����Ǹ�����һ������pi��Ϊָ�룬����ָ������ĵ�ַ���ᷢ���仯��������ָ����Ǹ������һ
	if (a[*pi] == '#' || *pi >= n)
	{
		printf("N ");
		(*pi)++;
		//��Ϊ�Ƕ��������������� '#' ��ζ�ź�����п��ܻ��У�����pi��ָ����Ǹ�������Ҫ�鿴���ڲ鿴������Ԫ�ص���һ��Ԫ��
		return NULL;
	}

	//����Ϊ#��Ҫ����һ���µĽڵ�
	BTNode* dst = BuyNode(a[*pi]);
	printf("%c ", dst->data);

	//�ݹ��������һ��Ԫ��
	(*pi)++;

	//��ֵ���ҽڵ�Ԫ�ظ���ǰ�ڵ�
	dst->left = BinaryTreeCreate(a, n, pi);
	dst->right = BinaryTreeCreate(a, n, pi);

	return dst;
}


// ����������
void BinaryTreeDestory(BTNode** root)
{
	//���ö������ڵ���ص㣬�ݹ鵽��ײ�Ľ�㣬���ͷ�
	//��һ��㷵�ص��ã����¶���������
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


// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	//�ݹ�ֱ��Ҷ�ӽڵ�����ҽڵ㣬ÿ����һ�Σ��ڵ������1
	return (root == NULL) ? 0 : (BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1);
}

// ������Ҷ�ӽڵ����
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

// ��������k��ڵ����
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

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//���ַ�������Ľڵ������һ�����ֵ�Ķ������ڵ�
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

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	
}