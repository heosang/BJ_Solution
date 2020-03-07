#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
void func();
int n;
int aryN[1001] = { 0, };
int sum[1001] = { 0, };
int ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryN[i]);
	}
	sort(aryN + 1, aryN + n + 1);
	for (int i = 1;i <= n;i++) {
		sum[i] += aryN[i]+sum[i-1];
	}
	for (int i = 1;i <= n;i++) {
		ans += sum[i];
	}

	printf("%d", ans);
	return 0;
}
