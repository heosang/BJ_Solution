#include<iostream>
using namespace std;
int main() {
	long long int n, f_1 = 1, f_2 = 0, f, temp;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 2;i <= n;i++) {
		f = f_1 + f_2;
		f_2 = f_1;
		f_1 = f;
	}
	cout << f;
	return 0;

}
