#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1987654321
using namespace std;
void bfs(int);
vector<pair<int, int>>vec[2001];
queue<pair<pair<int, int>,int>> q;
int sum[2001];
int realSum[2001];
int n, m, t;
int s, h, g;
int a, b, d;
int x[101];
int ansG[101];
int ansH[101];
int main() {
	int T;
	cin >> T;
	for (int k = 0;k < T;k++) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 1;i <= m;i++) {
			cin >> a >> b >> d;
			vec[a].push_back(make_pair(b, d));
			vec[b].push_back(make_pair(a, d));
		}
		for (int i = 1;i <= t;i++) {
			cin >> x[i];
		}

		sort(x + 1, x + t + 1);
		for (int i = 1;i <= n;i++) {
			sum[i] = INF;
		}
		bfs(s);
		for (int i = 1;i <= n;i++) {
			realSum[i] = sum[i];
		}
		int StoG = sum[g];
		int StoH = sum[h];
		for (int i = 1;i <= n;i++) {
			sum[i] = INF;
		}
		bfs(g);
		int GtoH = sum[h];
		for (int i = 1;i <= t;i++) {
			ansG[i] = sum[x[i]];
		}
		for (int i = 1;i <= n;i++) {
			sum[i] = INF;
		}
		bfs(h);
		int HtoG = sum[g];
		for (int i = 1;i <= t;i++) {
			ansH[i] = sum[x[i]];
		}
		for (int i = 1;i <= t;i++) {
			if (realSum[x[i]] == StoG + GtoH + ansH[i] || realSum[x[i]] == StoH + HtoG + ansG[i]) {
				cout << x[i] << " ";
			}
		}
		cout << "\n";
		for (int i = 1;i <= n;i++) {
			sum[i] = INF;
		}
		for (int i = 1;i <= n;i++) {
			vec[i].clear();
		}
		
	}
	return 0;
}
void bfs(int start) {
	sum[start] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (sum[cur] < weight)continue;
		for (int i = 0;i < vec[cur].size();i++) {
			int next = vec[cur][i].first;
			int nextW = weight + vec[cur][i].second;
			if (nextW < sum[next]) {
				sum[next] = nextW;
				pq.push(make_pair(nextW, next));
			}
		}
	}
	return;
}