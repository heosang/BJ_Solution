#include<iostream>
using namespace std;
int a[41];
int main() {
	long long int m,n, f1_0 = 0,f2_0=1, f2_1 = 0,f1_1=1,f_0=0,f_1=0;
	cin >> n;
	for (int j = 1;j <= n;j++) {
		cin >> a[j];
		
	}
	for (int j = 1;j <= n;j++) {
		f1_0 = 0, f2_0 = 1, f2_1 = 0, f1_1 = 1, f_0 = 0, f_1 = 0;
		if (a[j] == 0) {
			cout << "1 0" << endl;
			continue;
		}
		else if (a[j] == 1) {
			cout << "0 1" << endl;
			continue;
		}

		else {
			for (int k = 2;k <= a[j];k++) {
				f_0 = f1_0 + f2_0;
				f2_0 = f1_0;
				f1_0 = f_0;
				f_1 = f1_1 + f2_1;
				f2_1 = f1_1;
				f1_1 = f_1;
			}
			cout << f_0 << " " << f_1 << endl;
		}
	}
	return 0;
}
