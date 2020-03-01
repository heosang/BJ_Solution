#include<iostream>
#include<queue>
#include<algorithm>
#include<deque>

using namespace std;

deque <int> que;
queue <int> pos;
int func() {
	int total = 0;
	while (pos.size()) {
		int tempF = 0, tempB = 0;
		for (int i = 0;i < que.size();i++) {
			if (que.front() == pos.front()) {
				tempF = i;
			}
			que.push_back(que.front());
			que.pop_front();
		}
		for (int i = 0;i < que.size();i++) {
			if (que.front() == pos.front()) {
				tempB = i;
				if (tempF <= tempB) {
					total += tempF;
				}
				else {
					total += tempB;
				}
				pos.pop();
				que.pop_front();
				break;
			}
			else {
				que.push_front(que.back());
				que.pop_back();
			}
		}
	}
	return total;
}
int main() {
	int n, m;// 큐의 크기,뽑아내려고 하는 수의 개수
	int temp;
	int ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		que.push_back(i);
	}
	for (int i = 0;i < m;i++) {
		cin >> temp;
		pos.push(temp);
	}
	ans = func();
	cout << ans;
	return 0;
}