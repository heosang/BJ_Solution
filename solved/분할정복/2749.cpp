#include <iostream>
using namespace std;
int main() {
	long long int n;
	int ary[1500001];
	ary[1] = 1;
	ary[0] = 0;
	cin >> n;
	n %= 1500000;
	for (int i = 2;i <= n;i++) {
		ary[i] = (ary[i - 2] + ary[i - 1]) % 1000000;
	}
	cout << ary[n];
	return 0;
}