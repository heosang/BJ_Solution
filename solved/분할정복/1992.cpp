#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
#include<iostream>
using namespace std;
char ary[65][65] = { 0, };
void func(int, int, int, int, int);
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n;j++) {
			cin >> ary[i][j];
		}
	}
	func(1, n, 1, n, n);
	return 0;
}
void func(int xB, int xE, int yB, int yE, int n) {
	if (xB == xE) {
		printf("%c", ary[xB][yB]);
		return;
	}
	for (int i = xB;i <= xE;i++) {
		for (int j = yB;j <= yE;j++) {
			if (ary[i][j] != ary[xB][yB]) {
				printf("(");
				func(xB, xE - n / 2, yB, yE - n / 2, n / 2);
				func(xB, xE - n / 2, yB + n / 2, yE, n / 2);
				func(xB + n / 2, xE, yB, yE - n / 2, n / 2);			
				func(xB + n / 2, xE, yB + n / 2, yE, n / 2);			
				printf(")");
				return;
			}
		}
	}
	printf("%c", ary[xB][yB]);
	return;
}