#include<iostream>
using namespace std;
struct SQueue {
	int front;
	int rear;
	int maxSize;
	int* data;
};
bool Create(SQueue& Q, int maxSize)
{
	Q.data = NULL;
	if (!(Q.data = new int[maxSize])) {
		return false;
	}
	Q.maxSize = maxSize;
	Q.front = 0;
	Q.rear = 0;
	return true;
}
bool Destroy(SQueue& Q)
{
	delete[] Q.data;
	Q.data = NULL;
	Q.front = 0;
	Q.rear = 0;
	Q.maxSize = 0;
	return true;
}
bool IsEmpty(SQueue& Q)
{
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}
bool IsFull(SQueue& Q)
{
	if ((Q.rear + 1) % Q.maxSize == Q.front) {
		return true;
	}
	else {
		return false;
	}
}
bool Front(SQueue& Q, int& x)
{
	if (Q.front == Q.rear) {
		return false;
	}
	x = Q.data[(Q.front + 1) % Q.maxSize];
	return true;
}
bool EnQueue(SQueue& Q, int x)
{
	if ((Q.rear + 1) % Q.maxSize == Q.front) {
		return false;
	}
	Q.data[(Q.rear + 1) % Q.maxSize] = x;
	Q.rear = (Q.rear + 1) % Q.maxSize;
	return true;
}
bool DeQueue(SQueue& Q)
{
	if (Q.rear == Q.front) {
		return false;
	}
	Q.front = (Q.front + 1) % Q.maxSize;
	return true;
}
void Clear(SQueue& Q)
{
	Q.front = 0;
	Q.rear = 0;
}
int main()
{
	SQueue Q;
	cout << Create(Q, 10);
	cout << EnQueue(Q, 1);
	cout << EnQueue(Q, 2);
	cout << EnQueue(Q, 3);
	Clear(Q);
	cout << EnQueue(Q, 4);
	cout << EnQueue(Q, 5);
	cout << EnQueue(Q, 6) << endl;
	int x = 0;
	int i = 1;
	while (Q.front != Q.rear) {
		Front(Q, x);
		cout << "第" << i << "个出队列的值为" << x << endl;
		DeQueue(Q);
		i++;
	}
	Destroy(Q);
	return 0;
}