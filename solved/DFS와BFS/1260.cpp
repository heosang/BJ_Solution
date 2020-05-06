#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int adj[1001][1001];
queue <int> q;
void dfs(int);
void bfs(int);
bool visit[1001] = { 0 ,};
int n, m, v;
int main() {
	cin >> n >> m >> v;
	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		adj[a][b]=1;
		adj[b][a]=1;
	}
	dfs(v);
	for (int i = 1;i <= n;i++) {
		visit[i] = false;
	}
	cout << "\n";
	bfs(v);
}
void dfs(int v) {
	visit[v] = true;
	cout << v << " ";
	for (int i = 1;i <= n;i++) {
		if (adj[v][i] == 1 && visit[i] == false) {
			visit[i] = true;
			dfs(i);
		}
	}
	return;
}
void bfs(int v) {
	q.push(v);
	visit[v] = true;
	while (1) {
		if (q.empty()) {
			break;
		}
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 1;i <= n;i++) {
			if (adj[temp][i] == 1 && visit[i] == false) {
				visit[i] = true;
				q.push(i);
			}
		}
	}
	return;
}