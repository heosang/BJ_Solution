#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[1000][1000];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
void dfs(int,int);
int tomaNum = 0;
string temp;
int m,n;
int ans=0;
int main() {
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n ; j++) {
			cin>>map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				tomaNum++;
			}
		}
	}
	dfs(0, 0);
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n; j++) {
			if( map[i][j]==0){
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}
void dfs(int x,int y) {
	while (!q.empty()) {
		int cnt=0;
		for (int i = 0;i < tomaNum;i++) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < m && 0 <= ny && ny < n && map[nx][ny] == 0) {
					map[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					cnt++;
				}
			}
		}
		tomaNum = cnt;
		if (cnt)ans++;
	}
	return;
}