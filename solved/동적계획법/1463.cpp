#include<iostream>
using namespace std;
int n, ans[1000001] = { 0, };
void func();
int main() {
	cin >> n;
	func();
	cout << ans[n];
	return 0;	
}
void func() {
	int i, j, k;
	ans[1] = 0;
	for (int i = 2; i <= n; i++) {
		ans[i] = ans[i - 1] + 1;
		if (i % 2 == 0 && ans[i] > ans[i / 2] + 1) {
			ans[i] = ans[i / 2] + 1;
		}
		if (i % 3 == 0 && ans[i] > ans[i / 3] + 1) {
			ans[i] = ans[i / 3] + 1;
		}
	}
	return;
}