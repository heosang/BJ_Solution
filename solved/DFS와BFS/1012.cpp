#include <iostream>
#include <algorithm>
using namespace std;
int adj[50][50];
void dfs(int,int);
string temp;
int m,n,k;
int cnt;
int main() {
	int testCase;
	int a, b;
	cin >> testCase;
	for (int t = 0;t < testCase;t++) {
		cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				adj[i][j] = 0;
			}
		}
		for (int i = 0;i < k;i++) {
			cin >> a>>b;
			adj[a][b] = 1;
		}

		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (adj[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
void dfs(int i,int j) {
	if (i < 0 || i >=  m|| j < 0 || j >= n) {
		return;
	}
	if (adj[i][j] == 1)  {
		adj[i][j] = 0;
		dfs(i - 1, j);
		dfs(i, j - 1);
		dfs(i + 1, j);
		dfs(i, j + 1);
	}
	return;
}