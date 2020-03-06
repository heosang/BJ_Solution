#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>

using namespace std;
long long int n, m;
long long int aryN[1000001] = { 0, };
long long int ans = 0;

void func() {
	long long int start = 0;
	long long int last = aryN[n];
	long long int mid = (start + last) / 2;
	long long int tempN;//임시 합
	while (start <= last) {
		tempN = 0;
		for (int i = 1;i <= n;i++) {
			if (aryN[i] - mid <= 0) { ; }
			else { tempN += aryN[i] - mid; }
		}
		if (tempN < m) {
			last = mid - 1;
			mid = (start + last) / 2;
		}
		else {
			if (ans < mid) {
				ans = mid;
			}
			start = mid + 1;
			mid = (start + last) / 2;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryN[i]);
	}
	sort(aryN + 1, aryN + 1 + n);
	func();
	printf("%d\n", ans);
	return 0;
}