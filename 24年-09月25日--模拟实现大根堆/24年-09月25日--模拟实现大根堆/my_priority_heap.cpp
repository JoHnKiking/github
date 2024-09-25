#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include <utility>

using namespace std;

// 模拟实现queue，仅相关操作
template<typename T>
class my_queue
{
public:
	// 默认构造函数
	my_queue()
		: qhead(nullptr)
		, qtail(nullptr)
		, size(0)
	{};

	// 拷贝构造函数
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

	// 析构函数
	~my_queue()
	{
		while (!this->empty())
		{
			this->pop();
		}
	}

	// 判空
	bool empty()
	{
		return this->size == 0;
	}

	// 队列数量
	int _size()
	{
		return this->size;
	}

	// 尾插
	void push(T val)
	{
		QNode* newQueue = new QNode(val);// 动态开辟一个值为 val 的 QNode
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

	// 头删
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

	// 获得队头节点元素
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


// 模拟实现 priority_heap
template<typename T>
class my_priority_heap // 优先队列，大根堆
{
public:
	// 尾插，实现自动大根堆
	void push(T val)
	{
		heap.push_back(val);
		adjustup(heap.size() - 1);
	}

	// 获得堆顶的值
	T top()
	{
		if (heap.size() == 0)
			return T();
		return heap[0];
	}


	// 头删，实现自动大根堆
	void pop()
	{
		if (heap.size() == 0)
			return;
		heap[0] = heap.back();
		heap.pop_back();// vector 在创建的时候可能会开辟空间，不能直接 size-- 会造成内存泄漏	
		adjustdown(0);
	}

	// swap 实现
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

	// 向上调整
	void adjustup(int index)
	{
		if (index > 0 && (heap[index] > heap[parent(index)]))
		{
			swap(index, parent(index));
			index = parent(index);
			adjustup(index);
		}
	}

	// 向下调整
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