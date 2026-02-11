#include<iostream>
using namespace std;
struct BTNode {
	int num;
	BTNode* leftkid;
	BTNode* rightkid;
};
struct BinaryTree {
	BTNode* root;
};
void Create(BinaryTree& T)
{
	T.root = NULL;
}
BTNode* NewNode(int num,BTNode* ln, BTNode* rn)
{
	BTNode* nn = new BTNode;
	nn->num = num;
	nn->leftkid = ln;
	nn->rightkid = rn;
	return nn;
}
bool IsEmpty(BinaryTree& T)
{
	if (T.root == NULL) {
		return true;
	}
	else {
		return false;
	}
}
void ClearTree(BTNode*& T)
{
	if (T->leftkid != NULL) {
		ClearTree(T->leftkid);
	}
	if (T->rightkid != NULL) {
		ClearTree(T->rightkid);
	}
	delete T;
	T = NULL;
}
void Root(BinaryTree& T, int& x)
{
	x = T.root->num;
}
void PreOrderTree(BTNode* T)
{
	cout << T->num << "\t";
	if (T->leftkid != NULL) {
		PreOrderTree(T->leftkid);
	}
	if (T->rightkid != NULL) {
		PreOrderTree(T->rightkid);
	}
}
void InOrderTree(BTNode* T)
{
	if (T->leftkid != NULL) {
		InOrderTree(T->leftkid);
	}
	cout << T->num << "\t";
	if (T->rightkid != NULL) {
		InOrderTree(T->rightkid);
	}
}
void PostOrderTree(BTNode* T)
{
	if (T->leftkid != NULL) {
		PostOrderTree(T->leftkid);
	}
	if (T->rightkid != NULL) {
		PostOrderTree(T->rightkid);
	}
	cout << T->num << "\t";
}
int main()
{
	BTNode* A = new BTNode;
	BTNode* B = new BTNode;
	BTNode* C = new BTNode;
	BTNode* D = new BTNode;
	BTNode* E = new BTNode;
	BTNode* F = new BTNode;
	A->num = 1;
	B->num = 2;
	C->num = 3;
	D->num = 4;
	E->num = 5;
	F->num = 6;
	A->leftkid = B;
	A->rightkid = C;
	B->leftkid = D;
	B->rightkid = E;
	C->leftkid = NULL;
	C->rightkid = NULL;
	D->leftkid = F;
	D->rightkid = NULL;
	E->leftkid = NULL;
	E->rightkid = NULL;
	F->leftkid = NULL;
	F->rightkid = NULL;
	PostOrderTree(A);
	cout << endl;
	InOrderTree(A);
	cout << endl;
	PreOrderTree(A);
	ClearTree(A);
	return 0;
}