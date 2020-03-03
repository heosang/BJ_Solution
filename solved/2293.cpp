#include <cstdio>​

int main() {
	int n, k;
	int ary[101];
	int ans[10001] = { 0, };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	ans[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= ary[i]) {
				ans[j] += ans[j - ary[i]];
			}
		}
	}
	printf("%d\n", ans[k]);
	return 0;
}