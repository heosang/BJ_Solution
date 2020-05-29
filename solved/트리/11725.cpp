#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector <int>v[100000];
int ans[100001];
bool visit[100001] = { 0, };
int a, b;
int n, m;
void func(int,int  );
int main() {
	
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	func(1,1);
	for (int i = 2;i <= n;i++) {
		cout << ans[i]<<"\n";
	}
	return 0;
}
void func(int s,int par) {
	visit[s] = 1;
	ans[s] = par;
	for (int i = 0;i < v[s].size();i++) {
		int ns = v[s][i];
		if (!visit[ns]) {
			func(ns, s);
		}
	}
	return;
}