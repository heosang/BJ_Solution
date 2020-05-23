#include<iostream>
#include <algorithm>

#define INF 1987654321;
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int T, k, i;

int main() {
	cin >> T;
	while (T--) {
		cin >> k;
		for (i = 1; i <= k; ++i) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int d = 1; d < k; ++d) {
			for (int tx = 1; tx + d <= k; ++tx) {
				int ty = tx + d;
				dp[tx][ty] = INF;

				for (int mid = tx; mid < ty; ++mid)
					dp[tx][ty] =
					min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
			}
		}

		cout << dp[1][k] << endl;
	}
	return 0;
}
