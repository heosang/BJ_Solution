#include<iostream>
using namespace std;
int dp[1002] = { 0, }, ans[1002] = { 0, };
void func(int);
int main() {
	int temp, n, i;
	cin >> n;
	temp = 0;
	for (i = 1;i <= n;i++) {
		cin >> dp[i];
	}
	func(n);
	for (i = 1;i <= n;i++) {
		if (temp < ans[i])temp = ans[i];
	}
	cout << temp;
	return 0;
}
void func(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 0;j < i;j++) {
			if (dp[i] > dp[j] && ans[i] <= ans[j]) ans[i] = ans[j] + 1;
		}
	}
	return;
}