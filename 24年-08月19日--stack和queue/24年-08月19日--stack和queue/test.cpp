#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
#include"queue.h"

int main()
{
	bit::stack <int, vector<int >> st;
	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);

	
	bit::queue<int, list<int>> q;
	q.push(1);
	q.push(1);
	q.push(1);
	q.push(1);
	q.pop();
	q.pop();
	q.pop();

	return 0;
}