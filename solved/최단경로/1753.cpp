#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
void bfs(int);
vector<pair<int, int>>vec[300001];
queue<pair<pair<int, int>,int>> q;
int sum[20001];
int v, e;
int main(){
	int start;
	int a, b, c;
	cin >> v >> e;
	cin >> start;
	for (int i = 1;i <= e;i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}
	for (int i = 1;i <= v;i++) {
		sum[i] = 987654321;
	}
	sum[start] = 0;
	bfs(start);
	for (int i = 1;i <= v;i++) {
		if (sum[i] == 987654321) {
			cout << "INF\n";
		}
		else {
			cout << sum[i] << "\n";
		}
	}
	return 0;
}
void bfs(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if (sum[cur] < weight)continue;
		for (int i = 0;i < vec[cur].size();i++) {
			int next = vec[cur][i].first;
			int nextW = weight + vec[cur][i].second;
			if (nextW < sum[next]) {
				sum[next] = nextW;
				pq.push(make_pair(-nextW, next));
			}
		}
	}
	return;
}