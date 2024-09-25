#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include <utility>

using namespace std;

// ģ��ʵ��queue������ز���
template<typename T>
class my_queue
{
public:
	// Ĭ�Ϲ��캯��
	my_queue()
		: qhead(nullptr)
		, qtail(nullptr)
		, size(0)
	{};

	// �������캯��
	my_queue(const my_queue& q)
		: qhead(nullptr)
		, qtail(nullptr)
		, size(0)
	{
		QNode* tmp = q.qhead;
		while (tmp != nullptr)
		{
			this->push(tmp->next);
			tmp = tmp->next;
		}
	}

	// ��������
	~my_queue()
	{
		while (!this->empty())
		{
			this->pop();
		}
	}

	// �п�
	bool empty()
	{
		return this->size == 0;
	}

	// ��������
	int _size()
	{
		return this->size;
	}

	// β��
	void push(T val)
	{
		QNode* newQueue = new QNode(val);// ��̬����һ��ֵΪ val �� QNode
		if (this->empty())
		{
			this->qhead = newQueue;
			this->qtail = newQueue;
		}
		else
		{
			this->qtail->next = newQueue;
			this->qtail = newQueue;
		}
		this->size++;
	}

	// ͷɾ
	T pop()
	{
		if (this->empty())
			return T();
		T ret = this->qhead->data;
		QNode* tmp = this->qhead;
		this->qhead = tmp->next;
		delete tmp;
		this->size--;
		if (this->size == 0)	this->qtail = nullptr;
		return ret;
	}

	// ��ö�ͷ�ڵ�Ԫ��
	T top()
	{
		if (this->empty())
			return T();
		return this->qhead->data;
	}


	
private:
	struct QNode
	{
		QNode* next;
		T data;
		QNode(const T& val)
			:next(nullptr)
			,data(val)
		{};
	};
	QNode* qhead;
	QNode* qtail;
	int size;
};


// ģ��ʵ�� priority_heap
template<typename T>
class my_priority_heap // ���ȶ��У������
{
public:
	// β�壬ʵ���Զ������
	void push(T val)
	{
		heap.push_back(val);
		adjustup(heap.size() - 1);
	}

	// ��öѶ���ֵ
	T top()
	{
		if (heap.size() == 0)
			return T();
		return heap[0];
	}


	// ͷɾ��ʵ���Զ������
	void pop()
	{
		if (heap.size() == 0)
			return;
		heap[0] = heap.back();
		heap.pop_back();// vector �ڴ�����ʱ����ܻῪ�ٿռ䣬����ֱ�� size-- ������ڴ�й©	
		adjustdown(0);
	}

	// swap ʵ��
	void swap(int i, int j)
	{
		T tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}

private:
	vector<T> heap;
	int parent(int index) { return (index - 1) / 2; }
	int leftchild(int index) { return (index * 2) + 1; }
	int rightchild(int index)	 { return (index * 2) + 2; }

	// ���ϵ���
	void adjustup(int index)
	{
		if (index > 0 && (heap[index] > heap[parent(index)]))
		{
			swap(index, parent(index));
			index = parent(index);
			adjustup(index);
		}
	}

	// ���µ���
	void adjustdown(int index)
	{
		int largest = index;
		int left = leftchild(index);
		int right = rightchild(index);
		if (left < heap.size() && heap[left] > heap[largest]) largest = left;
		if (right < heap.size() && heap[right] > heap[largest]) largest = right;
		if (largest != index)
		{
			swap(heap[largest], heap[index]);
			adjustdown(largest);
		}
	}
};



int main()
{
	my_queue<vector<int>> q1;
	vector<int> x1(5, 1);
	vector<int> x2(5, 2);
	vector<int> x3(5, 3);
	q1.push(x1);
	q1.push(x2);
	q1.push(x3);
	vector<int> x = q1.top();

	q1.pop();
	q1.pop();
	x = q1.top();

	my_priority_heap<int> p1;
	p1.push(1);
	p1.push(7);
	p1.push(5);
	p1.push(2);
	p1.push(4);
	p1.push(5);
	p1.pop();
	int y = p1.top();

	return 0;
}