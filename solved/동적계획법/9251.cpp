#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[1001][1001] = { 0, };
string a, b;
void func();
int main() {
	
	cin >> a>>b;
	func();
	cout << dp[a.size()][b.size()];
	return 0;
}
void func() {
	int i, j;
	for (i = 1;i <= a.size();i++) {
		for (j = 1;j <= b.size();j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return;
}