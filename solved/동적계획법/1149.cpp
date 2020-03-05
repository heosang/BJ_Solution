#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>

using namespace std;
int aryN[3][1001] = { 0, };//정답
int rgb[3][1001] = { 0, };
int temp;

int main() {
	int n;//집의 수
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < 3;j++) {
			scanf("%d", &rgb[j][i]);
		}
	}
	aryN[0][1] = rgb[0][1];
	aryN[1][1] = rgb[1][1];
	aryN[2][1] = rgb[2][1];
	for (int i = 2;i <= n;i++) {
		for (int j = 0;j < 3;j++) {
			if (j == 0) {
				if (aryN[1][i - 1] > aryN[2][i - 1]) {
					aryN[j][i] = rgb[j][i] + aryN[2][i - 1];
				}
				else {
					aryN[j][i] = rgb[j][i] + aryN[1][i - 1];
				}
			}
			else if (j == 1) {
				if (aryN[0][i - 1] > aryN[2][i - 1]) {
					aryN[j][i] = rgb[j][i] + aryN[2][i - 1];
				}
				else {
					aryN[j][i] = rgb[j][i] + aryN[0][i - 1];
				}
			}
			else {
				if (aryN[0][i - 1] > aryN[1][i - 1]) {
					aryN[j][i] = rgb[j][i] + aryN[1][i - 1];
				}
				else {
					aryN[j][i] = rgb[j][i] + aryN[0][i - 1];
				}
			}
		}
	}
	int ans = aryN[0][n];
	if (ans >= aryN[1][n]) {
		ans = aryN[1][n];
	}
	if (ans >= aryN[2][n]) {
		ans = aryN[2][n];
	}
	printf("%d", ans);
	return 0;
}