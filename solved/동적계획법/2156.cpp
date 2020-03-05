#include<iostream>
#include<algorithm>
using namespace std;
int ans[10001] = { 0, }; //양의 합+연속횟수
int aryN[10001] = { 0, };//각 잔의 양 
void func(int);
int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> aryN[i];
	}
	func(n);
    cout<<ans[n];
	return 0;
}
void func(int n) {
	int i, j;
	ans[1] = aryN[1];
    ans[2]=aryN[2]+ans[1];
	for (i = 3;i <= n;i++) {
		ans[i]=max(aryN[i]+ans[i-2],max(aryN[i]+aryN[i-1]+ans[i-3],ans[i-1]));
	}
	return;
}