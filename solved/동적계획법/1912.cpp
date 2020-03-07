#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
void func();

int n;
int aryN[100001] = { 0, };
int ans[100001] = { 0, };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryN[i]);
	}
	func();
	int temp = ans[1];
	for (int i = 2;i <= n;i++) {
		temp = max(temp, ans[i]);
	}
	printf("%d", temp);
	return 0;
}
void func() {
	ans[1] = aryN[1];
	for (int i = 2;i <= n;i++) {
		ans[i] = max(aryN[i], ans[i - 1] + aryN[i]);
		
	}
	return;
}