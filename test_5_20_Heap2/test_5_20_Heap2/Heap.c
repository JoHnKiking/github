#include"Heap.h"


//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//����
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// ��β����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc newnode fail");
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		pq->phead = newnode;
		pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;

}
// ��ͷɾ��
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);

	if (pq->size == 1)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

// ȡ��ͷ�Ͷ�β������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}








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
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if(ret1)
	{
		return ret1;
	}

	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}
	return NULL;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}


// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}


// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL) {
		return;
	}

	// ʹ�ö���ʵ�ֲ������
	int front = 0, rear = 0;
	BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * 1000); // ����ڵ���������1000
	queue[rear++] = root;

	while (front < rear) {
		BTNode* current = queue[front++]; // ȡ������ǰ�˽ڵ�
		printf("%c ", current->data);

		if (current->left != NULL) {
			queue[rear++] = current->left; // ���ӽڵ����
		}
		if (current->right != NULL) {
			queue[rear++] = current->right; // ���ӽڵ����
		}
	}

	free(queue); // �ͷŶ����ڴ�
}


// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//��������������������Ľ��ʱ��ֻҪ�����˿սڵ㣬��ʱ������ֻ��Ҫ���ж�������ǲ���ȫΪ�ա�ֻҪ���ڿսڵ����Ķ����г�����һ���ǿսڵ�Ļ�����ô��ö������Ͳ���һ����ȫ��������

	int front = 0, rear = 0;
	BTNode** queue = (BTNode**)malloc(sizeof(BTNode) * 1000);//����ڵ���������1000
	if (root)
	{
		queue[rear++] = root;
	}

	while(front < rear)
	{
		BTNode* current = queue[front++];

		if (current == NULL)
		{
			break;
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}

	}
	while (front < rear)
	{
		BTNode* current = queue[front++];
		if (current)
		{
			free(queue); // �ͷŶ����ڴ�
			return 0;
		}
	}
	free(queue); // �ͷŶ����ڴ�
	return 1;
}
