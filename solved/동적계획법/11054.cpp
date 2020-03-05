#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
void func();

int n;
int aryN[1001] = { 0, };
int ans[2][1001] = { 0, };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryN[i]);
	}
	func();
	int temp = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < 2;j++) {
			temp = max(temp, ans[j][i]);
		}
	}
	printf("%d", temp);
	return 0;
}
void func() {
	ans[1][1] = 1;
	ans[0][1] = 1;
	for (int i = 2;i <= n;i++) {
		int temp = 1;
		ans[1][i] = 1;
		ans[0][i] = 1;
		for (int j = 1;j < i;j++) {
			if (aryN[j] < aryN[i]) {
				ans[1][i] = max(ans[1][i],ans[1][j] + 1);
			}
			if (aryN[j] > aryN[i]) {
				ans[0][i] = max(ans[0][i], max(ans[1][j] + 1, ans[0][j]+1));
			}
		}
	}
	return;
}