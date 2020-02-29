#include<iostream>
#include<queue>
#include<vector>

using namespace std;
queue <int> que, ans;

void func(int k) {
	int temp;
	while (que.size() > 0) {
		for (int i = 1;i < k;i++) {
			temp = que.front();
			que.pop();
			que.push(temp);
		}
		temp = que.front();
		que.pop();
		ans.push(temp);
	}
	return;
}
int main() {
	int n;//사람수
	int k;//k번째 사람제거
	std::cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		que.push(i);
	}
	func(k);
	cout << "<" << ans.front();
	ans.pop();
	while (ans.size() > 0) {
		cout << ", " << ans.front();
		ans.pop();
	}
	cout << ">";
	return 0;
}