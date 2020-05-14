#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[100][100][100];
int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };
queue<pair<pair<int, int>, int>> q;
void dfs(int,int,int);
int tomaNum = 0;
string temp;
int m,n,h;
int ans=0;
int main() {
	cin >> m >> n >> h;
	for (int k = 0;k < h;k++) {
		for (int i = 0;i < n ; i++) {
			for (int j = 0 ; j < m ; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push(make_pair(make_pair(i, j),k));
					tomaNum++;
				}
			}
			
		}
	}
	dfs(0, 0, 0);
	for (int k = 0;k < h;k++) {
		for (int i = 0;i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
void dfs(int x,int y , int z) {
	while (!q.empty()) {
		int cnt=0;
		for (int i = 0;i < tomaNum;i++) {
			x = q.front().first.first;
			y = q.front().first.second;
			z = q.front().second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && map[nx][ny][nz] == 0) {
					map[nx][ny][nz] = 1;
					q.push(make_pair(make_pair(nx, ny),nz));
					cnt++;
				}
			}
		}
		tomaNum = cnt;
		if (cnt)ans++;
	}
	return;
}