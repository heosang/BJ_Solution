#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
int ary[129][129] = { 0, };
void func(int, int, int, int,int);
int cntB = 0;
int cntW = 0;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%d", &ary[i][j]);
		}
	}
	func(1, n, 1, n, n);
	printf("%d\n%d", cntW,cntB);
	return 0;
}
void func(int xB, int xE, int yB, int yE,int n) {
	if (xB == xE) {
		if (ary[xB][yB] == 1) {
			cntB++;
		}
		else {
			cntW++;
		}
		return;
	}
	for (int i = xB;i <= xE;i++) {
		for (int j = yB;j <= yE;j++) {
			if (ary[i][j] != ary[xB][yB]) {
				func(xB+n/2, xE, yB, yE- n / 2,n/2);
				func(xB+n/2, xE, yB+ n / 2, yE, n / 2);
				func(xB, xE- n / 2, yB, yE- n / 2, n / 2);
				func(xB, xE- n / 2, yB+ n / 2, yE, n / 2);
				return;
			}
		}
	}
	if (ary[xB][yB] == 1) {
		cntB++;
	}
	else {
		cntW++;
	}
	return;
}