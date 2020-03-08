#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
void func(long long int);
int n;
long long int b;
long long int ary[6][6] = { 0, };
long long int ans[6][6];
long long int tAns[6][6];

int main() {
	long long int t1;
	scanf("%d %lld", &n, &b);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%lld", &t1);
			ary[i][j] = t1;
		}
	}
	func(b);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void func(long long int t) {	
	if (t == 1) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				ans[i][j] = ary[i][j]%1000;
			}
		}
		return ;
	}
	func(t / 2);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			tAns[i][j] = 0;
			for (int x = 1;x <= n;x++) {
				tAns[i][j]+= ans[i][x] * ans[x][j];
			}
			tAns[i][j] %= 1000;			
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			ans[i][j] = tAns[i][j];
		}
	}
	if (t % 2 == 1) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				tAns[i][j] = 0;
				for (int x = 1;x <= n;x++) {
					tAns[i][j] += ans[i][x] * ary[x][j];
				}
				tAns[i][j] %= 1000;
			}
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				ans[i][j] = tAns[i][j];
			}
		}
	}
	return ;
}