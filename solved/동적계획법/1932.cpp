#include<iostream>
using namespace std;
int n, path[501][501] = { 0, }, cost[501][501] = { 0, }, ans = 0;
void maxCost(int);
int main() {
	int ans=0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			cin >> path[i][j];
		}
	}
	maxCost(1);
	for (int k = 1;k <= n;k++) {
		if (cost[n][k] > ans)ans = cost[n][k];
	}
	cout << ans;
	return 0;
}
void maxCost(int depth) {
	int i, j, k,temp;
	cost[1][1] = path[1][1];
	for (i = 2;i <= n;i++) {
		for (j = 1;j < i;j++) {
			temp = cost[i - 1][j] + path[i][j];
			if (temp > cost[i][j])cost[i][j] = temp;
			temp = cost[i - 1][j] + path[i][j + 1];
			if (temp > cost[i][j+1])cost[i][j+1] = temp;
		}
	}
	return;
}