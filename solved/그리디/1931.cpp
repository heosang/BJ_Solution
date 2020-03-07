#pragma warning(disable:4996)
#include <cstdio>​
#include<vector>
#include <algorithm>
using namespace std;
void func();
void func();
vector<pair<int, int >> vecN;
using namespace std;
int n;
int ans = 0;

int main() {
	int t1, t2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t1, &t2);
		vecN.push_back(make_pair(t2, t1));
	}
	sort(vecN.begin(), vecN.end());
	func();
	printf("%d", ans);
	return 0;
}
void func() {
	int temp = 0;
	int tStart = vecN[0].first;
	ans++;
	for (int i = 1;i < n;i++) {
		if (vecN[i].second >= tStart) {
			tStart = vecN[i].first;
			ans++;
		}
	}


	return;
}