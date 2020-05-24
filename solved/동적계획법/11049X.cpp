#include<iostream>
#include <algorithm>

#define INF 1987654321;
using namespace std;

int dp[501][501];
int ary[501][2];
int N;
int ans = 0;

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> ary[i][0] >> ary[i][1];
	}
	for (int i = 1; i <= N; i++) {
		dp[i][i + 1] = ary[i][0] * ary[i][1] * ary[i + 1][1];
	}
	for (int m = 2;m <= N;m++) {
		for (int i = 1;i <= N-m;i++) {
			int j = i + m;
			for (int k = i;k < j;k++) {
				int res = dp[i][k] + dp[k + 1][j] + ary[i][0] * ary[k][1] * ary[j][1];
				if (!dp[i][j] || dp[i][j] > res) dp[i][j] = res;
			}
		}
	}
	return 0;
}
