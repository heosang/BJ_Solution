#include <iostream>
#include <algorithm>
#include <queue>
#include<string>
using namespace std;
void bfs();
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<pair<int, int>, pair<int, int>>> q;
int map[1000][1000] = { 0, };
int visit[1000][1000][2];
int n, m;
int ans = 1;
int main(){
	string temp;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		for (int j = 0;j < m;j++) {
			map[i][j] = temp[j] - '0';
		}
	}
	bfs();
	cout << ans;
	return 0;
}
void bfs() {
	visit[0][0][0] = 1;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			ans = cnt;
			return;
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
				if (!wall && map[nx][ny] == 1) {
					visit[nx][ny][wall + 1] = 1;
					q.push(make_pair(make_pair(nx, ny), make_pair(wall + 1, cnt + 1)));
				}
				else if (map[nx][ny] == 0 && !visit[nx][ny][wall]) {
					visit[nx][ny][wall] = 1;
					q.push(make_pair(make_pair(nx, ny), make_pair(wall, cnt + 1)));
				}
			}
		}
	}
	ans = -1;
	return;
}