#include <iostream>​
#include <algorithm>
#include<vector>
using namespace std;
void func();
int n;//물품의 수
int k;//버틸 수 있는 무게
int ary[101][100001] = { 0, };
int w[101] = { 0, };
int v[101] = { 0, };
int main() {
	cin >> n>>k;
	for (int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];		
	}
	func();
	cout << ary[n][k] << "\n";
	return 0;
}
void func() {
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= k;j++) {
			if (j -  w[i]>= 0) {
				ary[i][j] = max(ary[i - 1][j], v[i] + ary[i - 1][j - w[i]]);
			}
			else {
				ary[i][j] = ary[i - 1][j];
			}
			
		}
	}
	return;
}