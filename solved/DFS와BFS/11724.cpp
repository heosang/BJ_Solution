#include <iostream>
#include <algorithm>
using namespace std;
int adj[1001][1001];
void dfs(int);
bool visit[1001] = { 0 , };
int n, m, v;
int cnt = 0;
int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	for(int i=1;i<=n;i++) {
		if (visit[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
void dfs(int v) {
	visit[v] = true;
	for (int i = 1;i <= n;i++) {
		if (adj[v][i] == 1 && visit[i] == false) {
			dfs(i);
		}
	}
	return;
}