#include<iostream>
#include<string>
using namespace std;
struct Dataelem{
	int a;
	double b;
};
struct Shunxubiao {
	int n;//表示顺序表的长度
	int maxlength;//表示顺序表的最大长度
	Dataelem* dataelem;
};
bool Init(Shunxubiao& L1)
{
	L1.n = 0;
	L1.maxlength = 100;
	if (L1.dataelem = new Dataelem[L1.maxlength]) {
		return true;
	}
	else{
		return false;
	}
}
int Destroy(Shunxubiao& L1)
{
	if (L1.dataelem != NULL) {
		delete[] L1.dataelem;
	}
	L1.dataelem = NULL;
	L1.n = 0;
	return true;
}
bool IsEmpty(Shunxubiao L1)
{
	if (L1.n == 0) {
		return true;
	}
	else {
		return false;
	}
}
int Length(Shunxubiao L1)
{
	return L1.n;
}
Dataelem Find(Shunxubiao L1, int i)
{
	if (i < 0 || i > L1.n - 1) {
		Dataelem x = { 0,0.0 };
		return x;
	}
	else {
		return L1.dataelem[i];
	}
}
bool Insert(Shunxubiao& L1, int i, Dataelem x)
{
	if (i < -1 || i > L1.n - 1 || L1.n == L1.maxlength) {
		return false;
	}
	else {
		for (int j = L1.n;j > i + 1;j--) {
			L1.dataelem[j] = L1.dataelem[j - 1];
		}
		L1.dataelem[i + 1] = x;
		L1.n += 1;
		return true;
	}
}
bool Delete(Shunxubiao& L1,int i)
{
	if (i < 0 || i > L1.n - 1) {
		return false;
	}
	else {
		for (int j = i;j < L1.n - 1;j++) {
			L1.dataelem[j] = L1.dataelem[j + 1];
		}
		L1.n -= 1;
		return true;
	}
}
bool Update(Shunxubiao& L1, int i, Dataelem x)
{
	if (i < 0 || i > L1.n - 1) {
		return false;
	}
	else {
		L1.dataelem[i] = x;
		return true;
	}
}
int main()
{
	return 0;
}