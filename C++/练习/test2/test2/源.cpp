//#include"all.h"
//int main()
//{
//	all a1(7, 8);
//	print(a1);
//	while (1) {}
//	return 0;
//}
#include<iostream>
using namespace std;
const int N = 4;
const int M = 3;
const int P = 2;
void Multi(int(*a)[N], int(*b)[M], int(*c)[P]) {
	int i, j, k;
	for (i = 0; i<N; i++) {
		for (j = 0; j<P; j++) {
			c[i][j] = 0;
			for (k = 0; k<M; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			cout << c[i][j] << " = ";
		}
		cout << endl;
	}
}
void main() {
	int i, j;
	int A[4][4], B[3][3], C[4][2];
	for (i = 0; i<4; i++)
		for (j = 0; j<3; j++)
			cin >> A[i][j];
	for (i = 0; i<3; i++)
		for (j = 0; j<2; j++)
			cin >> B[i][j];
	cout << "C[4][2]=" << endl;
	Multi(A, B, C);

}

