#include<iostream>
using namespace std;
struct QNode {
	int data;
	QNode* link;
};
struct LQueue {
	QNode* front;
	QNode* rear;
};
bool Create(LQueue& Q)
{
	Q.front = NULL;
	Q.rear = NULL;
	return true;
}
bool Destroy(LQueue& Q)
{
	QNode* p = Q.front;
	QNode* k = NULL;
	while (p != NULL) {
		k = p;
		p = p->link;
		delete k;
	}
	Q.front = NULL;
	Q.rear = NULL;
	return true;
}
bool Front(LQueue& Q, int& x)
{
	if (Q.front == NULL) {
		return false;
	}
	x = Q.front->data;
	return true;
}
bool EnQueue(LQueue& Q,int x)
{
	if (Q.front == NULL) {
		if (!(Q.front = new QNode)) {
			return false;
		}
		Q.rear = Q.front;
		Q.front->data = x;
		Q.front->link = NULL;
		return true;
	}
	else {
		QNode* k = NULL;
		if (!(k = new QNode)) {
			return false;
		}
		Q.rear->link = k;
		k->data = x;
		k->link = NULL;
		Q.rear = k;
		return true;
	}
}
bool DeQueue(LQueue& Q)
{
	if (Q.front == NULL) {
		return false;
	}
	QNode* k = NULL;
	k = Q.front;
	Q.front = Q.front->link;
	delete k;
	if (Q.front == NULL) {
		Q.rear = NULL;
	}
	return true;
}
int main()
{
	LQueue Q;
	cout << Create(Q);
	cout << EnQueue(Q, 1);
	cout << EnQueue(Q, 2);
	cout << EnQueue(Q, 3);
	cout << EnQueue(Q, 4);
	cout << EnQueue(Q, 5);
	cout << EnQueue(Q, 6) << endl;
	int x = 0;
	int i = 1;
	while (Q.front != NULL) {
		Front(Q, x);
		cout << "第" << i << "个出队列的值为" << x << endl;
		DeQueue(Q);
		i++;
	}
	Destroy(Q);
	return 0;
}