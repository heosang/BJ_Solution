#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	char ary[100];
	cin >> n;
	for (int i = 0;i < n;i++) {
		ary[i] =' ';
	}
	for (int i = 0;i < n;i++) {
		ary[i] = '*';
		for (int j = n-1;j >=0 ;j--) {
			cout << ary[j];
		}
		cout << "\n";
	}
	return 0;
}
