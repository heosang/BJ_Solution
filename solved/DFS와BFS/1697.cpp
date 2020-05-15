#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
void bfs(int, int);
bool visit[100001] = { 0, };
int n, m;
int ans = 0;
int main(){
	cin >> n >> m;
	bfs(n, m);
	cout << ans;
	return 0;
}
void bfs(int n,int m) {
	queue<int> q;
	q.push(n);
	while (1) {
		int size = q.size();
		for (int i = 0;i < size;i++) {
			n = q.front();
			q.pop(); 
			if (n == m) {
				return;
			}
			if (n > 0 && visit[n - 1] == 0) {
				visit[n - 1] = 1;
				q.push(n - 1);
			}
			if (n < 100000 && visit[n + 1] == 0) {
				q.push(n + 1);
				visit[n + 1] = 1;
			}
			if (n * 2 <= 100000 && visit[n * 2] == 0) {
				q.push(n * 2);
				visit[n * 2] = 1;
			}
		}
		ans++;
	}
}