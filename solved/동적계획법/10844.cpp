#include<iostream>
#include<cmath>
using namespace std;
long long int n, dp[101][10] = { 0, }, ans[101] = { 0, };
void func();
int main() {
	cin >> n;
	func();
	cout << ans[n];
	return 0;
}
void func() {
	int i, j, k;
	for (i = 1;i < 10;i++) {
		dp[1][i] = 1;
	}
	ans[1] = 9;
	for (i = 2;i<=n;i++) {
		for (j = 0;j < 10;j++) {
			if (j > 0) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			if (j < 9) {
				dp[i][j] += dp[i - 1][j + 1];
			}
			dp[i][j] %= 1000000000;
		}
		for(k = 0;k < 10;k++) {
			ans[i] += dp[i][k];
		}
		ans[i] %= 1000000000;
	}
	return;
}