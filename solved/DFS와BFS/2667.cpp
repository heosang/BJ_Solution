#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
int adj[25][25];
void dfs(int,int);
vector<int> ans;
string temp;
int n;
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		for(int j=0;j<n;j++){
			adj[i][j] = temp[j] - '0';
		}
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (adj[i][j]==1) {
				ans.push_back(0);
				dfs(i,j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size()<<"\n";
	for (int i = 0;i < ans.size();i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
void dfs(int i,int j) {
	if (i < 0 || i >= n || j < 0 || j >= n) {
		return;
	}
	if (adj[i][j] == 1)  {
		adj[i][j] = 0;
		++ans[ans.size()-1];
		dfs(i - 1, j);
		dfs(i, j - 1);
		dfs(i + 1, j);
		dfs(i, j + 1);
	}
	return;
}