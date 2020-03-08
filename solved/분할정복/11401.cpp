#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
int func(int);
long long int n, k;
long long int ans;
long long int x = 1,y=1;
int p = 1000000007;

int main() {
	scanf("%lld %lld", &n, &k);
	for(int i = n;i > n-k;i--) {
		x = x * i % p;
	}
	for (int i = 1;i <= k;i++) {
		y = y * i % p;
	}
	long long int y2 = func(p - 2);
	printf("%lld", y2 * x % p);
	return 0;
}int func(int t) {
	if (t == 0) {
		return 1;
	}
	long long int temp = func(t / 2);
	ans = temp * temp % p;
	if (t % 2 == 1) {
		ans = ans * y % p;
	}
	return ans;
}