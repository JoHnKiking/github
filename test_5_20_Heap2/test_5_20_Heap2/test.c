#include"Heap.h"

int main()
{

	//���Դ���������
	char a[17] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int b = 0;
	int* pi = &b;
	BTNode* root = BinaryTreeCreate(a, 16, pi);
	printf("\n");
	
	//���Զ������ڵ����
	printf("\n�ڵ����Ϊ%d\n", BinaryTreeSize(root));

	//���Զ�����Ҷ�ӽڵ����
	printf("\nҶ�ӽڵ����Ϊ%d\n", BinaryTreeLeafSize(root));
	
	//���Զ�������k��ڵ����
	printf("\n��k��ڵ����Ϊ%d\n", BinaryTreeLevelKSize(root, 4));

	//���Զ���������ֵΪx�Ľڵ�
	BTNode* ret = BinaryTreeFind(root, 'E');

	//��������
	BinaryTreeDestory(&root);

	return 0;
}