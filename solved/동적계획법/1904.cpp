#include<iostream>
using namespace std;
int countAry(int);
int main() {
	long long int n,ans;
	cin >> n;
	ans = countAry(n);
	cout << ans;
	return 0;
}
int countAry(int n) {
	long long int i,j,f,f1=2,f2=1;
	if (n == 1)return 1;
	if (n == 2)return 2;
	for (i =3;i <= n;i++) {
		f = f1 + f2;
		f %= 15746;
		f2 = f1;
		f1 = f;
		
	}
	return f;
}
