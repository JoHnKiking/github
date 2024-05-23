#include"Heap.h"

int main()
{

	//���Դ���������
	char a[17] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	printf("�������е������ǣ�\n");
	for (int i = 0; i < 17; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n\n");

	printf("�����Ķ������е������ǣ�\n");
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

	// ������ǰ�����
	printf("\n������ǰ�������");
	BinaryTreePrevOrder(root);
	printf("\n");

	// �������������
	printf("\n���������������");
	BinaryTreeInOrder(root);
	printf("\n");

	// �������������
	printf("\n���������������");
	BinaryTreePostOrder(root);
	printf("\n");

	// ���Բ������
	printf("\n�������\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	//������ȫ����������
	printf("\n��ȫ�������ļ���ɹ���%d\n", BinaryTreeComplete(root));

	//��������
	BinaryTreeDestory(&root);

	printf("\n");
	return 0;
}