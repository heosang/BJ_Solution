#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1002] = { 0, }; //dp수열
int func(int);
int main() {
	int n, i, ans1;
	cin >> n;
	for (i = 1;i <= n;i++) {
		cin >> dp[i];
	}
	ans1 = func(n);
	cout << ans1;
	return 0;
}
int func(int n) {
	int i, j;
	int*temp;
	vector <int>ans;
	ans.push_back(-987654321);
	for (i = 1;i <= n;i++) {
		if (dp[i] > ans.back()) {
			ans.push_back(dp[i]);
		}
		else {
			auto temp = lower_bound(ans.begin(), ans.end(), dp[i]);
			*temp = dp[i];
		}
	}
	return(ans.size() - 1);
}