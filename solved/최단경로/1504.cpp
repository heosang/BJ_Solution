#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
void bfs(int);
vector<pair<int, int>>vec[801];
queue<pair<pair<int, int>,int>> q;
int sum[200001];
bool check[2] = { 0, };
int n, e;
int v1, v2;
int main(){
	int start;
	int a, b, c;
	cin >> n >> e;
	for (int i = 1;i <= e;i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	for (int i = 1;i <= n;i++) {
		sum[i] = INF;
	}
	bfs(1);
	int StoV1 = sum[v1];
	int StoV2 = sum[v2];
	for (int i = 1;i <= n;i++) {
		sum[i] = INF;
	}
	bfs(v1);
	int V1toV2 = sum[v2];
	int V1toN = sum[n];
	for (int i = 1;i <= n;i++) {
		sum[i] = INF;
	}
	bfs(v2);
	int V2toV1 = sum[v1];
	int V2toN = sum[n];
	if (StoV1 == INF || V1toV2 == INF || V2toN == INF || StoV2 == INF || V2toV1 == INF || V1toN == INF) {
		cout << "-1";
		return 0;
	}
	int ans = min(StoV1 + V1toV2 + V2toN, StoV2 + V2toV1 + V1toN);
	cout << ans;
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