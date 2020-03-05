#include<iostream>
using namespace std;
long long int countAry(int);
int main() {
	long long int n, nA[101] = { 0, }, ans[101] = { 0, };
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> nA[i];
	}
	for (int j = 1;j <= n;j++) {
		ans[j]=countAry(nA[j]);
		cout << ans[j]<<endl;
	}
	return 0;
}
long long int countAry(int n) {
	long long int i, j, f1 = 1, f2 = 1, f3 = 1, f4 = 2, f5 = 2, f6 = 3, f = 0;
	if (n == 1)return 1;
	if (n == 2)return 1;
	if (n == 3)return 1;
	if (n == 4)return 2;
	if (n == 5)return 2;
	if (n == 6)return 3;
	for (i = 7;i <= n;i++) {
		f = f6 + f2;
		f2 = f3;
		f3 = f4;
		f4 = f5;
		f5 = f6;
		f6 = f;
	}
	return f;
}
