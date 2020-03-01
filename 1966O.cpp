#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

queue <pair<int, int>> que;
int func(int m, int topImpt) {
	int count = 0;//프린트한 문서 수
	while (!que.empty()) {
		if (que.front().second == topImpt) {
			count++;
			if (que.front().first == m) {
				break;
			}
			que.pop();
			topImpt = 0;
			for (int i = 0;i < que.size();i++) {
				topImpt = max(topImpt, que.front().second);
				que.push(que.front());
				que.pop();
			}
		}
		else {
			que.push(que.front());
			que.pop();
		}
	}
	return count;
}
int main() {
	int testNum;//testcase 수
	int n;//문서의 수
	int m;//문서의 위치
	int impt;//문서의 중요도
	int topImpt = 0;// 중요도 가장 높은 수
	int temp;
	queue <int> ans;
	cin >> testNum;
	while (testNum--) {
		topImpt = 0;
		cin >> n >> m;
		for (int i = 0;i < n;i++) {
			cin >> impt;
			que.push(make_pair(i, impt));
			topImpt = max(topImpt, impt);
		}
		temp = func(m, topImpt);
		cout << temp << endl;
		while (que.size()) {
			que.pop();
		}
	}
	return 0;
}