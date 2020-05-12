#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[100][100];
int sum[100][100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs(int,int);
string temp;
int m,n;
int ans=987654321;
int main() {
	int testCase;
	int a, b;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		for (int j = 0;j < m ; j++) {
			map[i][j] = temp[j] - '0';
			sum[i][j] = 0;
		}
	}
	sum[0][0] = 1;
	dfs(0, 0);
	cout << sum[n-1][m-1] << "\n";
	return 0;
}
void dfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (sum[nx][ny] == 0 && map[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					sum[nx][ny] = sum[x][y] + 1;
				}
				else if (sum[nx][ny] == 0)
					sum[nx][ny] = -1;
			}
		}
	}

}