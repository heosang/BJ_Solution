#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
int ary[2188][2188] = { 0, };
void func(int, int, int, int, int);
int n;
int nm1 = 0;
int n1 = 0;
int n0 = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%d", &ary[i][j]);
		}
	}
	func(1, n, 1, n, n);
	printf("%d\n%d\n%d", nm1, n0, n1);
	return 0;
}
void func(int xB, int xE, int yB, int yE, int n) {
	if (xB == xE) {
		if (ary[xB][yB] == -1) {
			nm1++;
		}
		else if (ary[xB][yB] == 0) {
			n0++;
		}
		else {
			n1++;
		}
		return;
	}
	for (int i = xB;i <= xE;i++) {
		for (int j = yB;j <= yE;j++) {
			if (ary[i][j] != ary[xB][yB]) {
				func(xB + n / 3, xE - n / 3, yB, yE - 2 * n / 3, n / 3);
				func(xB + n / 3, xE - n / 3, yB + n / 3, yE - n / 3, n / 3);
				func(xB + n / 3, xE - n / 3, yB + 2 * n / 3, yE, n / 3);
				func(xB + 2 * n / 3, xE, yB, yE - 2 * n / 3, n / 3);
				func(xB + 2 * n / 3, xE, yB + n / 3, yE - n / 3, n / 3);
				func(xB + 2 * n / 3, xE, yB + 2 * n / 3, yE, n / 3);
				func(xB, xE - 2 * n / 3, yB, yE - 2 * n / 3, n / 3);
				func(xB, xE - 2 * n / 3, yB + n / 3, yE - n / 3, n / 3);
				func(xB, xE - 2 * n / 3, yB + 2 * n / 3, yE, n / 3);
				return;
			}
		}
	}
	if (ary[xB][yB] == -1) {
		nm1++;
	}
	else if (ary[xB][yB] == 0) {
		n0++;
	}
	else {
		n1++;
	}
	return;
}