#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue <int, vector<int>, greater<int>> que;
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
				ans.push(que.top());
				que.pop();
			}
		}
		else {
			que.push(temp);
		}
	}
	while (ans.size()) {
		cout << ans.front() << "\n";
		ans.pop();
	}
	return 0;
}

