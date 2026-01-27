#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* link;
};
struct SLink {
	int n;
	Node* head;
};
bool Init(SLink& L)
{
	L.n = 0;
	if (!(L.head = new Node)) {
		return false;
	}
	L.head->link = NULL;
	return true;
}
bool Destroy(SLink& L)
{
	Node* p = L.head;
	Node* q = NULL;
	while (p != NULL) {
		q = p;
		p = p->link;
		delete q;
	}
	L.n = 0;
	L.head = NULL;
	return true;
}
bool IsEmpty(SLink& L)
{
	if (L.n == 0) {
		return true;
	}
	else {
		return false;
	}
}
int Length(SLink& L)
{
	return L.n;
}
int Find(SLink& L, int i)
{
	if (i < 0 || i > L.n - 1) {
		return 0;
	}
	Node* p = L.head->link;
	for (int j = 0;j < i;j++) {
		p = p->link;
	}
	return p->data;
}
bool Insert(SLink& L, int i, int x)
{
	if (i < 0 || i > L.n) {
		return false;
	}
	Node* p = L.head;
	for (int j = 0;j < i;j++) {
		p = p->link;
	}
	Node* k;
	if (!(k = new Node)) {
		return false;
	}
	k->link = p->link;
	p->link = k;
	k->data = x;
	L.n += 1;
	return true;
}
bool Delete(SLink& L, int i)
{
	if (i < 0 || i > L.n - 1) {
		return false;
	}
	if (IsEmpty(L)) {
		return false;
	}
	Node* p = L.head;
	for (int j = 0;j < i;j++) {
		p = p->link;
	}
	Node* k = p->link;
	p->link = k->link;
	delete k;
	L.n -= 1;
	return true;
}
bool Update(SLink& L, int i, int x)
{
	if (i < 0 || i > L.n - 1) {
		return false;
	}
	Node* p = L.head->link;
	for (int j = 0;j < i;j++) {
		p = p->link;
	}
	p->data = x;
	return true;
}
void Output(SLink& L)
{
	Node* p = L.head->link;
	int i = 1;
	while (p != NULL) {
		cout << "链表第" << i << "个元素为" << p->data << "\t";
		i++;
		p = p->link;
	}
	cout << endl;
}
void Control(SLink& L)
{
	cout << "当前链表长度为" << L.n << "您要对它做出什么操作呢？（U表示更新结点,I表示插入结点,D表示删除结点,Q表示退出控制）请输入大写字母" << endl;
	char a;
	cin >> a;
	while (a != 'Q') {
		if (a == 'I') {
			cout << "您要插入的数值为？" << endl;
			int b;
			cin >> b;
			cout << "您要将其插入成为第几个元素呢？" << endl;
			int c;
			cin >> c;
			if (!(Insert(L, c - 1, b))) {
				cout << "您输入的插入位置有问题！请进行下一步操作." << endl;
			}
		}
		else if(a == 'D') {
			cout << "您要删除第几个元素呢？" << endl;
			int c;
			cin >> c;
			if (!(Delete(L, c - 1))) {
				cout << "您输入的删除位置有问题！请进行下一步操作." << endl;
			}
		}
		else if (a == 'U') {
			cout << "您要更新的数值为？" << endl;
			int b;
			cin >> b;
			cout << "您要更新第几个元素呢？" << endl;
			int c;
			cin >> c;
			if (!(Update(L, c - 1, b))) {
				cout << "您输入的更新位置有问题！请进行下一步操作." << endl;
			}
		}
		else if (a == 'Q') {
			break;
		}
		else {
			cout << "您输入的字母非法，请输入给定的操作字母！";
		}
		cout << "当前链表长度为" << L.n << endl;
		if (L.n != 0) {
			Output(L);
		}
		cout << "您要对它做出什么操作呢？（U表示更新结点,I表示插入结点,D表示删除结点,Q表示退出控制）请输入大写字母" << endl;
		cin >> a;
	}
}
int main()
{
	SLink L;
	Init(L);
	Control(L);
	Destroy(L);
	return 0;
}