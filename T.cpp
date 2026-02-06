#include<iostream>
using namespace std;
#define maxSize 10
struct Term {
	int row;//行
	int col;//列
	int value;//值
};//三元组
struct SparseMatrix {
	int m;//矩阵的行数
	int n;//矩阵的列数
	int t;//非零元素的个数
	Term table[maxSize];
};
//稀疏矩阵的转置方法1冒泡排序(A->B)
void T1(SparseMatrix& A, SparseMatrix& B)
{
	B.m = A.n;
	B.n = A.m;
	B.t = A.t;
	for (int i = 0;i < A.t;i++) {
		B.table[i].col = A.table[i].row;
		B.table[i].row = A.table[i].col;
		B.table[i].value = A.table[i].value;
	}
	for (int i = 0;i < A.t;i++) {
		int k = i;
		Term min = B.table[i];
		for (int j = i+1;j < A.t;j++) {
			if (B.table[j].row < min.row) {
				min = B.table[j];
				k = j;
			}
		}
		min = B.table[i];
		B.table[i] = B.table[k];
		B.table[k] = min;
	}
}
//稀疏矩阵的转置方法2直接排序
void T2(SparseMatrix& A, SparseMatrix& B)
{
	int k = 0;
	for (int i = 0;i < A.n;i++) {
		for (int j = 0;j < A.t;j++) {
			if (A.table[j].col == i) {
				B.table[k].row = A.table[j].col;
				B.table[k].col = A.table[j].row;
				B.table[k].value = A.table[j].value;
				k++;
			}
		}
	}
	B.m = A.n;
	B.n = A.m;
	B.t = A.t;
}
//稀疏矩阵的转置方法3快速转置
void T3(SparseMatrix& A, SparseMatrix& B)
{
	int* num = new int[A.n];
	for (int i = 0;i < A.n;i++) {
		num[i] = 0;
	}
	for (int i = 0;i < A.t;i++) {
		num[A.table[i].col]++;
	}
	int* k = new int[A.n];
	k[0] = 0;
	for (int i = 1;i < A.n;i++) {
		k[i] = num[i - 1] + k[i - 1];
	}
	for (int i = 0;i < A.t;i++) {
		int index = k[A.table[i].col]++;
		B.table[index].row = A.table[i].col;
		B.table[index].col = A.table[i].row;
		B.table[index].value = A.table[i].value;
	}
	B.m = A.n;
	B.n = A.m;
	B.t = A.t;
	delete[] num;
	delete[] k;
}
void Out(SparseMatrix& A)
{
	for (int i = 0;i < A.t;i++) {
		cout << "<" << A.table[i].row << "," << A.table[i].col << "," << A.table[i].value << ">" << endl;
	}
}
int main()
{
	int a[4][4] = { 0,1,0,2,0,0,0,0,4,0,0,0,2,0,3,0 };
	SparseMatrix A;
	SparseMatrix B;
	int k = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (a[i][j] != 0) {
				A.table[k].row = i;
				A.table[k].col = j;
				A.table[k].value = a[i][j];
				k++;
			}
		}
	}
	A.m = 4;
	A.n = 4;
	A.t = k;
	//Out(A);
	//T1(A,B);
	//T2(A,B);
	T3(A, B);
	Out(B);
	return 0;
}