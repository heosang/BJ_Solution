#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>

using namespace std;

long long int n, k, temp;
int aryN[10001] = { 0, };
long long int ans = 0;
void func() {
	long long int start, last, mid;
	int tempN=0;	
	start = 1;
	last = aryN[k];
	mid = (start + last) / 2;
	while (start<=last) {
		tempN = 0;
		for (int i = 1;i <= k;i++) {
			tempN += aryN[i] / mid;
		}
		if (tempN < n) {
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
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &aryN[i]);
	}
	sort(aryN + 1, aryN + 1 + k);
	func();
	printf("%d\n", ans);
	return 0;
}