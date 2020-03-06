#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
#include <vector>
#include<utility>
using namespace std;
void func();

int n;
vector <pair<int, int>> vecN;//A위치 B위치
int ans = 0;

int main() {
	int tempA, tempB;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &tempA, &tempB);
		vecN.push_back(make_pair(tempA, tempB));
	}
	sort(vecN.begin(), vecN.end());
	func();
	printf("%d", ans);
	return 0;
}
void func() {
	while (true) {
		int pos = 0;//가장많이 겹치는 선의 A위치 순서
		int topTemp = 0;//가장많이 겹치는 횟수
		for (int i = 0;i < vecN.size();i++) {
			int temp = 0;//각 겹치는 횟수
			for (int j = 0;j < vecN.size();j++) {
				if (vecN[i].first > vecN[j].first&& vecN[i].second < vecN[j].second) {
					temp++;
				}
				if (vecN[i].first < vecN[j].first && vecN[i].second > vecN[j].second) {
					temp++;
				}
			}
			if (temp > topTemp) {
				topTemp = temp;
				pos = i;
			}
		}
		if (topTemp == 0) {
			break;
		}
		vecN.erase(vecN.begin() + pos);
		ans++;
	}
	return;
}