#include"Heap.h"


//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//销毁
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

// 队尾插入
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
// 队头删除
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

// 取队头和队尾的数据
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

// 二叉树前序遍历 
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

// 二叉树中序遍历
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


// 二叉树后序遍历
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


// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL) {
		return;
	}

	// 使用队列实现层序遍历
	int front = 0, rear = 0;
	BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * 1000); // 假设节点数不超过1000
	queue[rear++] = root;

	while (front < rear) {
		BTNode* current = queue[front++]; // 取出队列前端节点
		printf("%c ", current->data);

		if (current->left != NULL) {
			queue[rear++] = current->left; // 左子节点入队
		}
		if (current->right != NULL) {
			queue[rear++] = current->right; // 右子节点入队
		}
	}

	free(queue); // 释放队列内存
}


// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//当遍历层序遍历二叉树的结果时，只要出现了空节点，这时，我们只需要再判断其后面是不是全为空。只要是在空节点后面的队列中出现了一个非空节点的话，那么这棵二叉树就不是一颗完全二叉树。

	int front = 0, rear = 0;
	BTNode** queue = (BTNode**)malloc(sizeof(BTNode) * 1000);//假设节点数不超过1000
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
			free(queue); // 释放队列内存
			return 0;
		}
	}
	free(queue); // 释放队列内存
	return 1;
}
