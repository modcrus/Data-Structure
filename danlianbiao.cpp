//#include<iostream>
//using namespace std;
//struct Node {
//	int data;//单链表数据元素的数据域
//	Node* next;//单链表数据元素的指针域
//};
//struct SingleList {
//	Node* head;//头指针
//	int n;//单链表长度
//};
//bool Init(SingleList& L)
//{
//	L.head = NULL;
//	L.n = 0;
//	return true;
//}
//bool Destroy(SingleList& L)
//{
//	if (L.head != NULL) {
//		Node* p = L.head;
//		Node* q = NULL;
//		while (p != NULL) {
//			q = p;
//			p = p->next;
//			delete q;
//		}
//		L.head = NULL;
//		L.n = 0;
//	}
//	return true;
//}
//bool IsEmpty(SingleList L)
//{
//	if (L.n == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int Length(SingleList L)
//{
//	return L.n;
//}
////int Find(SingleList L, int i)
////{
////	if (i < 0 || i > L.n - 1) {
////		return 0;
////	}
////	else {
////		Node* p = L.head;
////		Node* q;
////		int x;
////		while (p != NULL && i != -1) {
////			q = p;
////			p = p->next;
////			x = q->data;
////			i = i - 1;
////		}
////		return x;
////	}
////}
//int Find(SingleList L, int i)
//{
//	if (i < 0 || i > L.n - 1) {
//		return 0;
//	}
//	Node* p = L.head;
//	for (int j = 0;j < i;j++) {
//		p = p->next;
//	}
//	return p->data;
//}
////bool Insert(SingleList& L, int i, int x)
////{
////	if (i < -1 || i > L.n - 1) {
////		return false;
////	}
////	else {
////		Node* p = L.head;
////		Node* q = NULL;
////		if (i == -1) {
////			if (!(q = new Node)) {
////				return false;
////			}
////			L.head = q;
////			q->data = x;
////			q->next = p;
////		}
////		else {
////			while (p != NULL && i != -1) {
////				i -= 1;
////				q = p;
////				p = p->next;
////			}
////			Node* k;
////			if (!(k = new Node)) {
////				return false;
////			}
////			q->next = k;
////			k->next = p;
////			k->data = x;
////		}
////		L.n += 1;
////		return true;
////	}
////}
//bool Insert(SingleList& L, int i, int x)//数值x插入成为第（i+1）个数据元素
//{
//	if (i < 0 || i > L.n) {
//		return false;
//	}
//	if (i == 0) {
//		Node* k;
//		if (!(k = new Node)) {
//			return false;
//		}
//		k->next = L.head;
//		L.head = k;
//		k->data = x;
//	}
//	else {
//		Node* p = L.head;
//		for (int j = 0;j < i - 1;j++) //寻找插入的前一个数据元素
//		{
//			p = p->next;
//		}
//		Node* k;
//		if (!(k = new Node)) {
//			return false;
//		}
//		k->next = p->next;
//		p->next = k;
//		k->data = x;
//	}
//	L.n += 1;
//	return true;
//}
////bool Delete(SingleList& L, int i)
////{
////	if (i < 0 || i > L.n - 1) {
////		return false;
////	}
////	if (L.n == 0) {
////		return false;
////	}
////	if (i == 0) {
////		Node* k = L.head;
////		L.head = L.head->next;
////		delete k;
////
////	}
////	else {
////		Node* p = L.head;
////		Node* q = NULL;
////		while (p != NULL && i != 0) {
////			i -= 1;
////			q = p;
////			p = p->next;
////		}
////		q->next = p->next;
////		delete p;
////	}
////	L.n -= 1;
////	return true;
////}
//bool Delete(SingleList& L, int i)
//{
//	if (i < 0 || i > L.n - 1) {
//		return false;
//	}
//	if (i == 0) {
//		Node* k = L.head;
//		L.head = L.head->next;
//		delete k;
//	}
//	else {
//		Node* p = L.head;
//		for (int j = 0;j < i - 1;j++) {
//			p = p->next;
//		}
//		Node* k = p->next;
//		p->next = k->next;
//		delete k;
//	}
//	L.n -= 1;
//	return true;
//}
////bool Update(SingleList& L, int i, int x)
////{
////	if (i < 0 || i > L.n - 1) {
////		return false;
////	}
////	Node* p = L.head;
////	Node* q = NULL;
////	while (p != NULL && i != -1) {
////		i -= 1;
////		q = p;
////		p = p->next;
////	}
////	q->data = x;
////	return true;
////}
//bool Update(SingleList& L, int i, int x)
//{
//	if (i < 0 || i > L.n - 1) {
//		return false;
//	}
//	Node* p = L.head;
//	for (int j = 0;j < i;j++) {
//		p = p->next;
//	}
//	p->data = x;
//	return true;
//}
//int main()
//{
//	SingleList L;
//	cout << Init(L);
//	cout << Insert(L, 0, 5);
//	cout << Insert(L, 0, 6);
//	cout << Update(L, 1, 6) << endl;
//	cout << "链表的长度为" << L.n << endl << "链表第一个元素为" << Find(L, 0) << endl << "链表第二个元素为" << Find(L, 1) << endl;
//	Destroy(L);
//	return 0;
//}