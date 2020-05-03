#include <iostream>
#include <vector>
#include<utility>
#include <algorithm>
int cnt=0;
using namespace std;
vector <pair<int, int>> ans;
bool ary[101] = { 0, };
int main() {
	int comNum, pairNum;
	int comA, comB;
	cin >> comNum;
	cin >> pairNum;
	for (int i = 0;i < pairNum;i++) {
		cin >> comA >> comB;
		if (comA < comB) {
			ans.push_back(make_pair(comA, comB));
		}
		else {
			ans.push_back(make_pair(comB, comA));
		}
	}
	sort(ans.begin(), ans.end());
	ary[1] = true;
	if (ans[0].first != 1) {
		cout << "0";
		return 0;
	}
	else {
		ary[ans[0].second] = true;
		cnt++;
	}
	for (int i = 1;i < pairNum;i++) {
		if (ary[ans[i].first] == true&& ary[ans[i].second] == false) {
			cnt++;
			ary[ans[i].second] == true;
		}
	}
	cout << cnt;
	return 0;
}