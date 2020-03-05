#include<iostream>
#include<algorithm>
using namespace std;
int ans[3][10001] = { 0, }; //양의 합+연속횟수
int aryN[10001] = { 0, };//각 잔의 양 
void func(int);
int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> aryN[i];
	}
	func(n);
	if (ans[2][n] >= ans[1][n]&&ans[2][n]>=ans[2][n-1]) {
		cout << ans[2][n];
	}
	else if(ans[1][n] >= ans[2][n] && ans[1][n] >= ans[2][n - 1]){

		cout << ans[1][n];
	}
	else {
		cout << ans[2][n - 1];
	}
	return 0;
}
void func(int n) {
	int i, j;
	ans[1][1] = aryN[1];
	for (i = 2;i <= n;i++) {
		ans[2][i] = ans[1][i - 1] + aryN[i];
		if (ans[1][i - 2] >= ans[2][i - 2]) {
			ans[1][i] = ans[1][i - 2] + aryN[i];
		}
		else {
			ans[1][i] = ans[2][i - 2] + aryN[i];
		}
	}
	return;
}