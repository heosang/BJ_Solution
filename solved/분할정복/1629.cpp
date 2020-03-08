#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
int func(int);
long long int a, b, c;
long long int ans;

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	ans=func(b);
	printf("%lld", ans);
	return 0;
}int func(int b) {
	if (b == 0) {
		return 1;
	}
	long long int temp = func(b / 2);
	ans = temp * temp % c;
	if (b % 2 == 1) {
		ans = ans * a % c;
	}
	return ans;
}