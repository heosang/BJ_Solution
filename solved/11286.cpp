#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
queue <int> ans;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);


	int n;
	int temp;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		if (temp == 0) {
			if (que.size() == 0) {
				ans.push(0);
			}
			else {
				if (que.top().second == 0) {
					ans.push(-que.top().first);
				}
				else {
					ans.push(que.top().first);
				}
				que.pop();
			}
		}
		else if (temp < 0) {
			que.push(make_pair(-temp, 0));
		}
		else {
			que.push(make_pair(temp, 1));
		}

	}
	while (ans.size()) {
		cout << ans.front() << "\n";
		ans.pop();
	}
	return 0;
}

