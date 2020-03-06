#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
#include<vector>
using namespace std;
void func();
void pick(int, int);

int ans = 1000000000;
int n;
int tempA = 0, tempB = 0;
int aryN[21][21] = { 0, };
bool team[21] = { 0, };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &aryN[i][j]);
		}
	}
	pick(1, 0);
	printf("%d", ans/2);
	return 0;
}
void func() {
	tempA = 0;
	tempB = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (team[i] == true && team[j] == true) {
				tempA += aryN[i][j] + aryN[j][i];
			}
			if (team[i] == false && team[j] == false) {
				tempB += aryN[i][j] + aryN[j][i];
			}
		}
	}
	if (tempA > tempB) {
		ans = min(ans, tempA - tempB);
	}
	else
	{
		ans = min(ans, tempB - tempA);
	}

	return;
}
void pick(int num, int cnt) {
	if (cnt == n/2) { 
		func();
		return;
	}
	if (num > n) { return; }
	for (int i = num;i <= n;i++) {
		team[i] = true;
		pick(i + 1, cnt+1);
		team[i] = false;
	}
	return;
}